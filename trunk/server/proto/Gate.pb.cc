// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/Gate.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "proto/Gate.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace GateServer {

namespace {

const ::google::protobuf::Descriptor* UserLogin_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UserLogin_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_proto_2fGate_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_proto_2fGate_2eproto() {
  protobuf_AddDesc_proto_2fGate_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "proto/Gate.proto");
  GOOGLE_CHECK(file != NULL);
  UserLogin_descriptor_ = file->message_type(0);
  static const int UserLogin_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UserLogin, dwid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UserLogin, str_),
  };
  UserLogin_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      UserLogin_descriptor_,
      UserLogin::default_instance_,
      UserLogin_offsets_,
      -1,
      -1,
      -1,
      sizeof(UserLogin),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UserLogin, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UserLogin, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_proto_2fGate_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      UserLogin_descriptor_, &UserLogin::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_proto_2fGate_2eproto() {
  delete UserLogin::default_instance_;
  delete UserLogin_reflection_;
}

void protobuf_AddDesc_proto_2fGate_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_proto_2fGate_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\020proto/Gate.proto\022\nGateServer\"&\n\tUserLo"
    "gin\022\014\n\004dwID\030\001 \001(\r\022\013\n\003str\030\002 \001(\014b\006proto3", 78);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "proto/Gate.proto", &protobuf_RegisterTypes);
  UserLogin::default_instance_ = new UserLogin();
  UserLogin::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_proto_2fGate_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_proto_2fGate_2eproto {
  StaticDescriptorInitializer_proto_2fGate_2eproto() {
    protobuf_AddDesc_proto_2fGate_2eproto();
  }
} static_descriptor_initializer_proto_2fGate_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int UserLogin::kDwIDFieldNumber;
const int UserLogin::kStrFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

UserLogin::UserLogin()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:GateServer.UserLogin)
}

void UserLogin::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

UserLogin::UserLogin(const UserLogin& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:GateServer.UserLogin)
}

void UserLogin::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  dwid_ = 0u;
  str_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

UserLogin::~UserLogin() {
  // @@protoc_insertion_point(destructor:GateServer.UserLogin)
  SharedDtor();
}

void UserLogin::SharedDtor() {
  str_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void UserLogin::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* UserLogin::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UserLogin_descriptor_;
}

const UserLogin& UserLogin::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_proto_2fGate_2eproto();
  return *default_instance_;
}

UserLogin* UserLogin::default_instance_ = NULL;

UserLogin* UserLogin::New(::google::protobuf::Arena* arena) const {
  UserLogin* n = new UserLogin;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void UserLogin::Clear() {
// @@protoc_insertion_point(message_clear_start:GateServer.UserLogin)
  dwid_ = 0u;
  str_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool UserLogin::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:GateServer.UserLogin)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 dwID = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &dwid_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_str;
        break;
      }

      // optional bytes str = 2;
      case 2: {
        if (tag == 18) {
         parse_str:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_str()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:GateServer.UserLogin)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:GateServer.UserLogin)
  return false;
#undef DO_
}

void UserLogin::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:GateServer.UserLogin)
  // optional uint32 dwID = 1;
  if (this->dwid() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->dwid(), output);
  }

  // optional bytes str = 2;
  if (this->str().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->str(), output);
  }

  // @@protoc_insertion_point(serialize_end:GateServer.UserLogin)
}

::google::protobuf::uint8* UserLogin::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:GateServer.UserLogin)
  // optional uint32 dwID = 1;
  if (this->dwid() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->dwid(), target);
  }

  // optional bytes str = 2;
  if (this->str().size() > 0) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->str(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:GateServer.UserLogin)
  return target;
}

int UserLogin::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:GateServer.UserLogin)
  int total_size = 0;

  // optional uint32 dwID = 1;
  if (this->dwid() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->dwid());
  }

  // optional bytes str = 2;
  if (this->str().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->str());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void UserLogin::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:GateServer.UserLogin)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const UserLogin* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const UserLogin>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:GateServer.UserLogin)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:GateServer.UserLogin)
    MergeFrom(*source);
  }
}

void UserLogin::MergeFrom(const UserLogin& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:GateServer.UserLogin)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.dwid() != 0) {
    set_dwid(from.dwid());
  }
  if (from.str().size() > 0) {

    str_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.str_);
  }
}

void UserLogin::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:GateServer.UserLogin)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UserLogin::CopyFrom(const UserLogin& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:GateServer.UserLogin)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UserLogin::IsInitialized() const {

  return true;
}

void UserLogin::Swap(UserLogin* other) {
  if (other == this) return;
  InternalSwap(other);
}
void UserLogin::InternalSwap(UserLogin* other) {
  std::swap(dwid_, other->dwid_);
  str_.Swap(&other->str_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata UserLogin::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = UserLogin_descriptor_;
  metadata.reflection = UserLogin_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// UserLogin

// optional uint32 dwID = 1;
void UserLogin::clear_dwid() {
  dwid_ = 0u;
}
 ::google::protobuf::uint32 UserLogin::dwid() const {
  // @@protoc_insertion_point(field_get:GateServer.UserLogin.dwID)
  return dwid_;
}
 void UserLogin::set_dwid(::google::protobuf::uint32 value) {
  
  dwid_ = value;
  // @@protoc_insertion_point(field_set:GateServer.UserLogin.dwID)
}

// optional bytes str = 2;
void UserLogin::clear_str() {
  str_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& UserLogin::str() const {
  // @@protoc_insertion_point(field_get:GateServer.UserLogin.str)
  return str_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void UserLogin::set_str(const ::std::string& value) {
  
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:GateServer.UserLogin.str)
}
 void UserLogin::set_str(const char* value) {
  
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:GateServer.UserLogin.str)
}
 void UserLogin::set_str(const void* value, size_t size) {
  
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:GateServer.UserLogin.str)
}
 ::std::string* UserLogin::mutable_str() {
  
  // @@protoc_insertion_point(field_mutable:GateServer.UserLogin.str)
  return str_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* UserLogin::release_str() {
  // @@protoc_insertion_point(field_release:GateServer.UserLogin.str)
  
  return str_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void UserLogin::set_allocated_str(::std::string* str) {
  if (str != NULL) {
    
  } else {
    
  }
  str_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), str);
  // @@protoc_insertion_point(field_set_allocated:GateServer.UserLogin.str)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace GateServer

// @@protoc_insertion_point(global_scope)