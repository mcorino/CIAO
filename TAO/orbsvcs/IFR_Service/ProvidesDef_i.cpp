/* -*- C++ -*- */
// $Id$

#include "Repository_i.h"
#include "ProvidesDef_i.h"

ACE_RCSID(IFR_Service, ProvidesDef_i, "$Id$")

TAO_ProvidesDef_i::TAO_ProvidesDef_i (
    TAO_Repository_i *repo,
    ACE_Configuration_Section_Key section_key
  )
  : TAO_IRObject_i (repo, section_key),
    TAO_Contained_i (repo, section_key)
{
}

TAO_ProvidesDef_i::~TAO_ProvidesDef_i (void)
{
}

IR::DefinitionKind
TAO_ProvidesDef_i::def_kind (CORBA::Environment &)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  return IR::dk_Provides;
}

void 
TAO_ProvidesDef_i::destroy (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
}

IR::Contained::Description *
TAO_ProvidesDef_i::describe (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

IR::InterfaceDef_ptr 
TAO_ProvidesDef_i::interface_type (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

