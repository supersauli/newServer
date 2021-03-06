// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/LoginProto.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "proto/LoginProto.pb.h"

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

namespace LoginProto {

namespace {

const ::google::protobuf::Descriptor* Result_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Result_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_proto_2fLoginProto_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_proto_2fLoginProto_2eproto() {
  protobuf_AddDesc_proto_2fLoginProto_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "proto/LoginProto.proto");
  GOOGLE_CHECK(file != NULL);
  Result_descriptor_ = file->message_type(0);
  static const int Result_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Result, dwid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Result, result_),
  };
  Result_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Result_descriptor_,
      Result::default_instance_,
      Result_offsets_,
      -1,
      -1,
      -1,
      sizeof(Result),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Result, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Result, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_proto_2fLoginProto_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Result_descriptor_, &Result::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_proto_2fLoginProto_2eproto() {
  delete Result::default_instance_;
  delete Result_reflection_;
}

void protobuf_AddDesc_proto_2fLoginProto_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_proto_2fLoginProto_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\026proto/LoginProto.proto\022\nLoginProto\"&\n\006"
    "Result\022\014\n\004dwID\030\001 \001(\r\022\016\n\006result\030\002 \001(\010b\006pr"
    "oto3", 84);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "proto/LoginProto.proto", &protobuf_RegisterTypes);
  Result::default_instance_ = new Result();
  Result::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_proto_2fLoginProto_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_proto_2fLoginProto_2eproto {
  StaticDescriptorInitializer_proto_2fLoginProto_2eproto() {
    protobuf_AddDesc_proto_2fLoginProto_2eproto();
  }
} static_descriptor_initializer_proto_2fLoginProto_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Result::kDwIDFieldNumber;
const int Result::kResultFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Result::Result()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:LoginProto.Result)
}

void Result::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

Result::Result(const Result& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:LoginProto.Result)
}

void Result::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  dwid_ = 0u;
  result_ = false;
}

Result::~Result() {
  // @@protoc_insertion_point(destructor:LoginProto.Result)
  SharedDtor();
}

void Result::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Result::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Result::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Result_descriptor_;
}

const Result& Result::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_proto_2fLoginProto_2eproto();
  return *default_instance_;
}

Result* Result::default_instance_ = NULL;

Result* Result::New(::google::protobuf::Arena* arena) const {
  Result* n = new Result;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Result::Clear() {
// @@protoc_insertion_point(message_clear_start:LoginProto.Result)
#if defined(__clang__)
#define ZR_HELPER_(f) \
  _Pragma("clang diagnostic push") \
  _Pragma("clang diagnostic ignored \"-Winvalid-offsetof\"") \
  __builtin_offsetof(Result, f) \
  _Pragma("clang diagnostic pop")
#else
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<Result*>(16)->f)
#endif

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  ZR_(dwid_, result_);

#undef ZR_HELPER_
#undef ZR_

}

bool Result::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:LoginProto.Result)
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
        if (input->ExpectTag(16)) goto parse_result;
        break;
      }

      // optional bool result = 2;
      case 2: {
        if (tag == 16) {
         parse_result:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &result_)));

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
  // @@protoc_insertion_point(parse_success:LoginProto.Result)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:LoginProto.Result)
  return false;
#undef DO_
}

void Result::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:LoginProto.Result)
  // optional uint32 dwID = 1;
  if (this->dwid() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->dwid(), output);
  }

  // optional bool result = 2;
  if (this->result() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->result(), output);
  }

  // @@protoc_insertion_point(serialize_end:LoginProto.Result)
}

::google::protobuf::uint8* Result::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:LoginProto.Result)
  // optional uint32 dwID = 1;
  if (this->dwid() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->dwid(), target);
  }

  // optional bool result = 2;
  if (this->result() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->result(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:LoginProto.Result)
  return target;
}

int Result::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:LoginProto.Result)
  int total_size = 0;

  // optional uint32 dwID = 1;
  if (this->dwid() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->dwid());
  }

  // optional bool result = 2;
  if (this->result() != 0) {
    total_size += 1 + 1;
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Result::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:LoginProto.Result)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const Result* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const Result>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:LoginProto.Result)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:LoginProto.Result)
    MergeFrom(*source);
  }
}

void Result::MergeFrom(const Result& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:LoginProto.Result)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.dwid() != 0) {
    set_dwid(from.dwid());
  }
  if (from.result() != 0) {
    set_result(from.result());
  }
}

void Result::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:LoginProto.Result)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Result::CopyFrom(const Result& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:LoginProto.Result)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Result::IsInitialized() const {

  return true;
}

void Result::Swap(Result* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Result::InternalSwap(Result* other) {
  std::swap(dwid_, other->dwid_);
  std::swap(result_, other->result_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Result::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Result_descriptor_;
  metadata.reflection = Result_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Result

// optional uint32 dwID = 1;
void Result::clear_dwid() {
  dwid_ = 0u;
}
 ::google::protobuf::uint32 Result::dwid() const {
  // @@protoc_insertion_point(field_get:LoginProto.Result.dwID)
  return dwid_;
}
 void Result::set_dwid(::google::protobuf::uint32 value) {
  
  dwid_ = value;
  // @@protoc_insertion_point(field_set:LoginProto.Result.dwID)
}

// optional bool result = 2;
void Result::clear_result() {
  result_ = false;
}
 bool Result::result() const {
  // @@protoc_insertion_point(field_get:LoginProto.Result.result)
  return result_;
}
 void Result::set_result(bool value) {
  
  result_ = value;
  // @@protoc_insertion_point(field_set:LoginProto.Result.result)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace LoginProto

// @@protoc_insertion_point(global_scope)
