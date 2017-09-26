#include "test.h"
#include "zend_API.h"

ZEND_FUNCTION(test_hello)
{
    php_printf("Hello World!\n");
}

static zend_function_entry test_functions[] = {
    ZEND_FE(test_hello,        NULL)
    { NULL, NULL, NULL }
};

zend_module_entry test_module_entry = {
    STANDARD_MODULE_HEADER,
    "test", //这个地方是扩展名称，往往我们会在这个地方使用一个宏。
    test_functions, /* Functions */
    NULL, /* MINIT */
    NULL, /* MSHUTDOWN */
    NULL, /* RINIT */
    NULL, /* RSHUTDOWN */
    NULL, /* MINFO */
    "1.0", //这个地方是我们扩展的版本
    STANDARD_MODULE_PROPERTIES
};
