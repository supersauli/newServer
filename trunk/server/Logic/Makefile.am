CXX: = clang++
CXXFLAGS+=-I ../sdk/ -lstdc++ -static -L/usr/local/lib/ -lprotobuf
bin_PROGRAMS=LogicServer
LogicServer_SOURCES=LogicServer.cpp

LogicServer_LDADD = ../sdk/libsdk.la 
LogicServer_LDFLAGS = -no-install
