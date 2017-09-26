#!/usr/bin/env bash

#php7.19
#./configure --enable-embed=static --disable-all
#make
if [[ $1 != "" ]]; then
 file=`basename $1`
 fileName=${file%.*}
 #resolv dns库
 gcc $1 -o ${fileName}.a ./ext/test/test.o -I./include/ -I./include/main -I./include/Zend -I./include/TSRM -L./lib -lphp7 -lresolv
else
 echo "Usage: $1 <path/to/file>"
fi

