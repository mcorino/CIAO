// -*- C++ -*-
// $Id$

#include "ace/Env_Value_T.h"
#include "tao/ORB_Core.h"
#include "dds4ccm/impl/Utils.h"
#include "dds4ccm/impl/logger/Log_Macros.h"

#include "dds4ccm/impl/TopicListener.h"
#include "dds4ccm/impl/PublisherListener.h"
#include "dds4ccm/impl/SubscriberListener.h"

#if (CIAO_DDS4CCM_NDDS==1)
# include "dds4ccm/impl/ndds/TypeSupport.h"
# include "dds4ccm/impl/ndds/DomainParticipant.h"
#endif

template <typename CCM_TYPE>
DDS_Base_Connector_T<CCM_TYPE>::DDS_Base_Connector_T (void)
  : domain_id_ (0)
  , configuration_complete_ (false)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE>::DDS_Base_Connector_T");

  ACE_Env_Value<int> id (ACE_TEXT("DDS4CCM_DEFAULT_DOMAIN_ID"), this->domain_id_);
  this->domain_id_ = id;
  this->dlf_ =
    ACE_Dynamic_Service<CIAO::DDS4CCM::Logger_Service>::instance ("DDS4CCM_Logger");
  if (this->dlf_)
    {
      this->dlf_->init ();
    }
}

template <typename CCM_TYPE>
DDS_Base_Connector_T<CCM_TYPE>::~DDS_Base_Connector_T (void)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE>::~DDS_Base_Connector_T");

  DDS4CCM_DEBUG (DDS4CCM_LOG_LEVEL_ACTION, (LM_TRACE, DDS4CCM_INFO
                "DDS_Base_Connector_T::~DDS_Base_Connector_T - "
                "Connector has been destructed\n"));
}

template <typename CCM_TYPE>
::DDS::DomainId_t
DDS_Base_Connector_T<CCM_TYPE>::domain_id (void)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE>::domain_id");

  return this->domain_id_;
}

template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::domain_id (
  ::DDS::DomainId_t domain_id)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE>::domain_id");

  if (this->configuration_complete_)
    {
      throw ::CCM_DDS::NonChangeable ();
    }
  else
    {
      this->domain_id_ = domain_id;
    }
}

template <typename CCM_TYPE>
char *
DDS_Base_Connector_T<CCM_TYPE>::qos_profile (void)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE>::qos_profile");

  return CORBA::string_dup (this->qos_profile_.in ());
}

template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::qos_profile (
  const char * qos_profile)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE>::qos_profile");

  if (this->configuration_complete_)
    {
      throw ::CCM_DDS::NonChangeable ();
    }
  else
    {
      this->qos_profile_ = ::CORBA::string_dup (qos_profile);
    }
}

template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::init_domain (
  ::DDS::DomainParticipant_ptr & participant)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE>::init_domain");

  DDS4CCM_DEBUG (DDS4CCM_LOG_LEVEL_ACTION_STARTING, (LM_TRACE, DDS4CCM_INFO
                "DDS_Base_Connector_T::init_domain - "
                "Start configuring default domain <%d>\n",
                this->domain_id_));

#if (CIAO_DDS4CCM_NDDS==1)
  if (!::CORBA::is_nil (this->qos_profile_.in ()))
    {
      this->participant_factory_.set_default_participant_qos_with_profile (
                                      this->qos_profile_.in ());

      participant = this->participant_factory_.create_participant_with_profile (
                                      this->domain_id_,
                                      this->qos_profile_.in (),
                                      ::DDS::DomainParticipantListener::_nil (),
                                      0);
    }
  else
#else
        ACE_UNUSED_ARG (this->qos_profile_);
#endif
    {
      ::DDS::DomainParticipantQos qos;
      participant = this->participant_factory_.create_participant (
                                      this->domain_id_,
                                      qos,
                                      ::DDS::DomainParticipantListener::_nil (),
                                      0);
    }

  if (::CORBA::is_nil (participant))
    {
      DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                  "DDS_Base_Connector_T::init_domain - "
                  "Error: Unable to create DomainParticipant for domain <%d>\n",
                  this->domain_id_));
      throw ::CCM_DDS::InternalError (::DDS::RETCODE_ERROR, 0);
    }
}

