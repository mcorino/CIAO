/* -*- C++ -*- */
//
// $Id$
//
// ================================================================
//
// = LIBRARY
//   TAO
//
// = FILENAME
//   PollableC.h
//
// = DESCRIPTION
//   Generated from Pollable.pidl
//   The code was generated by the IDL compiler and then hand-crafted
//   to reduce the includes interdependencies.
//
// ================================================================

#ifndef TAO_IDL_POLLABLEC_H
#define TAO_IDL_POLLABLEC_H

#include "tao/corbafwd.h"

#if (TAO_HAS_CORBA_MESSAGING == 1) && (TAO_HAS_AMI_POLLER == 1)

#include "tao/Object.h"
#include "tao/Exception.h"
#include "tao/CDR.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export
#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

class CORBA_PollableSet;
typedef CORBA_PollableSet *CORBA_PollableSet_ptr;

class TAO_Export CORBA_PollableSet_var
{
public:
  CORBA_PollableSet_var (void); // default constructor
  CORBA_PollableSet_var (CORBA_PollableSet_ptr);
  CORBA_PollableSet_var (const CORBA_PollableSet_var &); // copy constructor
  ~CORBA_PollableSet_var (void); // destructor

  CORBA_PollableSet_var &operator= (CORBA_PollableSet_ptr);
  CORBA_PollableSet_var &operator= (const CORBA_PollableSet_var &);
  CORBA_PollableSet_ptr operator-> (void) const;

  operator const CORBA_PollableSet_ptr &() const;
  operator CORBA_PollableSet_ptr &();
  // in, inout, out, _retn
  CORBA_PollableSet_ptr in (void) const;
  CORBA_PollableSet_ptr &inout (void);
  CORBA_PollableSet_ptr &out (void);
  CORBA_PollableSet_ptr _retn (void);
  CORBA_PollableSet_ptr ptr (void) const;

private:
  CORBA_PollableSet_ptr ptr_;
};

class TAO_Export CORBA_PollableSet_out
{
public:
  CORBA_PollableSet_out (CORBA_PollableSet_ptr &);
  CORBA_PollableSet_out (CORBA_PollableSet_var &);
  CORBA_PollableSet_out (const CORBA_PollableSet_out &);
  CORBA_PollableSet_out &operator= (const CORBA_PollableSet_out &);
  CORBA_PollableSet_out &operator= (const CORBA_PollableSet_var &);
  CORBA_PollableSet_out &operator= (CORBA_PollableSet_ptr);
  operator CORBA_PollableSet_ptr &();
  CORBA_PollableSet_ptr &ptr (void);
  CORBA_PollableSet_ptr operator-> (void);

private:
  CORBA_PollableSet_ptr &ptr_;
};

class CORBA_Pollable;
typedef CORBA_Pollable *CORBA_Pollable_ptr;

class TAO_Export CORBA_Pollable_var
{
public:
  CORBA_Pollable_var (void); // default constructor
  CORBA_Pollable_var (CORBA_Pollable_ptr);
  CORBA_Pollable_var (const CORBA_Pollable_var &); // copy constructor
  ~CORBA_Pollable_var (void); // destructor

  CORBA_Pollable_var &operator= (CORBA_Pollable_ptr);
  CORBA_Pollable_var &operator= (const CORBA_Pollable_var &);
  CORBA_Pollable_ptr operator-> (void) const;

  operator const CORBA_Pollable_ptr &() const;
  operator CORBA_Pollable_ptr &();
  // in, inout, out, _retn
  CORBA_Pollable_ptr in (void) const;
  CORBA_Pollable_ptr &inout (void);
  CORBA_Pollable_ptr &out (void);
  CORBA_Pollable_ptr _retn (void);
  CORBA_Pollable_ptr ptr (void) const;

private:
  CORBA_Pollable_ptr ptr_;
};

class TAO_Export CORBA_Pollable_out
{
public:
  CORBA_Pollable_out (CORBA_Pollable_ptr &);
  CORBA_Pollable_out (CORBA_Pollable_var &);
  CORBA_Pollable_out (const CORBA_Pollable_out &);
  CORBA_Pollable_out &operator= (const CORBA_Pollable_out &);
  CORBA_Pollable_out &operator= (const CORBA_Pollable_var &);
  CORBA_Pollable_out &operator= (CORBA_Pollable_ptr);
  operator CORBA_Pollable_ptr &();
  CORBA_Pollable_ptr &ptr (void);
  CORBA_Pollable_ptr operator-> (void);

private:
  CORBA_Pollable_ptr &ptr_;
};

class TAO_Export CORBA_Pollable : public virtual CORBA_Object
{
 public:
#if !defined(__GNUC__) || __GNUC__ > 2 || __GNUC_MINOR__ >= 8
  typedef CORBA_Pollable_ptr _ptr_type;
  typedef CORBA_Pollable_var _var_type;
#endif /* __GNUC__ */

