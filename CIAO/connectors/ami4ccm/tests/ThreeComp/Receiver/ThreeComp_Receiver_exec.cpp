// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.3
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

#include "ThreeComp_Receiver_exec.h"
#include "ace/OS_NS_unistd.h"

namespace CIAO_ThreeComp_Receiver_Impl
{

  /**
   * Facet Executor Implementation Class: do_my_foo_exec_i
   */

  do_my_foo_exec_i::do_my_foo_exec_i (
        ::ThreeComp::CCM_Receiver_Context_ptr ctx,
         Atomic_UShort &nr_of_received)
    : ciao_context_ (
        ::ThreeComp::CCM_Receiver_Context::_duplicate (ctx)),
         nr_of_received_(nr_of_received)
  {
  }

  do_my_foo_exec_i::~do_my_foo_exec_i (void)
  {
  }

  // Operations from ::ThreeComp::MyFoo

  ::CORBA::Long
  do_my_foo_exec_i::foo (::CORBA::Long cmd,
  ::CORBA::String_out answer)
  {
    ACE_OS::sleep(2);
     CORBA::Long ret = 0;
     ++nr_of_received_;
     if (cmd == 10)
       {
         ret = 1;
       }
     if (cmd == 20)
       {
         ret = 2;
       }
     answer = CORBA::string_dup ("Hi from receiver.");
     return ret;  }

  /**
   * Component Executor Implementation Class: Receiver_exec_i
   */

  Receiver_exec_i::Receiver_exec_i (void)
  :nr_of_received_(0)
  {
  }

  Receiver_exec_i::~Receiver_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes and port operations.

  ::ThreeComp::CCM_MyFoo_ptr
  Receiver_exec_i::get_do_my_foo (void)
  {
    if ( ::CORBA::is_nil (this->ciao_do_my_foo_.in ()))
      {
        do_my_foo_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          do_my_foo_exec_i (
            this->ciao_context_.in (),
            this->nr_of_received_),
            ::ThreeComp::CCM_MyFoo::_nil ());

          this->ciao_do_my_foo_ = tmp;
      }

    return
      ::ThreeComp::CCM_MyFoo::_duplicate (
        this->ciao_do_my_foo_.in ());
  }

  // Operations from Components::SessionComponent.

  void
  Receiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::ThreeComp::CCM_Receiver_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Receiver_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_remove (void)
  {
  // each Receiver has to receive 2 requests.
    if (nr_of_received_.value() != 2)
      {
        ACE_ERROR ((LM_ERROR,
                   "ERROR: Receiver received wrong number of messages"
                   " ( %u/2)!\n",
                   nr_of_received_.value() ));
      }
    else
      {
        ACE_DEBUG ((LM_DEBUG, "OK: This Receiver works as expected.\n"));
      }
  }

  extern "C" THREECOMP_RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_ThreeComp_Receiver_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Receiver_exec_i);

    return retval;
  }
}