template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::set_session_context (
  ::Components::SessionContext_ptr ctx)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE>::set_session_context");

  typename CCM_TYPE::context_type::_var_type lctx =
    CCM_TYPE::context_type::_narrow (ctx);

  if (::CORBA::is_nil (lctx.in ()))
    {
      throw ::CORBA::INTERNAL ();
    }

  this->context_ = lctx;
}

template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::configuration_complete (void)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE>::configuration_complete");
  this->init_domain (this->domain_participant_.inout ());
  this->configuration_complete_ = true;
}

template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::ccm_activate (void)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE>::ccm_activate");
}

template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::ccm_passivate (void)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE>::ccm_passivate");
}

template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::ccm_remove (void)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE>::ccm_remove");

  ::DDS::DomainParticipant_var dp = this->domain_participant_._retn ();
  if (!::CORBA::is_nil (dp.in ()))
    {
      this->remove_domain (dp.in ());
    }
}

template <typename CCM_TYPE>
ACE_Reactor*
DDS_Base_Connector_T<CCM_TYPE>::reactor (void)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE>::reactor");

  ACE_Reactor* reactor = 0;

#if (CIAO_DDS4CCM_CONTEXT_SWITCH == 1)
  ::CORBA::Object_var ccm_object = this->context_->get_CCM_object();
  if (!::CORBA::is_nil (ccm_object.in ()))
    {
      ::CORBA::ORB_var orb = ccm_object->_get_orb ();
      if (!::CORBA::is_nil (orb.in ()))
        {
          reactor = orb->orb_core ()->reactor ();
          if (!reactor)
            {
              DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                            "DDS_Event_Connector_T::ccm_activate - "
                            "No reactor to perform required context switch.\n"));
              throw ::CORBA::INTERNAL ();
            }
        }
    }
#endif
  return reactor;
}

/**
  * Initialization
 **/
template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::init_topic (
  ::DDS::DomainParticipant_ptr participant,
  ::DDS::Topic_ptr & topic,
  const char * topic_name,
  const char * typesupport_name)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::init_topic");

  ::DDS::Topic_var tp;
#if (CIAO_DDS4CCM_NDDS==1)
  if (!::CORBA::is_nil (this->qos_profile_.in ()))
    {
      tp = participant->create_topic_with_profile (topic_name,
                                          typesupport_name,
                                          this->qos_profile_.in (),
                                          ::DDS::TopicListener::_nil (),
                                          0);
    }
  else
#endif
    {
      ::DDS::TopicQos tqos;
      tp = participant->create_topic (topic_name,
                             typesupport_name,
                             tqos,
                             ::DDS::TopicListener::_nil (),
                             0);
    }
  if (::CORBA::is_nil (tp))
    {
      DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_DDS_NIL_RETURN, (LM_ERROR, DDS4CCM_INFO
                    "DDS_Base_Connector_T::init_topic - "
                    "Error: Proxy returned a nil topic\n"));
      throw ::CCM_DDS::InternalError (::DDS::RETCODE_ERROR, 0);
    }
  topic = tp._retn ();
}

template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::init_publisher (
  ::DDS::DomainParticipant_ptr participant,
  ::DDS::Publisher_ptr & publisher)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::init_publisher");

  if (::CORBA::is_nil (publisher))
    {
#if (CIAO_DDS4CCM_NDDS==1)
      if (!::CORBA::is_nil (this->qos_profile_.in ()))
        {
          publisher = participant->create_publisher_with_profile (
                                              this->qos_profile_.in (),
                                              ::DDS::PublisherListener::_nil (),
                                              0);
        }
      else
#else
        ACE_UNUSED_ARG (this->qos_profile_);
#endif
        {
          ::DDS::PublisherQos pqos;
          publisher = participant->create_publisher (pqos,
                                            ::DDS::PublisherListener::_nil (),
                                            0);
        }
      if (::CORBA::is_nil (publisher))
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_DDS_NIL_RETURN, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Base_Connector_T::init_publisher - "
                        "Error: Proxy returned a nil publisher.\n"));
          throw ::CCM_DDS::InternalError (::DDS::RETCODE_ERROR, 0);
        }
    }
}