  // the static operations
  static CORBA_Pollable_ptr _duplicate (CORBA_Pollable_ptr obj);
  static CORBA_Pollable_ptr _narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_Pollable_ptr _unchecked_narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_Pollable_ptr _nil (void);

  virtual CORBA::Boolean is_ready (
      CORBA::ULong timeout,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  virtual CORBA_PollableSet_ptr create_pollable_set (
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  virtual CORBA::Boolean _is_a (
      const CORBA::Char *type_id,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  virtual const char* _interface_repository_id (void) const;
protected:
  CORBA_Pollable (void); // default constructor
  CORBA_Pollable (TAO_Stub *objref,
      TAO_ServantBase *_tao_servant = 0,
      CORBA::Boolean _tao_collocated = 0
    );
  virtual ~CORBA_Pollable (void);
private:
  CORBA_Pollable (const CORBA_Pollable &);
  void operator= (const CORBA_Pollable &);
};

class CORBA_DIIPollable;
typedef CORBA_DIIPollable *CORBA_DIIPollable_ptr;

class TAO_Export CORBA_DIIPollable_var
{
public:
  CORBA_DIIPollable_var (void); // default constructor
  CORBA_DIIPollable_var (CORBA_DIIPollable_ptr);
  CORBA_DIIPollable_var (const CORBA_DIIPollable_var &); // copy constructor
  ~CORBA_DIIPollable_var (void); // destructor

  CORBA_DIIPollable_var &operator= (CORBA_DIIPollable_ptr);
  CORBA_DIIPollable_var &operator= (const CORBA_DIIPollable_var &);
  CORBA_DIIPollable_ptr operator-> (void) const;

  operator const CORBA_DIIPollable_ptr &() const;
  operator CORBA_DIIPollable_ptr &();
  // in, inout, out, _retn
  CORBA_DIIPollable_ptr in (void) const;
  CORBA_DIIPollable_ptr &inout (void);
  CORBA_DIIPollable_ptr &out (void);
  CORBA_DIIPollable_ptr _retn (void);
  CORBA_DIIPollable_ptr ptr (void) const;

private:
  CORBA_DIIPollable_ptr ptr_;
};

class TAO_Export CORBA_DIIPollable_out
{
public:
  CORBA_DIIPollable_out (CORBA_DIIPollable_ptr &);
  CORBA_DIIPollable_out (CORBA_DIIPollable_var &);
  CORBA_DIIPollable_out (const CORBA_DIIPollable_out &);
  CORBA_DIIPollable_out &operator= (const CORBA_DIIPollable_out &);
  CORBA_DIIPollable_out &operator= (const CORBA_DIIPollable_var &);
  CORBA_DIIPollable_out &operator= (CORBA_DIIPollable_ptr);
  operator CORBA_DIIPollable_ptr &();
  CORBA_DIIPollable_ptr &ptr (void);
  CORBA_DIIPollable_ptr operator-> (void);

private:
  CORBA_DIIPollable_ptr &ptr_;
};

class TAO_Export CORBA_DIIPollable: public virtual CORBA_Pollable
{
public:
#if !defined(__GNUC__) || __GNUC__ > 2 || __GNUC_MINOR__ >= 8
  typedef CORBA_DIIPollable_ptr _ptr_type;
  typedef CORBA_DIIPollable_var _var_type;
#endif /* __GNUC__ */

  // the static operations
  static CORBA_DIIPollable_ptr _duplicate (CORBA_DIIPollable_ptr obj);
  static CORBA_DIIPollable_ptr _narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_DIIPollable_ptr _unchecked_narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_DIIPollable_ptr _nil (void);

  virtual CORBA::Boolean _is_a (
      const CORBA::Char *type_id,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  virtual const char* _interface_repository_id (void) const;
protected:
  CORBA_DIIPollable (void); // default constructor
  CORBA_DIIPollable (TAO_Stub *objref,
      TAO_ServantBase *_tao_servant = 0,
      CORBA::Boolean _tao_collocated = 0
    );
  virtual ~CORBA_DIIPollable (void);
private:
  CORBA_DIIPollable (const CORBA_DIIPollable &);
  void operator= (const CORBA_DIIPollable &);
};

class TAO_Export CORBA_PollableSet : public virtual ACE_CORBA_1 (Object)
{
public:
#if !defined(__GNUC__) || __GNUC__ > 2 || __GNUC_MINOR__ >= 8
  typedef CORBA_PollableSet_ptr _ptr_type;
  typedef CORBA_PollableSet_var _var_type;
#endif /* __GNUC__ */

  // the static operations
  static CORBA_PollableSet_ptr _duplicate (CORBA_PollableSet_ptr obj);
  static CORBA_PollableSet_ptr _narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_PollableSet_ptr _unchecked_narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_PollableSet_ptr _nil (void);

  class NoPossiblePollable;
  typedef NoPossiblePollable *NoPossiblePollable_ptr;

  class TAO_Export NoPossiblePollable : public CORBA::UserException
  {
  public:
    // ****************
    // The fields (and their helper classes)


    // End of implicit types for the fields
    // ****************

    NoPossiblePollable (void); // default ctor
    NoPossiblePollable (const NoPossiblePollable &); // copy ctor
    ~NoPossiblePollable (void); // dtor
          NoPossiblePollable &operator= (const NoPossiblePollable &);


    virtual void _raise (void);

    static NoPossiblePollable *_narrow (CORBA::Exception *);


    // = TAO extension
    static CORBA::Exception *_alloc (void);

  }; // exception CORBA::PollableSet::NoPossiblePollable

  static CORBA::TypeCode_ptr _tc_NoPossiblePollable;

  class UnknownPollable;
  typedef UnknownPollable *UnknownPollable_ptr;

  class TAO_Export UnknownPollable : public CORBA::UserException
  {
  public:
    // ****************
    // The fields (and their helper classes)


    // End of implicit types for the fields
    // ****************

    UnknownPollable (void); // default ctor
    UnknownPollable (const UnknownPollable &); // copy ctor
    ~UnknownPollable (void); // dtor
          UnknownPollable &operator= (const UnknownPollable &);


    virtual void _raise (void);

    static UnknownPollable *_narrow (CORBA::Exception *);


    // = TAO extension
    static CORBA::Exception *_alloc (void);

  }; // exception CORBA::PollableSet::UnknownPollable

  static CORBA::TypeCode_ptr _tc_UnknownPollable;


  virtual CORBA_DIIPollable_ptr create_dii_pollable (
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  virtual void add_pollable (
      CORBA_Pollable_ptr potential,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  virtual CORBA_Pollable_ptr poll (
      CORBA::ULong timeout,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  virtual void remove (
      CORBA_Pollable_ptr potential,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  virtual CORBA::UShort number_left (
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  virtual CORBA::Boolean _is_a (
      const CORBA::Char *type_id,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  virtual const char* _interface_repository_id (void) const;
protected:
  CORBA_PollableSet (void); // default constructor
  CORBA_PollableSet (TAO_Stub *objref,
      TAO_ServantBase *_tao_servant = 0,
      CORBA::Boolean _tao_collocated = 0
    );
  virtual ~CORBA_PollableSet (void);
private:
  CORBA_PollableSet (const CORBA_PollableSet &);
  void operator= (const CORBA_PollableSet &);
};

// Any operators for interface CORBA_Pollable
TAO_Export void operator<<= (CORBA::Any &, CORBA_Pollable_ptr);
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA_Pollable *&);
// Any operators for interface CORBA::DIIPollable
TAO_Export void operator<<= (CORBA::Any &, CORBA::DIIPollable_ptr);
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::DIIPollable *&);
// Any operators for interface CORBA_PollableSet
TAO_Export void operator<<= (CORBA::Any &, CORBA_PollableSet_ptr);
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA_PollableSet *&);
TAO_Export void operator<<= (CORBA::Any &, const CORBA_PollableSet::NoPossiblePollable &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA_PollableSet::NoPossiblePollable*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA_PollableSet::NoPossiblePollable *&);
TAO_Export void operator<<= (CORBA::Any &, const CORBA_PollableSet::UnknownPollable &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA_PollableSet::UnknownPollable*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA_PollableSet::UnknownPollable *&);

#ifndef __ACE_INLINE__

TAO_Export CORBA::Boolean
operator<< (TAO_OutputCDR &, const CORBA_Pollable_ptr );
TAO_Export CORBA::Boolean
operator>> (TAO_InputCDR &, CORBA_Pollable_ptr &);
TAO_Export CORBA::Boolean
operator<< (TAO_OutputCDR &, const CORBA::DIIPollable_ptr );
TAO_Export CORBA::Boolean
operator>> (TAO_InputCDR &, CORBA::DIIPollable_ptr &);
TAO_Export CORBA::Boolean
operator<< (TAO_OutputCDR &, const CORBA_PollableSet_ptr );
TAO_Export CORBA::Boolean
operator>> (TAO_InputCDR &, CORBA_PollableSet_ptr &);
TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA_PollableSet::NoPossiblePollable &); //
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA_PollableSet::NoPossiblePollable &);
TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA_PollableSet::UnknownPollable &); //
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA_PollableSet::UnknownPollable &);

#endif /* __ACE_INLINE__ */


#if defined (__ACE_INLINE__)
#include "tao/PollableC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* TAO_HAS_CORBA_MESSAGING == 1 && TAO_HAS_AMI_POLLER == 1 */

#endif /* TAO_IDL_POLLABLEC_H */
