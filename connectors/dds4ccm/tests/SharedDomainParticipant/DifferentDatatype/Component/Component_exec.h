// -*- C++ -*-
#ifndef CIAO_COMPONENT_EXEC_H_
#define CIAO_COMPONENT_EXEC_H_


#include "ComponentEC.h"

#include /**/ "Component_exec_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"

class DDSDomainParticipant;

namespace CIAO_SharedDP_SharedDPComponent_Impl
{
  class Component_exec_i
    : public virtual SharedDPComponent_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Component_exec_i (void);
    virtual ~Component_exec_i (void);

    virtual void set_session_context (::Components::SessionContext_ptr ctx);

    virtual void configuration_complete (void);

    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);

  private:
    ::SharedDP::CCM_SharedDPComponent_Context_var context_;

    ::DDS::InstanceHandle_t dp1_hnd_;
    ::DDS::InstanceHandle_t dp2_hnd_;
    ::DDS::InstanceHandle_t dp3_hnd_;
    ::DDS::DomainParticipant_ptr dp1_ptr_;
    ::DDS::DomainParticipant_ptr dp2_ptr_;
    ::DDS::DomainParticipant_ptr dp3_ptr_;
  };

  extern "C" COMPONENT_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Component_Impl (void);
}

#endif /* ifndef */

