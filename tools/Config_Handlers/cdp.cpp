/* $Id$
 * This code was generated by the XML Schema Compiler.
 *
 * Changes made to this code will most likely be overwritten
 * when the handlers are recompiled.
 *
 * If you find errors or feel that there are bugfixes to be made,
 * please contact the current XSC maintainer:
 *             Will Otte <wotte@dre.vanderbilt.edu>
 */

// Fix for Borland compilers, which seem to have a broken
// <string> include.
#ifdef __BORLANDC__
# include <string.h>
#endif

#include "cdp.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    // DeploymentPlan
    // 

    DeploymentPlan::
    DeploymentPlan ()
    : 
    ::XSCRT::Type (), 
    regulator__ ()
    {
    }

    DeploymentPlan::
    DeploymentPlan (::CIAO::Config_Handlers::DeploymentPlan const& s)
    :
    ::XSCRT::Type (),
    label_ (s.label_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.label_) : 0),
    UUID_ (s.UUID_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.UUID_) : 0),
    realizes_ (s.realizes_.get () ? new ::CIAO::Config_Handlers::ComponentInterfaceDescription (*s.realizes_) : 0),
    regulator__ ()
    {
      if (label_.get ()) label_->container (this);
      if (UUID_.get ()) UUID_->container (this);
      if (realizes_.get ()) realizes_->container (this);
      {
        for (implementation_const_iterator i (s.implementation_.begin ());i != s.implementation_.end ();++i) add_implementation (*i);
      }

      {
        for (instance_const_iterator i (s.instance_.begin ());i != s.instance_.end ();++i) add_instance (*i);
      }

      {
        for (connection_const_iterator i (s.connection_.begin ());i != s.connection_.end ();++i) add_connection (*i);
      }

      {
        for (dependsOn_const_iterator i (s.dependsOn_.begin ());i != s.dependsOn_.end ();++i) add_dependsOn (*i);
      }

      {
        for (artifact_const_iterator i (s.artifact_.begin ());i != s.artifact_.end ();++i) add_artifact (*i);
      }

      {
        for (infoProperty_const_iterator i (s.infoProperty_.begin ());i != s.infoProperty_.end ();++i) add_infoProperty (*i);
      }
    }

    ::CIAO::Config_Handlers::DeploymentPlan& DeploymentPlan::
    operator= (::CIAO::Config_Handlers::DeploymentPlan const& s)
    {
      if (s.label_.get ()) label (*(s.label_));
      else label_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      if (s.UUID_.get ()) UUID (*(s.UUID_));
      else UUID_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (0);

      if (s.realizes_.get ()) realizes (*(s.realizes_));
      else realizes_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentInterfaceDescription > (0);

      implementation_.clear ();
      {
        for (implementation_const_iterator i (s.implementation_.begin ());i != s.implementation_.end ();++i) add_implementation (*i);
      }

      instance_.clear ();
      {
        for (instance_const_iterator i (s.instance_.begin ());i != s.instance_.end ();++i) add_instance (*i);
      }

      connection_.clear ();
      {
        for (connection_const_iterator i (s.connection_.begin ());i != s.connection_.end ();++i) add_connection (*i);
      }

      dependsOn_.clear ();
      {
        for (dependsOn_const_iterator i (s.dependsOn_.begin ());i != s.dependsOn_.end ();++i) add_dependsOn (*i);
      }

      artifact_.clear ();
      {
        for (artifact_const_iterator i (s.artifact_.begin ());i != s.artifact_.end ();++i) add_artifact (*i);
      }

      infoProperty_.clear ();
      {
        for (infoProperty_const_iterator i (s.infoProperty_.begin ());i != s.infoProperty_.end ();++i) add_infoProperty (*i);
      }

      return *this;
    }


    // DeploymentPlan
    // 
    bool DeploymentPlan::
    label_p () const
    {
      return label_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& DeploymentPlan::
    label () const
    {
      return *label_;
    }

    void DeploymentPlan::
    label (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (label_.get ())
      {
        *label_ = e;
      }

      else
      {
        label_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        label_->container (this);
      }
    }

    // DeploymentPlan
    // 
    bool DeploymentPlan::
    UUID_p () const
    {
      return UUID_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& DeploymentPlan::
    UUID () const
    {
      return *UUID_;
    }

    void DeploymentPlan::
    UUID (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (UUID_.get ())
      {
        *UUID_ = e;
      }

      else
      {
        UUID_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        UUID_->container (this);
      }
    }

    // DeploymentPlan
    // 
    bool DeploymentPlan::
    realizes_p () const
    {
      return realizes_.get () != 0;
    }

    ::CIAO::Config_Handlers::ComponentInterfaceDescription const& DeploymentPlan::
    realizes () const
    {
      return *realizes_;
    }

    void DeploymentPlan::
    realizes (::CIAO::Config_Handlers::ComponentInterfaceDescription const& e)
    {
      if (realizes_.get ())
      {
        *realizes_ = e;
      }

      else
      {
        realizes_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentInterfaceDescription > (new ::CIAO::Config_Handlers::ComponentInterfaceDescription (e));
        realizes_->container (this);
      }
    }

    // DeploymentPlan
    // 
    DeploymentPlan::implementation_iterator DeploymentPlan::
    begin_implementation ()
    {
      return implementation_.begin ();
    }

    DeploymentPlan::implementation_iterator DeploymentPlan::
    end_implementation ()
    {
      return implementation_.end ();
    }

    DeploymentPlan::implementation_const_iterator DeploymentPlan::
    begin_implementation () const
    {
      return implementation_.begin ();
    }

    DeploymentPlan::implementation_const_iterator DeploymentPlan::
    end_implementation () const
    {
      return implementation_.end ();
    }

    void DeploymentPlan::
    add_implementation (::CIAO::Config_Handlers::MonolithicDeploymentDescription const& e)
    {
      implementation_.push_back (e);
    }

    size_t DeploymentPlan::
    count_implementation(void) const
    {
      return implementation_.size ();
    }

    // DeploymentPlan
    // 
    DeploymentPlan::instance_iterator DeploymentPlan::
    begin_instance ()
    {
      return instance_.begin ();
    }

    DeploymentPlan::instance_iterator DeploymentPlan::
    end_instance ()
    {
      return instance_.end ();
    }

    DeploymentPlan::instance_const_iterator DeploymentPlan::
    begin_instance () const
    {
      return instance_.begin ();
    }

    DeploymentPlan::instance_const_iterator DeploymentPlan::
    end_instance () const
    {
      return instance_.end ();
    }

    void DeploymentPlan::
    add_instance (::CIAO::Config_Handlers::InstanceDeploymentDescription const& e)
    {
      instance_.push_back (e);
    }

    size_t DeploymentPlan::
    count_instance(void) const
    {
      return instance_.size ();
    }

    // DeploymentPlan
    // 
    DeploymentPlan::connection_iterator DeploymentPlan::
    begin_connection ()
    {
      return connection_.begin ();
    }

    DeploymentPlan::connection_iterator DeploymentPlan::
    end_connection ()
    {
      return connection_.end ();
    }

    DeploymentPlan::connection_const_iterator DeploymentPlan::
    begin_connection () const
    {
      return connection_.begin ();
    }

    DeploymentPlan::connection_const_iterator DeploymentPlan::
    end_connection () const
    {
      return connection_.end ();
    }

    void DeploymentPlan::
    add_connection (::CIAO::Config_Handlers::PlanConnectionDescription const& e)
    {
      connection_.push_back (e);
    }

    size_t DeploymentPlan::
    count_connection(void) const
    {
      return connection_.size ();
    }

    // DeploymentPlan
    // 
    DeploymentPlan::dependsOn_iterator DeploymentPlan::
    begin_dependsOn ()
    {
      return dependsOn_.begin ();
    }

    DeploymentPlan::dependsOn_iterator DeploymentPlan::
    end_dependsOn ()
    {
      return dependsOn_.end ();
    }

    DeploymentPlan::dependsOn_const_iterator DeploymentPlan::
    begin_dependsOn () const
    {
      return dependsOn_.begin ();
    }

    DeploymentPlan::dependsOn_const_iterator DeploymentPlan::
    end_dependsOn () const
    {
      return dependsOn_.end ();
    }

    void DeploymentPlan::
    add_dependsOn (::CIAO::Config_Handlers::ImplementationDependency const& e)
    {
      dependsOn_.push_back (e);
    }

    size_t DeploymentPlan::
    count_dependsOn(void) const
    {
      return dependsOn_.size ();
    }

    // DeploymentPlan
    // 
    DeploymentPlan::artifact_iterator DeploymentPlan::
    begin_artifact ()
    {
      return artifact_.begin ();
    }

    DeploymentPlan::artifact_iterator DeploymentPlan::
    end_artifact ()
    {
      return artifact_.end ();
    }

    DeploymentPlan::artifact_const_iterator DeploymentPlan::
    begin_artifact () const
    {
      return artifact_.begin ();
    }

    DeploymentPlan::artifact_const_iterator DeploymentPlan::
    end_artifact () const
    {
      return artifact_.end ();
    }

    void DeploymentPlan::
    add_artifact (::CIAO::Config_Handlers::ArtifactDeploymentDescription const& e)
    {
      artifact_.push_back (e);
    }

    size_t DeploymentPlan::
    count_artifact(void) const
    {
      return artifact_.size ();
    }

    // DeploymentPlan
    // 
    DeploymentPlan::infoProperty_iterator DeploymentPlan::
    begin_infoProperty ()
    {
      return infoProperty_.begin ();
    }

    DeploymentPlan::infoProperty_iterator DeploymentPlan::
    end_infoProperty ()
    {
      return infoProperty_.end ();
    }

    DeploymentPlan::infoProperty_const_iterator DeploymentPlan::
    begin_infoProperty () const
    {
      return infoProperty_.begin ();
    }

    DeploymentPlan::infoProperty_const_iterator DeploymentPlan::
    end_infoProperty () const
    {
      return infoProperty_.end ();
    }

    void DeploymentPlan::
    add_infoProperty (::CIAO::Config_Handlers::Property const& e)
    {
      infoProperty_.push_back (e);
    }

    size_t DeploymentPlan::
    count_infoProperty(void) const
    {
      return infoProperty_.size ();
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    // DeploymentPlan
    //

    DeploymentPlan::
    DeploymentPlan (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == ACE_TEXT ("label"))
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          label (t);
        }

        else if (n == ACE_TEXT ("UUID"))
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          UUID (t);
        }

        else if (n == ACE_TEXT ("realizes"))
        {
          ::CIAO::Config_Handlers::ComponentInterfaceDescription t (e);
          realizes (t);
        }

        else if (n == ACE_TEXT ("implementation"))
        {
          ::CIAO::Config_Handlers::MonolithicDeploymentDescription t (e);
          add_implementation (t);
        }

        else if (n == ACE_TEXT ("instance"))
        {
          ::CIAO::Config_Handlers::InstanceDeploymentDescription t (e);
          add_instance (t);
        }

        else if (n == ACE_TEXT ("connection"))
        {
          ::CIAO::Config_Handlers::PlanConnectionDescription t (e);
          add_connection (t);
        }

        else if (n == ACE_TEXT ("dependsOn"))
        {
          ::CIAO::Config_Handlers::ImplementationDependency t (e);
          add_dependsOn (t);
        }

        else if (n == ACE_TEXT ("artifact"))
        {
          ::CIAO::Config_Handlers::ArtifactDeploymentDescription t (e);
          add_artifact (t);
        }

        else if (n == ACE_TEXT ("infoProperty"))
        {
          ::CIAO::Config_Handlers::Property t (e);
          add_infoProperty (t);
        }

        else 
        {
        }
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

#include "XMLSchema/TypeInfo.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace
    {
      ::XMLSchema::TypeInfoInitializer < ACE_TCHAR > XMLSchemaTypeInfoInitializer_ (::XSCRT::extended_type_info_map ());

      struct DeploymentPlanTypeInfoInitializer
      {
        DeploymentPlanTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (DeploymentPlan));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      DeploymentPlanTypeInfoInitializer DeploymentPlanTypeInfoInitializer_;
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Traversal
    {
      // DeploymentPlan
      //
      //

      void DeploymentPlan::
      traverse (Type& o)
      {
        pre (o);
        if (o.label_p ()) label (o);
        else label_none (o);
        if (o.UUID_p ()) UUID (o);
        else UUID_none (o);
        if (o.realizes_p ()) realizes (o);
        else realizes_none (o);
        implementation (o);
        instance (o);
        connection (o);
        dependsOn (o);
        artifact (o);
        infoProperty (o);
        post (o);
      }

      void DeploymentPlan::
      traverse (Type const& o)
      {
        pre (o);
        if (o.label_p ()) label (o);
        else label_none (o);
        if (o.UUID_p ()) UUID (o);
        else UUID_none (o);
        if (o.realizes_p ()) realizes (o);
        else realizes_none (o);
        implementation (o);
        instance (o);
        connection (o);
        dependsOn (o);
        artifact (o);
        infoProperty (o);
        post (o);
      }

      void DeploymentPlan::
      pre (Type&)
      {
      }

      void DeploymentPlan::
      pre (Type const&)
      {
      }

      void DeploymentPlan::
      label (Type& o)
      {
        dispatch (o.label ());
      }

      void DeploymentPlan::
      label (Type const& o)
      {
        dispatch (o.label ());
      }

      void DeploymentPlan::
      label_none (Type&)
      {
      }

      void DeploymentPlan::
      label_none (Type const&)
      {
      }

      void DeploymentPlan::
      UUID (Type& o)
      {
        dispatch (o.UUID ());
      }

      void DeploymentPlan::
      UUID (Type const& o)
      {
        dispatch (o.UUID ());
      }

      void DeploymentPlan::
      UUID_none (Type&)
      {
      }

      void DeploymentPlan::
      UUID_none (Type const&)
      {
      }

      void DeploymentPlan::
      realizes (Type& o)
      {
        dispatch (o.realizes ());
      }

      void DeploymentPlan::
      realizes (Type const& o)
      {
        dispatch (o.realizes ());
      }

      void DeploymentPlan::
      realizes_none (Type&)
      {
      }

      void DeploymentPlan::
      realizes_none (Type const&)
      {
      }

      void DeploymentPlan::
      implementation (Type& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::implementation_iterator b (o.begin_implementation()), e (o.end_implementation());

        if (b != e)
        {
          implementation_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) implementation_next (o);
          }

          implementation_post (o);
        }
      }

      void DeploymentPlan::
      implementation (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::implementation_const_iterator b (o.begin_implementation()), e (o.end_implementation());

        if (b != e)
        {
          implementation_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) implementation_next (o);
          }

          implementation_post (o);
        }
      }

      void DeploymentPlan::
      implementation_pre (Type&)
      {
      }

      void DeploymentPlan::
      implementation_pre (Type const&)
      {
      }

      void DeploymentPlan::
      implementation_next (Type&)
      {
      }

      void DeploymentPlan::
      implementation_next (Type const&)
      {
      }

      void DeploymentPlan::
      implementation_post (Type&)
      {
      }

      void DeploymentPlan::
      implementation_post (Type const&)
      {
      }

      void DeploymentPlan::
      instance (Type& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::instance_iterator b (o.begin_instance()), e (o.end_instance());

        if (b != e)
        {
          instance_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) instance_next (o);
          }

          instance_post (o);
        }

        else instance_none (o);
      }

      void DeploymentPlan::
      instance (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::instance_const_iterator b (o.begin_instance()), e (o.end_instance());

        if (b != e)
        {
          instance_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) instance_next (o);
          }

          instance_post (o);
        }

        else instance_none (o);
      }

      void DeploymentPlan::
      instance_pre (Type&)
      {
      }

      void DeploymentPlan::
      instance_pre (Type const&)
      {
      }

      void DeploymentPlan::
      instance_next (Type&)
      {
      }

      void DeploymentPlan::
      instance_next (Type const&)
      {
      }

      void DeploymentPlan::
      instance_post (Type&)
      {
      }

      void DeploymentPlan::
      instance_post (Type const&)
      {
      }

      void DeploymentPlan::
      instance_none (Type&)
      {
      }

      void DeploymentPlan::
      instance_none (Type const&)
      {
      }

      void DeploymentPlan::
      connection (Type& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::connection_iterator b (o.begin_connection()), e (o.end_connection());

        if (b != e)
        {
          connection_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) connection_next (o);
          }

          connection_post (o);
        }

        else connection_none (o);
      }

      void DeploymentPlan::
      connection (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::connection_const_iterator b (o.begin_connection()), e (o.end_connection());

        if (b != e)
        {
          connection_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) connection_next (o);
          }

          connection_post (o);
        }

        else connection_none (o);
      }

      void DeploymentPlan::
      connection_pre (Type&)
      {
      }

      void DeploymentPlan::
      connection_pre (Type const&)
      {
      }

      void DeploymentPlan::
      connection_next (Type&)
      {
      }

      void DeploymentPlan::
      connection_next (Type const&)
      {
      }

      void DeploymentPlan::
      connection_post (Type&)
      {
      }

      void DeploymentPlan::
      connection_post (Type const&)
      {
      }

      void DeploymentPlan::
      connection_none (Type&)
      {
      }

      void DeploymentPlan::
      connection_none (Type const&)
      {
      }

      void DeploymentPlan::
      dependsOn (Type& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::dependsOn_iterator b (o.begin_dependsOn()), e (o.end_dependsOn());

        if (b != e)
        {
          dependsOn_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) dependsOn_next (o);
          }

          dependsOn_post (o);
        }

        else dependsOn_none (o);
      }

      void DeploymentPlan::
      dependsOn (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::dependsOn_const_iterator b (o.begin_dependsOn()), e (o.end_dependsOn());

        if (b != e)
        {
          dependsOn_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) dependsOn_next (o);
          }

          dependsOn_post (o);
        }

        else dependsOn_none (o);
      }

      void DeploymentPlan::
      dependsOn_pre (Type&)
      {
      }

      void DeploymentPlan::
      dependsOn_pre (Type const&)
      {
      }

      void DeploymentPlan::
      dependsOn_next (Type&)
      {
      }

      void DeploymentPlan::
      dependsOn_next (Type const&)
      {
      }

      void DeploymentPlan::
      dependsOn_post (Type&)
      {
      }

      void DeploymentPlan::
      dependsOn_post (Type const&)
      {
      }

      void DeploymentPlan::
      dependsOn_none (Type&)
      {
      }

      void DeploymentPlan::
      dependsOn_none (Type const&)
      {
      }

      void DeploymentPlan::
      artifact (Type& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::artifact_iterator b (o.begin_artifact()), e (o.end_artifact());

        if (b != e)
        {
          artifact_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) artifact_next (o);
          }

          artifact_post (o);
        }

        else artifact_none (o);
      }

      void DeploymentPlan::
      artifact (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::artifact_const_iterator b (o.begin_artifact()), e (o.end_artifact());

        if (b != e)
        {
          artifact_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) artifact_next (o);
          }

          artifact_post (o);
        }

        else artifact_none (o);
      }

      void DeploymentPlan::
      artifact_pre (Type&)
      {
      }

      void DeploymentPlan::
      artifact_pre (Type const&)
      {
      }

      void DeploymentPlan::
      artifact_next (Type&)
      {
      }

      void DeploymentPlan::
      artifact_next (Type const&)
      {
      }

      void DeploymentPlan::
      artifact_post (Type&)
      {
      }

      void DeploymentPlan::
      artifact_post (Type const&)
      {
      }

      void DeploymentPlan::
      artifact_none (Type&)
      {
      }

      void DeploymentPlan::
      artifact_none (Type const&)
      {
      }

      void DeploymentPlan::
      infoProperty (Type& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::infoProperty_iterator b (o.begin_infoProperty()), e (o.end_infoProperty());

        if (b != e)
        {
          infoProperty_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) infoProperty_next (o);
          }

          infoProperty_post (o);
        }

        else infoProperty_none (o);
      }

      void DeploymentPlan::
      infoProperty (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::infoProperty_const_iterator b (o.begin_infoProperty()), e (o.end_infoProperty());

        if (b != e)
        {
          infoProperty_pre (o);
          for (; b != e;)
          {
            dispatch (*b);
            if (++b != e) infoProperty_next (o);
          }

          infoProperty_post (o);
        }

        else infoProperty_none (o);
      }

      void DeploymentPlan::
      infoProperty_pre (Type&)
      {
      }

      void DeploymentPlan::
      infoProperty_pre (Type const&)
      {
      }

      void DeploymentPlan::
      infoProperty_next (Type&)
      {
      }

      void DeploymentPlan::
      infoProperty_next (Type const&)
      {
      }

      void DeploymentPlan::
      infoProperty_post (Type&)
      {
      }

      void DeploymentPlan::
      infoProperty_post (Type const&)
      {
      }

      void DeploymentPlan::
      infoProperty_none (Type&)
      {
      }

      void DeploymentPlan::
      infoProperty_none (Type const&)
      {
      }

      void DeploymentPlan::
      post (Type&)
      {
      }

      void DeploymentPlan::
      post (Type const&)
      {
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Writer
    {
      // DeploymentPlan
      //
      //

      DeploymentPlan::
      DeploymentPlan (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      DeploymentPlan::
      DeploymentPlan ()
      {
      }

      void DeploymentPlan::
      traverse (Type const& o)
      {
        Traversal::DeploymentPlan::traverse (o);
      }

      void DeploymentPlan::
      label (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("label"), top_ ()));
        Traversal::DeploymentPlan::label (o);
        pop_ ();
      }

      void DeploymentPlan::
      UUID (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("UUID"), top_ ()));
        Traversal::DeploymentPlan::UUID (o);
        pop_ ();
      }

      void DeploymentPlan::
      realizes (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("realizes"), top_ ()));
        Traversal::DeploymentPlan::realizes (o);
        pop_ ();
      }

      void DeploymentPlan::
      implementation_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("implementation"), top_ ()));
      }

      void DeploymentPlan::
      implementation_next (Type const& o)
      {
        implementation_post (o);
        implementation_pre (o);
      }

      void DeploymentPlan::
      implementation_post (Type const&)
      {
        pop_ ();
      }

      void DeploymentPlan::
      instance_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("instance"), top_ ()));
      }

      void DeploymentPlan::
      instance_next (Type const& o)
      {
        instance_post (o);
        instance_pre (o);
      }

      void DeploymentPlan::
      instance_post (Type const&)
      {
        pop_ ();
      }

      void DeploymentPlan::
      connection_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("connection"), top_ ()));
      }

      void DeploymentPlan::
      connection_next (Type const& o)
      {
        connection_post (o);
        connection_pre (o);
      }

      void DeploymentPlan::
      connection_post (Type const&)
      {
        pop_ ();
      }

      void DeploymentPlan::
      dependsOn_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("dependsOn"), top_ ()));
      }

      void DeploymentPlan::
      dependsOn_next (Type const& o)
      {
        dependsOn_post (o);
        dependsOn_pre (o);
      }

      void DeploymentPlan::
      dependsOn_post (Type const&)
      {
        pop_ ();
      }

      void DeploymentPlan::
      artifact_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("artifact"), top_ ()));
      }

      void DeploymentPlan::
      artifact_next (Type const& o)
      {
        artifact_post (o);
        artifact_pre (o);
      }

      void DeploymentPlan::
      artifact_post (Type const&)
      {
        pop_ ();
      }

      void DeploymentPlan::
      infoProperty_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("infoProperty"), top_ ()));
      }

      void DeploymentPlan::
      infoProperty_next (Type const& o)
      {
        infoProperty_post (o);
        infoProperty_pre (o);
      }

      void DeploymentPlan::
      infoProperty_post (Type const&)
      {
        pop_ ();
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

