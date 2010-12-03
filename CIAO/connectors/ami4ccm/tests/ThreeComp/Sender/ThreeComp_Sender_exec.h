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
#ifndef CIAO_THREECOMP_SENDER_EXEC_GBRV83_H_
#define CIAO_THREECOMP_SENDER_EXEC_GBRV83_H_

#include /**/ "ace/pre.h"

#include "ThreeComp_SenderEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "ThreeComp_Sender_exec_export.h"
#include "tao/LocalObject.h"
#include "ace/Task.h"

namespace CIAO_ThreeComp_Sender_Impl
{
  typedef ACE_Atomic_Op <TAO_SYNCH_MUTEX, CORBA::UShort > Atomic_UShort;

  /// Worker thread for asynchronous invocations
   class asynch_foo_generator : public virtual ACE_Task_Base
   {
   public:
     asynch_foo_generator (::ThreeComp::CCM_Sender_Context_ptr context,
         Atomic_UShort  &nr_of_rec,
         Atomic_UShort  &nr_of_sent);

     virtual int svc (void);

   private:
     ::ThreeComp::CCM_Sender_Context_var context_;
      Atomic_UShort  &nr_of_rec_;
      Atomic_UShort  &nr_of_sent_;
   };

   /// Worker thread for synchronous invocations
   class synch_foo_generator : public virtual ACE_Task_Base
   {
   public:
     synch_foo_generator (::ThreeComp::CCM_Sender_Context_ptr context,
         Atomic_UShort  &nr_of_rec);
     virtual int svc (void);

   private:
     ::ThreeComp::CCM_Sender_Context_var context_;
     Atomic_UShort  &nr_of_rec_;
    };
  /**
   * Provider Executor Implementation Class: do_my_state_exec_i
   */

  class do_my_state_exec_i
    : public virtual ::ThreeComp::CCM_State,
      public virtual ::CORBA::LocalObject
  {
  public:
    do_my_state_exec_i (
      ::ThreeComp::CCM_Sender_Context_ptr ctx);
    virtual ~do_my_state_exec_i (void);

    //@{
    /** Operations and attributes from ::ThreeComp::State. */

    virtual
    ::CORBA::Long bar (::CORBA::Long cmd,
    ::CORBA::String_out answer);
    //@}

  private:
    ::ThreeComp::CCM_Sender_Context_var ciao_context_;
  };

  /**
   * Provider Executor Implementation Class: do_my_bar_exec_i
   */

  class do_my_bar_exec_i
    : public virtual ::ThreeComp::CCM_MyBar,
      public virtual ::CORBA::LocalObject
  {
  public:
    do_my_bar_exec_i (
      ::ThreeComp::CCM_Sender_Context_ptr ctx);
    virtual ~do_my_bar_exec_i (void);

    //@{
    /** Operations and attributes from ::ThreeComp::MyBar. */

    virtual
    ::CORBA::Long testbar (::CORBA::Long cmd,
    ::CORBA::String_out answer);
    //@}

  private:
    ::ThreeComp::CCM_Sender_Context_var ciao_context_;
  };

  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  class Sender_exec_i
    : public virtual Sender_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Sender_exec_i (void);
    virtual ~Sender_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */

    virtual ::ThreeComp::CCM_State_ptr
    get_do_my_state (void);

    virtual ::ThreeComp::CCM_MyBar_ptr
    get_do_my_bar (void);
    //@}

    //@{
    /** Operations from Components::SessionComponent. */
    virtual void set_session_context (::Components::SessionContext_ptr ctx);
    virtual void configuration_complete (void);
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

    //@{
    /** User defined public operations. */
    //@}

  private:
    ::ThreeComp::CCM_Sender_Context_var ciao_context_;

    //@{
    /** Component attributes. */
    ::ThreeComp::CCM_State_var ciao_do_my_state_;
    ::ThreeComp::CCM_MyBar_var ciao_do_my_bar_;
    //@}

    //@{
    /** User defined members. */
    asynch_foo_generator* asynch_foo_gen;
    synch_foo_generator* synch_foo_gen;
    Atomic_UShort nr_of_rec_;
    Atomic_UShort nr_of_sent_;
    //@}

    //@{
    /** User defined private operations. */
    //@}
  };

  extern "C" THREECOMP_SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_ThreeComp_Sender_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */