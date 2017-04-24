AUTOMAKE_OPTIONS=foreign
CXX := clang++
#CXXFLAGS +=-llog4cplus -lsctp -lpthread
LIBS = -llog4cplus -lsctp -lpthread -lstdc++ -lxml2 -lprotobuf -static

LDADD = ./liblz4.a
#文件列表
fileList = \
		sSctpScoket.cpp \
		sPthreadPool.cpp \
		sEpoll.cpp \
		sSctpPool.cpp \
		UserTest.cpp \
		sSctpPthread.cpp \
		sLogManager.cpp \
		XmlFile.cpp \
		sTask.cpp \
		net/sServer.cpp \
		lz4.c \
		sCompress.cpp


#动态库
#lib_LIBRARIES = libsdk.a
#libsdk_a_SOURCES = $(fileList)

#静态库
lib_LTLIBRARIES = libsdk.la
libsdk_la_SOURCES = $(fileList)


