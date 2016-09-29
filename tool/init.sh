#clang++  main.cpp -o run --std=gnu++11 -g -I /usr/local/log4cplus/include/ -L /usr/local/lib -llog4cplus
clang++  main.cpp -o run   -g -I /usr/local/log4cplus/include/ -L /usr/local/lib/liblog4cplus-1.2.so.5 -llog4cplus -lpthread --std=gnu++11
