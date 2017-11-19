AUTOMAKE_OPTIONS=foreign
CXX := clang++
#CXX := g++
#INCLUDES=-I ../sdk/
CXXFLAGS+=-I ../sdk/
#CXXFLAGS+=-I ../sdk/ -lstdc++ 
#CFLAGS=-I ../sdk/ -stdlib=libc++
bin_PROGRAMS=main
main_SOURCES=main.cpp 

main_LDADD = ../sdk/libsdk.la 
main_LDFLAGS = -no-install
