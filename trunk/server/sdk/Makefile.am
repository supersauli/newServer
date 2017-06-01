AUTOMAKE_OPTIONS=foreign
#CXX := clang++
CXX := g++
#CXXFLAGS +=-llog4cplus -lsctp -lpthread
LIBS = -llog4cplus -lsctp -lpthread -lstdc++ -lxml2 -lprotobuf -static

LDADD = ./liblz4.a
#文件列表
fileList = \
		./net/sSctpSocket.cpp \
		./net/sSctpPool.cpp \
		./net/sSctpPthread.cpp \
		./net/sServer.cpp \
		./net/sEpoll.cpp \
		./base/sPthreadPool.cpp \
		./base/sLogManager.cpp \
		./base/XmlFile.cpp \
		./base/sCompress.cpp \
		./third_part/zip/lz4.c \
		 UserTest.cpp 

#动态库
#lib_LIBRARIES = libsdk.a
#libsdk_a_SOURCES = $(fileList)

#静态库
lib_LTLIBRARIES = libsdk.la
libsdk_la_SOURCES = $(fileList)


