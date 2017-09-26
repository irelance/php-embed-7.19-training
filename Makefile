CC = gcc
CFLAGS = -I./include/ \
            -I./include/main \
            -I./include/Zend \
            -I./include/TSRM \
            -Wall -g
LDFLAGS = -lstdc++ -L./lib -lphp7 -lresolv
ALL:
	$(CC) -o embed test.c $(CFLAGS) $(LDFLAGS)
