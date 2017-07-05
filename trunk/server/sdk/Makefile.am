AUTOMAKE_OPTIONS=foreign
CXX := clang++
#CXX := g++
#CXXFLAGS +=-llog4cplus -lsctp -lpthread
LIBS = -llog4cplus -lsctp -lpthread -lstdc++ -lxml2 -lprotobuf -static

#文件列表
fileList = \
		./net/sSctpSocket.cpp \
		./net/sSctpPool.cpp \
		./net/sSctpPthread.cpp \
		./net/sServer.cpp \
		./net/sEpoll.cpp \
		./net/ServerSocket.cpp \
		./base/sPthreadPool.cpp \
		./base/LogManager.cpp \
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


