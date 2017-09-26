#ifndef PHP_HELLO_H
#define PHP_HELLO_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

extern zend_module_entry hello_module_entry;
#define phpext_hello_ptr &hello_module_entry

#define PHP_HELLO_MODULE_NAME   "hello"
#define PHP_HELLO_BUILD_DATE    __DATE__ " " __TIME__
#define PHP_HELLO_VERSION       "1.0.0"
#define PHP_HELLO_AUTHOR        ""
#define PHP_HELLO_HOMEPAGE      ""

ZEND_MINIT_FUNCTION(hello);
ZEND_MSHUTDOWN_FUNCTION(hello);
ZEND_MINFO_FUNCTION(hello);

/* declaration of functions to be exported */
ZEND_FUNCTION(hello_echo_world);

#endif /* ifndef PHP_HELLO_H */
