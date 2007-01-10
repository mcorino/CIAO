//
// $Id$
//

#include "Client_Task.h"

ACE_RCSID(Bug_1XXX_Regression, Client_Task, "$Id$")

Client_Task::Client_Task (Test::Hello_ptr receiver,
                          CORBA::ORB_ptr orb,
                          ACE_Thread_Manager *thr_mgr)
  : ACE_Task_Base (thr_mgr)
  , receiver_ (Test::Hello::_duplicate (receiver))
  , handler_ (new Reply_Handler(receiver, orb))
  , handler_var_ (handler_->_this())
  , orb_ (CORBA::ORB::_duplicate (orb))
{
}

Client_Task::~Client_Task (void)
{
}

int
Client_Task::svc (void)
{
  //  ACE_DEBUG ((LM_DEBUG, "(%P|%t) Starting client task\n"));

  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      CORBA::Object_var object =
        this->orb_->resolve_initial_references ("PolicyCurrent");

      CORBA::PolicyCurrent_var policy_current =
        CORBA::PolicyCurrent::_narrow (object.in ());

      TimeBase::TimeT timeout_period = 20 * 1000;

      CORBA::Any timeout_as_any;
      timeout_as_any <<= timeout_period;

      CORBA::PolicyList policy_list (1);
      policy_list.length (1);
      policy_list[0] =
        this->orb_->create_policy (Messaging::RELATIVE_RT_TIMEOUT_POLICY_TYPE,
                                   timeout_as_any);

      policy_current->set_policy_overrides (policy_list,
                                            CORBA::ADD_OVERRIDE);

      policy_list[0]->destroy();

      // Start 25 separate concurrent request streams
      for (CORBA::Short i = 0; i != 25; ++i)
      {
        this->receiver_->sendc_short_sleep (this->handler_var_.in ()
            ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;
      }

      ACE_Time_Value tv(10, 0);
      orb_->run(tv ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCH (CORBA::TIMEOUT, ex)
    {
      // A CORBA::TIMEOUT exception is expected since
      // the server aborts itself
      ACE_UNUSED_ARG (ex);
      ACE_DEBUG ((LM_DEBUG,
                  "Client received an expected CORBA::TIMEOUT exception.\n"));
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "(%P|%t) Client_Task - caught exception:");
      return -1;
    }
  ACE_ENDTRY;

  return 0;
}
