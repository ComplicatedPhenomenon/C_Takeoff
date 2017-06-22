cc -Wall -g -DNDEBUG -c -o ex22.o ex22.c
cc -Wall -g -DNDEBUG  ex22_main.c ex22.o -o ex22_main
./ex22_main

# build these two files manually instead of using `MAKEFILE`, so you can see how the files are being putting together by the compiler
