#include <stdio.h>
#include "php_embed.h"
#include "zend_API.h"
#include "zend_compile.h"
#include "ext/test/test.h"

static zend_bool php_auto_globals_create_array(zend_string *name)
{
    zval    type;
    zend_array *symbol_table;
	ZVAL_ARR(&type, symbol_table);
	Z_TYPE_INFO_P(&type) = IS_ARRAY;
	zend_hash_update(&EG(symbol_table), name, &type);
	return 0; /* don't rearm */
}

static zend_bool php_auto_globals_create_string(zend_string *name)
{
    zval    type;
	ZVAL_STRING(&type, "string");
	Z_TYPE_INFO_P(&type) = IS_STRING;
	zend_hash_update(&EG(symbol_table), name, &type);
	return 0; /* don't rearm */
}

int main(int argc, char * argv[]){
    PHP_EMBED_START_BLOCK(argc,argv);
    /*  注册全局变量
    char * key="TEST";
	zend_register_auto_global(zend_string_init(key, sizeof(key) - 1, 1), 1, php_auto_globals_create_string);
	*/
	/*  注册扩展
    zend_startup_module(&walu_module_entry);
	*/
	/*  禁止函数
    char * disableFunctionName="strlen";
    zend_disable_function(disableFunctionName,strlen(disableFunctionName));
	*/
    zend_startup_module(&test_module_entry);
    char * script = "var_dump(get_loaded_extensions());";
    zend_eval_string(script, NULL, "Simple Hello World App" TSRMLS_CC);
    PHP_EMBED_END_BLOCK();
    return 0;
}
