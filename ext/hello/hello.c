#include "php_hello.h"

ZEND_FUNCTION(hello_echo_world)
{
	php_printf("hello world!\n");
	return;
}