template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::init_subscriber (
  ::DDS::DomainParticipant_ptr participant,
  ::DDS::Subscriber_ptr & subscriber)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::init_subscriber");

  if (::CORBA::is_nil (subscriber))
    {
#if (CIAO_DDS4CCM_NDDS==1)
      if (!::CORBA::is_nil (this->qos_profile_.in ()))
        {
          subscriber = participant->create_subscriber_with_profile (
                                              this->qos_profile_.in (),
                                              ::DDS::SubscriberListener::_nil (),
                                              0);
        }
      else
#else
        ACE_UNUSED_ARG (this->qos_profile_);
#endif
        {
          ::DDS::SubscriberQos sqos;
          subscriber = participant->create_subscriber (sqos,
                                              ::DDS::SubscriberListener::_nil (),
                                              0);
        }
      if (::CORBA::is_nil (subscriber))
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_DDS_NIL_RETURN, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Base_Connector_T::init_subscriber - "
                        "Error: Proxy returned a nil subscriber.\n"));
          throw ::CCM_DDS::InternalError (::DDS::RETCODE_ERROR, 0);
        }
    }
}

/**
  * Activation
 **/
template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::activate_topic (
  ACE_Reactor* reactor,
  ::DDS::Topic_ptr topic,
  ::DDS::TopicListener_ptr & listener)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::activate_topic");

  ::CCM_DDS::ConnectorStatusListener_var error_listener =
    this->context_->get_connection_error_listener ();

  ::DDS::StatusMask const mask =
    ::CIAO::DDS4CCM::TopicListener::get_mask (error_listener.in ());

  if (mask != 0)
    {
      if (::CORBA::is_nil (listener))
        {
          ACE_NEW_THROW_EX (listener,
                            ::CIAO::DDS4CCM::TopicListener (
                              error_listener.in (),
                              reactor),
                            ::CORBA::NO_MEMORY ());

          ::DDS::ReturnCode_t const retcode = topic->set_listener (listener,
                                                                   mask);

          if (retcode != ::DDS::RETCODE_OK)
            {
              DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                            "DDS_Base_Connector_T::activate_topic - "
                            "Error while setting the listener on the topic - <%C>\n",
                            ::CIAO::DDS4CCM::translate_retcode (retcode)));
              throw ::CORBA::INTERNAL ();
            }
        }
    }
}

template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::activate_publisher (
  ACE_Reactor* reactor,
  ::DDS::Publisher_ptr publisher,
  ::DDS::PublisherListener_ptr & publisher_listener)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::activate_publisher");

  ::CCM_DDS::ConnectorStatusListener_var error_listener =
    this->context_->get_connection_error_listener ();

  ::DDS::StatusMask const mask =
      ::CIAO::DDS4CCM::PublisherListener::get_mask (error_listener.in ());

  if (mask != 0)
    {
      if (::CORBA::is_nil (publisher_listener))
        {
          ACE_NEW_THROW_EX (publisher_listener,
                            ::CIAO::DDS4CCM::PublisherListener (
                              error_listener.in (),
                              reactor),
                            ::CORBA::NO_MEMORY ());
        }

      ::DDS::ReturnCode_t const retcode = publisher->set_listener (publisher_listener,
                                                                   mask);

      if (retcode != ::DDS::RETCODE_OK)
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Base_Connector_T::activate_publisher - "
                        "Error while setting the listener on the publisher - <%C>\n",
                        ::CIAO::DDS4CCM::translate_retcode (retcode)));
          throw ::CORBA::INTERNAL ();
        }
    }
}

