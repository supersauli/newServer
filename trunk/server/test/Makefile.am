AUTOMAKE_OPTIONS=foreign
CXX := clang++
#INCLUDES=-I ../sdk/
CXXFLAGS+=-I ../sdk/ -lstdc++ -static
#CFLAGS=-I ../sdk/ -stdlib=libc++
bin_PROGRAMS=main
main_SOURCES=main.cpp \
			 head.h \
			 test.pb.cc 

main_LDADD = ../sdk/libsdk.la 
main_LDFLAGS = -no-install
