AUTOMAKE_OPTIONS=foreign
CXX := clang++
#CXX := g++
#INCLUDES=-I ../sdk/
CXXFLAGS+=-I ../sdk/ -lstdc++ -static -L/usr/local/lib/ -lprotobuf
#CFLAGS=-I ../sdk/ -stdlib=libc++
bin_PROGRAMS=main
main_SOURCES=main.cpp \
			 head.h \
			 test.pb.cc 

main_LDADD = ../sdk/libsdk.la 
main_LDFLAGS = -no-install
