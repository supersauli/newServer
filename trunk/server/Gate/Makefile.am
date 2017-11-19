AUTOMAKE_OPTIONS=foreign
CXX :=clang++
CPPFLAGS=-I ../sdk/ -I ../proto/
bin_PROGRAMS=GateServer
GateServer_SOURCES=GateServer.cpp 
GateServer_LDADD = ../sdk/libsdk.la ../proto/libprotocol.la
