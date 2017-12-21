// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: BattleUserMsg.proto

#ifndef PROTOBUF_BattleUserMsg_2eproto__INCLUDED
#define PROTOBUF_BattleUserMsg_2eproto__INCLUDED

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
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
namespace BattleMsg {
}  // namespace BattleMsg

namespace BattleMsg {

namespace protobuf_BattleUserMsg_2eproto {
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
}  // namespace protobuf_BattleUserMsg_2eproto

enum BattleUserMsg {
  eBattleMsg_Unknown = 0,
  eBattleMsg_Login = 1,
  eBattleMsg_Logout = 2,
  eBattleMsg_Broadcast = 3,
  BattleUserMsg_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  BattleUserMsg_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool BattleUserMsg_IsValid(int value);
const BattleUserMsg BattleUserMsg_MIN = eBattleMsg_Unknown;
const BattleUserMsg BattleUserMsg_MAX = eBattleMsg_Broadcast;
const int BattleUserMsg_ARRAYSIZE = BattleUserMsg_MAX + 1;

const ::google::protobuf::EnumDescriptor* BattleUserMsg_descriptor();
inline const ::std::string& BattleUserMsg_Name(BattleUserMsg value) {
  return ::google::protobuf::internal::NameOfEnum(
    BattleUserMsg_descriptor(), value);
}
inline bool BattleUserMsg_Parse(
    const ::std::string& name, BattleUserMsg* value) {
  return ::google::protobuf::internal::ParseNamedEnum<BattleUserMsg>(
    BattleUserMsg_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace BattleMsg

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::BattleMsg::BattleUserMsg> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::BattleMsg::BattleUserMsg>() {
  return ::BattleMsg::BattleUserMsg_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_BattleUserMsg_2eproto__INCLUDED
