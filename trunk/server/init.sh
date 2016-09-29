#!/bin/sh
#run autoscan
libtoolize --force --copy --automake
aclocal 
autoconf
autoheader
automake --add-missing
#静态库
./configure --enable-shared --disable-static
#动态库
#./configure --disable-shared --enable-static