template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::activate_subscriber (
  ACE_Reactor* reactor,
  ::DDS::Subscriber_ptr subscriber,
  ::DDS::SubscriberListener_ptr & subscriber_listener)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::activate_subscriber");

  ::CCM_DDS::ConnectorStatusListener_var error_listener =
    this->context_->get_connection_error_listener ();

  ::DDS::StatusMask const mask =
    ::CIAO::DDS4CCM::SubscriberListener::get_mask (error_listener.in ());

  if (mask != 0)
    {
      if (::CORBA::is_nil (subscriber_listener))
        {
          ACE_NEW_THROW_EX (subscriber_listener,
                            ::CIAO::DDS4CCM::SubscriberListener (
                              error_listener.in (),
                              reactor),
                            ::CORBA::NO_MEMORY ());
        }

      ::DDS::ReturnCode_t const retcode = subscriber->set_listener (subscriber_listener,
                                                                    mask);

      if (retcode != ::DDS::RETCODE_OK)
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Base_Connector_T::activate_subscriber - "
                        "Error while setting the listener on the subscriber - <%C>\n",
                        ::CIAO::DDS4CCM::translate_retcode (retcode)));
          throw ::CORBA::INTERNAL ();
        }
    }
}

/**
  * Passivation
 **/
template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::passivate_topic (
  ::DDS::Topic_ptr topic,
  ::DDS::TopicListener_ptr topic_listener)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::passivate_topic");

  if (!::CORBA::is_nil (topic_listener))
    {
      ::DDS::ReturnCode_t const retcode =
        topic->set_listener (::DDS::TopicListener::_nil (), 0);
      if (retcode != ::DDS::RETCODE_OK)
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Base_Connector_T::passivate_topic - "
                        "Error while setting the listener on the topic - <%C>\n",
                        ::CIAO::DDS4CCM::translate_retcode (retcode)));
          throw ::CORBA::INTERNAL ();
        }
    }
}

template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::passivate_publisher (
  ::DDS::Publisher_ptr publisher,
  ::DDS::PublisherListener_ptr publisher_listener)

{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::passivate_publisher");

  if (!::CORBA::is_nil (publisher_listener))
    {
      ::DDS::ReturnCode_t const retcode =
        publisher->set_listener (::DDS::PublisherListener::_nil (), 0);

      if (retcode != ::DDS::RETCODE_OK)
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Base_Connector_T::passivate_publisher - "
                        "Error while setting the listener on the publisher - <%C>\n",
                        ::CIAO::DDS4CCM::translate_retcode (retcode)));
          throw ::CORBA::INTERNAL ();
        }
    }
}

template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::passivate_subscriber (
  ::DDS::Subscriber_ptr subscriber,
  ::DDS::SubscriberListener_ptr subscriber_listener)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::passivate_subscriber");

  if (!::CORBA::is_nil (subscriber_listener))
    {
      ::DDS::ReturnCode_t const retcode =
        subscriber->set_listener (::DDS::SubscriberListener::_nil (), 0);
      if (retcode != ::DDS::RETCODE_OK)
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Base_Connector_T::passivate_subscriber - "
                        "Error while setting the listener on the subscriber - <%C>\n",
                        ::CIAO::DDS4CCM::translate_retcode (retcode)));
          throw ::CORBA::INTERNAL ();
        }
    }
}

/**
  * Removal
 **/
template <typename CCM_TYPE>
void DDS_Base_Connector_T<CCM_TYPE>::remove_topic (
  ::DDS::DomainParticipant_ptr participant,
  ::DDS::Topic_ptr topic)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::remove_topic");

  ::DDS::ReturnCode_t retcode = participant->delete_topic (topic);
  if (retcode != ::DDS::RETCODE_OK)
    {
      throw ::CCM_DDS::InternalError (retcode, 0);
    }
}

template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::remove_publisher (
  ::DDS::DomainParticipant_ptr participant,
  ::DDS::Publisher_ptr publisher)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::remove_publisher");

  participant->delete_publisher (publisher);
}

template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::remove_subscriber (
  ::DDS::DomainParticipant_ptr participant,
  ::DDS::Subscriber_ptr subscriber)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::remove_subscriber");

  participant->delete_subscriber (subscriber);
}

template <typename CCM_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE>::remove_domain (
  ::DDS::DomainParticipant_ptr participant)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::remove_domain");

  ::DDS::ReturnCode_t const retcode = this->participant_factory_.delete_participant (participant);
  if (retcode != ::DDS::RETCODE_OK)
    {
      throw ::CCM_DDS::InternalError (retcode, 0);
    }
}