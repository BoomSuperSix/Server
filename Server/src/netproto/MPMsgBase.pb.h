// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MPMsgBase.proto

#ifndef PROTOBUF_MPMsgBase_2eproto__INCLUDED
#define PROTOBUF_MPMsgBase_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "MPDefine.pb.h"
// @@protoc_insertion_point(includes)
namespace MPMsg {
class Ident;
class IdentDefaultTypeInternal;
extern IdentDefaultTypeInternal _Ident_default_instance_;
class MsgBase;
class MsgBaseDefaultTypeInternal;
extern MsgBaseDefaultTypeInternal _MsgBase_default_instance_;
}  // namespace MPMsg

namespace MPMsg {

namespace protobuf_MPMsgBase_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static void InitDefaultsImpl();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_MPMsgBase_2eproto

// ===================================================================

class Ident : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:MPMsg.Ident) */ {
 public:
  Ident();
  virtual ~Ident();

  Ident(const Ident& from);

  inline Ident& operator=(const Ident& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Ident(Ident&& from) noexcept
    : Ident() {
    *this = ::std::move(from);
  }

  inline Ident& operator=(Ident&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Ident& default_instance();

  static inline const Ident* internal_default_instance() {
    return reinterpret_cast<const Ident*>(
               &_Ident_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Ident* other);
  friend void swap(Ident& a, Ident& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Ident* New() const PROTOBUF_FINAL { return New(NULL); }

  Ident* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Ident& from);
  void MergeFrom(const Ident& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Ident* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // int64 high = 1;
  void clear_high();
  static const int kHighFieldNumber = 1;
  ::google::protobuf::int64 high() const;
  void set_high(::google::protobuf::int64 value);

  // int64 low = 2;
  void clear_low();
  static const int kLowFieldNumber = 2;
  ::google::protobuf::int64 low() const;
  void set_low(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:MPMsg.Ident)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int64 high_;
  ::google::protobuf::int64 low_;
  mutable int _cached_size_;
  friend struct protobuf_MPMsgBase_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class MsgBase : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:MPMsg.MsgBase) */ {
 public:
  MsgBase();
  virtual ~MsgBase();

  MsgBase(const MsgBase& from);

  inline MsgBase& operator=(const MsgBase& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MsgBase(MsgBase&& from) noexcept
    : MsgBase() {
    *this = ::std::move(from);
  }

  inline MsgBase& operator=(MsgBase&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const MsgBase& default_instance();

  static inline const MsgBase* internal_default_instance() {
    return reinterpret_cast<const MsgBase*>(
               &_MsgBase_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(MsgBase* other);
  friend void swap(MsgBase& a, MsgBase& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MsgBase* New() const PROTOBUF_FINAL { return New(NULL); }

  MsgBase* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const MsgBase& from);
  void MergeFrom(const MsgBase& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(MsgBase* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bytes msg_data = 3;
  void clear_msg_data();
  static const int kMsgDataFieldNumber = 3;
  const ::std::string& msg_data() const;
  void set_msg_data(const ::std::string& value);
  #if LANG_CXX11
  void set_msg_data(::std::string&& value);
  #endif
  void set_msg_data(const char* value);
  void set_msg_data(const void* value, size_t size);
  ::std::string* mutable_msg_data();
  ::std::string* release_msg_data();
  void set_allocated_msg_data(::std::string* msg_data);

  // uint32 msg_type = 1;
  void clear_msg_type();
  static const int kMsgTypeFieldNumber = 1;
  ::google::protobuf::uint32 msg_type() const;
  void set_msg_type(::google::protobuf::uint32 value);

  // uint32 msg_id = 2;
  void clear_msg_id();
  static const int kMsgIdFieldNumber = 2;
  ::google::protobuf::uint32 msg_id() const;
  void set_msg_id(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:MPMsg.MsgBase)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr msg_data_;
  ::google::protobuf::uint32 msg_type_;
  ::google::protobuf::uint32 msg_id_;
  mutable int _cached_size_;
  friend struct protobuf_MPMsgBase_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Ident

// int64 high = 1;
inline void Ident::clear_high() {
  high_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 Ident::high() const {
  // @@protoc_insertion_point(field_get:MPMsg.Ident.high)
  return high_;
}
inline void Ident::set_high(::google::protobuf::int64 value) {
  
  high_ = value;
  // @@protoc_insertion_point(field_set:MPMsg.Ident.high)
}

// int64 low = 2;
inline void Ident::clear_low() {
  low_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 Ident::low() const {
  // @@protoc_insertion_point(field_get:MPMsg.Ident.low)
  return low_;
}
inline void Ident::set_low(::google::protobuf::int64 value) {
  
  low_ = value;
  // @@protoc_insertion_point(field_set:MPMsg.Ident.low)
}

// -------------------------------------------------------------------

// MsgBase

// uint32 msg_type = 1;
inline void MsgBase::clear_msg_type() {
  msg_type_ = 0u;
}
inline ::google::protobuf::uint32 MsgBase::msg_type() const {
  // @@protoc_insertion_point(field_get:MPMsg.MsgBase.msg_type)
  return msg_type_;
}
inline void MsgBase::set_msg_type(::google::protobuf::uint32 value) {
  
  msg_type_ = value;
  // @@protoc_insertion_point(field_set:MPMsg.MsgBase.msg_type)
}

// uint32 msg_id = 2;
inline void MsgBase::clear_msg_id() {
  msg_id_ = 0u;
}
inline ::google::protobuf::uint32 MsgBase::msg_id() const {
  // @@protoc_insertion_point(field_get:MPMsg.MsgBase.msg_id)
  return msg_id_;
}
inline void MsgBase::set_msg_id(::google::protobuf::uint32 value) {
  
  msg_id_ = value;
  // @@protoc_insertion_point(field_set:MPMsg.MsgBase.msg_id)
}

// bytes msg_data = 3;
inline void MsgBase::clear_msg_data() {
  msg_data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MsgBase::msg_data() const {
  // @@protoc_insertion_point(field_get:MPMsg.MsgBase.msg_data)
  return msg_data_.GetNoArena();
}
inline void MsgBase::set_msg_data(const ::std::string& value) {
  
  msg_data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:MPMsg.MsgBase.msg_data)
}
#if LANG_CXX11
inline void MsgBase::set_msg_data(::std::string&& value) {
  
  msg_data_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:MPMsg.MsgBase.msg_data)
}
#endif
inline void MsgBase::set_msg_data(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  msg_data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:MPMsg.MsgBase.msg_data)
}
inline void MsgBase::set_msg_data(const void* value, size_t size) {
  
  msg_data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:MPMsg.MsgBase.msg_data)
}
inline ::std::string* MsgBase::mutable_msg_data() {
  
  // @@protoc_insertion_point(field_mutable:MPMsg.MsgBase.msg_data)
  return msg_data_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MsgBase::release_msg_data() {
  // @@protoc_insertion_point(field_release:MPMsg.MsgBase.msg_data)
  
  return msg_data_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MsgBase::set_allocated_msg_data(::std::string* msg_data) {
  if (msg_data != NULL) {
    
  } else {
    
  }
  msg_data_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), msg_data);
  // @@protoc_insertion_point(field_set_allocated:MPMsg.MsgBase.msg_data)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace MPMsg

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MPMsgBase_2eproto__INCLUDED
