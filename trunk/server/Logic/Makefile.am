AUTOMAKE_OPTIONS=foreign
CXX :=clang++
CPPFLAGS=-I ../sdk/ ../proto/
bin_PROGRAMS=LogicServer
LogicServer_SOURCES=LogicServer.cpp \
					Package.cpp

LogicServer_LDADD = ../sdk/libsdk.la 
LogicServer_LDFLAGS = -no-install
