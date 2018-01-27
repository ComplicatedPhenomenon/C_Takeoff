#!/bin/bash

# compile the lib file and make the .so

cc -c libex29.c -o libex29.o
cc -shared -o libex29.so libex29.o

cc -Wall -g -DNDEBUG ex29.c -ldl -o ex29

ex29 ./libex29.so print_a_message "hello there"
./ex29 ./libex29.so print_a_message "hello there"

./ex29 ./libex29.so uppercase "hello there"
./ex29 ./libex29.so lowercase "HELLO tHeRe"

./ex29 ./libex29.so fail_on_purpose "i fail"

# try to give bad args
./ex29 ./libex29.so asfasfasdf asdfadff

# try loading a .so that is not there

./ex29 ./libex.so asfasfasdf asdfadff

rm *.so *.o ex29
