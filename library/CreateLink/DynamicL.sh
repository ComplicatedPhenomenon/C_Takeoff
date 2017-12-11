#!/bin/sh
gcc -rdynamic -o progdl progdl.c -ldl
./progdl
rm  progdl
