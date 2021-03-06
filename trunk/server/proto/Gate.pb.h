// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/Gate.proto

#ifndef PROTOBUF_proto_2fGate_2eproto__INCLUDED
#define PROTOBUF_proto_2fGate_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace GateServer {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_proto_2fGate_2eproto();
void protobuf_AssignDesc_proto_2fGate_2eproto();
void protobuf_ShutdownFile_proto_2fGate_2eproto();

class NewGate;
class UserLogin;

// ===================================================================

class NewGate : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:GateServer.NewGate) */ {
 public:
  NewGate();
  virtual ~NewGate();

  NewGate(const NewGate& from);

  inline NewGate& operator=(const NewGate& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const NewGate& default_instance();

  void Swap(NewGate* other);

  // implements Message ----------------------------------------------

  inline NewGate* New() const { return New(NULL); }

  NewGate* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NewGate& from);
  void MergeFrom(const NewGate& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(NewGate* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 dwID = 1;
  void clear_dwid();
  static const int kDwIDFieldNumber = 1;
  ::google::protobuf::uint32 dwid() const;
  void set_dwid(::google::protobuf::uint32 value);

  // optional string strIP = 2;
  void clear_strip();
  static const int kStrIPFieldNumber = 2;
  const ::std::string& strip() const;
  void set_strip(const ::std::string& value);
  void set_strip(const char* value);
  void set_strip(const char* value, size_t size);
  ::std::string* mutable_strip();
  ::std::string* release_strip();
  void set_allocated_strip(::std::string* strip);

  // @@protoc_insertion_point(class_scope:GateServer.NewGate)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr strip_;
  ::google::protobuf::uint32 dwid_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_proto_2fGate_2eproto();
  friend void protobuf_AssignDesc_proto_2fGate_2eproto();
  friend void protobuf_ShutdownFile_proto_2fGate_2eproto();

  void InitAsDefaultInstance();
  static NewGate* default_instance_;
};
// -------------------------------------------------------------------

class UserLogin : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:GateServer.UserLogin) */ {
 public:
  UserLogin();
  virtual ~UserLogin();

  UserLogin(const UserLogin& from);

  inline UserLogin& operator=(const UserLogin& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const UserLogin& default_instance();

  void Swap(UserLogin* other);

  // implements Message ----------------------------------------------

  inline UserLogin* New() const { return New(NULL); }

  UserLogin* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const UserLogin& from);
  void MergeFrom(const UserLogin& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(UserLogin* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 dwID = 1;
  void clear_dwid();
  static const int kDwIDFieldNumber = 1;
  ::google::protobuf::uint32 dwid() const;
  void set_dwid(::google::protobuf::uint32 value);

  // optional bytes str = 2;
  void clear_str();
  static const int kStrFieldNumber = 2;
  const ::std::string& str() const;
  void set_str(const ::std::string& value);
  void set_str(const char* value);
  void set_str(const void* value, size_t size);
  ::std::string* mutable_str();
  ::std::string* release_str();
  void set_allocated_str(::std::string* str);

  // @@protoc_insertion_point(class_scope:GateServer.UserLogin)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr str_;
  ::google::protobuf::uint32 dwid_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_proto_2fGate_2eproto();
  friend void protobuf_AssignDesc_proto_2fGate_2eproto();
  friend void protobuf_ShutdownFile_proto_2fGate_2eproto();

  void InitAsDefaultInstance();
  static UserLogin* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// NewGate

// optional uint32 dwID = 1;
inline void NewGate::clear_dwid() {
  dwid_ = 0u;
}
inline ::google::protobuf::uint32 NewGate::dwid() const {
  // @@protoc_insertion_point(field_get:GateServer.NewGate.dwID)
  return dwid_;
}
inline void NewGate::set_dwid(::google::protobuf::uint32 value) {
  
  dwid_ = value;
  // @@protoc_insertion_point(field_set:GateServer.NewGate.dwID)
}

// optional string strIP = 2;
inline void NewGate::clear_strip() {
  strip_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& NewGate::strip() const {
  // @@protoc_insertion_point(field_get:GateServer.NewGate.strIP)
  return strip_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void NewGate::set_strip(const ::std::string& value) {
  
  strip_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:GateServer.NewGate.strIP)
}
inline void NewGate::set_strip(const char* value) {
  
  strip_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:GateServer.NewGate.strIP)
}
inline void NewGate::set_strip(const char* value, size_t size) {
  
  strip_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:GateServer.NewGate.strIP)
}
inline ::std::string* NewGate::mutable_strip() {
  
  // @@protoc_insertion_point(field_mutable:GateServer.NewGate.strIP)
  return strip_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* NewGate::release_strip() {
  // @@protoc_insertion_point(field_release:GateServer.NewGate.strIP)
  
  return strip_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void NewGate::set_allocated_strip(::std::string* strip) {
  if (strip != NULL) {
    
  } else {
    
  }
  strip_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), strip);
  // @@protoc_insertion_point(field_set_allocated:GateServer.NewGate.strIP)
}

// -------------------------------------------------------------------

// UserLogin

// optional uint32 dwID = 1;
inline void UserLogin::clear_dwid() {
  dwid_ = 0u;
}
inline ::google::protobuf::uint32 UserLogin::dwid() const {
  // @@protoc_insertion_point(field_get:GateServer.UserLogin.dwID)
  return dwid_;
}
inline void UserLogin::set_dwid(::google::protobuf::uint32 value) {
  
  dwid_ = value;
  // @@protoc_insertion_point(field_set:GateServer.UserLogin.dwID)
}

// optional bytes str = 2;
inline void UserLogin::clear_str() {
  str_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& UserLogin::str() const {
  // @@protoc_insertion_point(field_get:GateServer.UserLogin.str)
  return str_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void UserLogin::set_str(const ::std::string& value) {
  
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:GateServer.UserLogin.str)
}
inline void UserLogin::set_str(const char* value) {
  
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:GateServer.UserLogin.str)
}
inline void UserLogin::set_str(const void* value, size_t size) {
  
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:GateServer.UserLogin.str)
}
inline ::std::string* UserLogin::mutable_str() {
  
  // @@protoc_insertion_point(field_mutable:GateServer.UserLogin.str)
  return str_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* UserLogin::release_str() {
  // @@protoc_insertion_point(field_release:GateServer.UserLogin.str)
  
  return str_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void UserLogin::set_allocated_str(::std::string* str) {
  if (str != NULL) {
    
  } else {
    
  }
  str_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), str);
  // @@protoc_insertion_point(field_set_allocated:GateServer.UserLogin.str)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace GateServer

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_proto_2fGate_2eproto__INCLUDED
