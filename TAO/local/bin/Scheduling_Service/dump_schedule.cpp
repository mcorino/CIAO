//
// $Id$
//

#include "ace/Sched_Params.h"
#include "ace/Get_Opt.h"
#include "tao/corba.h"

#include "CosNamingC.h"
#include "Scheduler_Factory.h"

// This program dumps the results of one scheduling in a C++ file.



int main (int argc, char *argv[])
{
  ACE_TRY
    {
      // Initialize ORB.
      CORBA::ORB_ptr orb = 
	CORBA::ORB_init (argc, argv, "dump_schedule", ACE_TRY_ENV);
      ACE_CHECK_ENV;

      CORBA::POA_ptr poa =
	orb->POA_init(argc, argv, "POA");
      if (poa == 0)
	{
	  ACE_ERROR_RETURN ((LM_ERROR,
			     " (%P|%t) Unable to initialize the POA.\n"),
			    1);
	}

#if 0
      CORBA::Object_ptr objref =
	orb->resolve_initial_references ("NameService");
      ACE_CHECK_ENV;
      CosNaming::NamingContext_var naming_context = 
        CosNaming::NamingContext::_narrow (objref, ACE_TRY_ENV);
      ACE_CHECK_ENV;

      ACE_Scheduler_Factory::use_config (naming_context);
#else
      ACE_Scheduler_Factory::use_config (orb);
#endif /* 0 */

      RtecScheduler::RT_Info_Set* infos;
      ACE_Scheduler_Factory::server ()->compute_scheduling
	(ACE_Sched_Params::priority_min (ACE_SCHED_FIFO,
					 ACE_SCOPE_THREAD),
	 ACE_Sched_Params::priority_max (ACE_SCHED_FIFO,
					 ACE_SCOPE_THREAD),
	 infos, ACE_TRY_ENV);
      ACE_CHECK_ENV;

      ACE_Scheduler_Factory::dump_schedule (*infos,
					    "Scheduler_Runtime.cpp");
      delete infos;
    }
  ACE_CATCH (CORBA::SystemException, sys_ex)
    {
      ACE_TRY_ENV.print_exception ("SYS_EX");
    }
  ACE_ENDTRY;

  return 0;
}
