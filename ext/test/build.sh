#!/usr/bin/env bash
root_path=../..

gcc -c test.c -o test.o -I${root_path}/include/ -I${root_path}/include/main -I${root_path}/include/Zend -I${root_path}/include/TSRM

