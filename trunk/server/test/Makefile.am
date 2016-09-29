AUTOMAKE_OPTIONS=foreign
CXX := clang++
#INCLUDES=-I ../sdk/
CXXFLAGS+=-I ../sdk/ -lstdc++
#CFLAGS=-I ../sdk/ -stdlib=libc++
bin_PROGRAMS=main
main_SOURCES=main.cpp \
			 head.h 

main_LDADD = ../sdk/libsdk.la  
main_LDFLAGS = -no-install
