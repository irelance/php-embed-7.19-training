PHP_ARG_ENABLE(hello, whether to enable hello support,
Make sure that the comment is aligned:
[  --enable-hello           Enable hello support])

if test "$PHP_HELLO" != "no"; then
  PHP_NEW_EXTENSION(hello, hello.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
