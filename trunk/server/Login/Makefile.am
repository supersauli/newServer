AUTOMAKE_OPTIONS=foreign
CXX := clang++
CPPFLAGS+=-I ../sdk/  -I ../proto/
bin_PROGRAMS= LoginServer
LoginServer_SOURCES = LoginServer.cpp \
				ZoneManage.cpp \
				LoginMessage.cpp
LoginServer_LDADD = ../sdk/libsdk.la ../proto/libprotocol.la
