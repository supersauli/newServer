#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE
AC_LANG(C++)
# Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
#AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB
AC_PROG_LIBTOOL
# Checks for libraries.
#AC_CHECK_LIB([log4cxx], [main])
#AC_HAVE_LIBRARY(log4cxx,LIBS="${LIBS} -llog4cxx",AC_MSG_ERROR(liblog4cxx not found!))
#CORE_LIBS = -Wl,-Bstatic -L/usr/local/apr/lib -Wl,-Bstatic -L/usr/local/log4cxx/lib -static-llog4cxx -lsctp
#CXXFLAGS="-Wall -g3   -O0 -I/usr/local/apr/include  -I/usr/local/log4cxx/include -L/usr/local/apr/lib -llog4cxx -lsctp "
#CXXFLAGS="-Wall -g3   -O0 -I/usr/local/apr/include  -L/usr/local/apr/lib  -lsctp -lpthread -std=c++11  -L/usr/lib64/ "
CXXFLAGS="-Wall -g3 -O0	-std=c++11 -fPIC"
LDFLAGS="-L/usr/lib64/"
AC_SUBST(CXXFLAGS)
# Checks for header files.
AC_CHECK_HEADERS([sys/time.h unistd.h])
# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([gettimeofday])

AC_CONFIG_FILES([Makefile
                 sdk/Makefile
				 Gate/Makefile
                 test/Makefile
				 ])
AC_OUTPUT
