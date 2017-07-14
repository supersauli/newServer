AUTOMAKE_OPTIONS=foreign
CXX := clang++
#CXX := g++
#CXXFLAGS +=-llog4cplus -lsctp -lpthread
LIBS = -llog4cplus -lsctp -lpthread -lstdc++ -lxml2 -lprotobuf -static -lzmq

#文件列表
fileList = \
		./base/HelpFunction.cpp \
		./net/SctpSocket.cpp \
		./net/SctpPool.cpp \
		./net/SctpPthread.cpp \
		./net/Server.cpp \
		./net/Epoll.cpp \
		./net/ServerSocket.cpp \
		./base/PthreadPool.cpp \
		./base/LogManager.cpp \
		./base/XmlFile.cpp \
		./base/CompressManage.cpp \
		./base/JsonManager.cpp \
		./third_part/zip/lz4.c \
		./net/ServerSocket.cpp \
		 UserTest.cpp 

#动态库
#lib_LIBRARIES = libsdk.a
#libsdk_a_SOURCES = $(fileList)

#静态库
lib_LTLIBRARIES = libsdk.la
libsdk_la_SOURCES = $(fileList)


