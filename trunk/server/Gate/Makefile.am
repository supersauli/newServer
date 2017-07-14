AUTOMAKE_OPTIONS=foreign
CXX :=clang++
CPPFLAGS=-I ../sdk/ -I ../proto/
bin_PROGRAMS=Gate
Gate_SOURCES=Gate.cpp 
Gate_LDADD = ../sdk/libsdk.la ../proto/libprotocol.la
