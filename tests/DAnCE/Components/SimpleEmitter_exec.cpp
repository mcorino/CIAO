#include "SimpleEmitter_exec.h"
#include "ace/Log_Msg.h"

namespace CIAO_Simple_SimpleEmitter_Impl
{
  //==================================================================
  // Component Executor Implementation Class:   SimpleEmitter_exec_i
  //==================================================================

  SimpleEmitter_exec_i::SimpleEmitter_exec_i (void)
  {
    ACE_TRACE ("SimpleEmitter_exec_i::SimpleEmitter_exec_i (void)");
  }

  SimpleEmitter_exec_i::~SimpleEmitter_exec_i (void)
  {
    ACE_TRACE ("SimpleEmitter_exec_i::~SimpleEmitter_exec_i (void)");
  }

  // Supported or inherited operations.

  // Attribute operations.

  // Port operations.

  // Operations from Components::SessionComponent

  void
  SimpleEmitter_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    ACE_TRACE ("SimpleEmitter_exec_i::set_session_context ()");
    this->context_ =
      ::Simple::CCM_SimpleEmitter_Context::_narrow (ctx);

    if (CORBA::is_nil (this->context_.in ()))
    {
      throw ::CORBA::INTERNAL ();
    }
  }

  void
  SimpleEmitter_exec_i::configuration_complete ()
  {
    ACE_TRACE ("SimpleEmitter_exec_i::configuration_complete ()");
    // Your code here.
  }

  void
  SimpleEmitter_exec_i::ccm_activate ()
  {
    ACE_TRACE ("SimpleEmitter_exec_i::ccm_activate ()");
    // Your code here.
#if !defined (CCM_NOEVENT)
    ::Simple::Hello_var hello = new OBV_Simple::Hello ("Test successful, hello from SimpleEmitter_exec_i");

    this->context_->push_hello_emits (hello.in ());
#endif
  }

  void
  SimpleEmitter_exec_i::ccm_passivate ()
  {
    ACE_TRACE ("SimpleEmitter_exec_i::ccm_passivate ()");
    // Your code here.
  }

  void
  SimpleEmitter_exec_i::ccm_remove ()
  {
    ACE_TRACE ("SimpleEmitter_exec_i::ccm_remove ()");
    // Your code here.
  }

  //==================================================================
  // Home Executor Implementation Class:   SimpleEmitterHome_exec_i
  //==================================================================

  SimpleEmitterHome_exec_i::SimpleEmitterHome_exec_i (void)
  {
    ACE_TRACE ("SimpleEmitterHome_exec_i::SimpleEmitterHome_exec_i (void)");
  }

  SimpleEmitterHome_exec_i::~SimpleEmitterHome_exec_i (void)
  {
    ACE_TRACE ("SimpleEmitterHome_exec_i::~SimpleEmitterHome_exec_i (void)");
  }

  // Supported or inherited operations.

  // Home operations.

  // Factory and finder operations.

  // Attribute operations.

  // Implicit operations.

  ::Components::EnterpriseComponent_ptr
  SimpleEmitterHome_exec_i::create ()
  {
    ACE_TRACE ("SimpleEmitterHome_exec_i::create ()");

    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_THROW_EX (
      retval,
      SimpleEmitter_exec_i,
      ::CORBA::NO_MEMORY ());

    return retval;
  }

  extern "C" SIMPLEEMITTER_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Simple_SimpleEmitterHome_Impl (void)
  {
    ACE_TRACE ("create_Simple_SimpleEmitterHome_Impl (void)");
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();

    ACE_NEW_RETURN (
      retval,
      SimpleEmitterHome_exec_i,
      ::Components::HomeExecutorBase::_nil ());

    return retval;
  }
}

