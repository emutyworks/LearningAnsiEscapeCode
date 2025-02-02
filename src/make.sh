#!/bin/sh
gcc main.c -o test
res=$?

if [ $res = 0 ]; then
  ./test
fi
