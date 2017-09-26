#include <stdio.h>
#include <string.h>
#include "php_embed.h"

static char *zend_file_cache_get_bin_file_path(zend_string *script_path);

int main(int argc, char * argv[]){
    /* 基本的参数检查 */
    if ( argc <= 1 ) {
        fprintf(stderr, "Usage: %s <src> <dist>\n", argv[0]);
        return -1;
    }
    PHP_EMBED_START_BLOCK(argc,argv);
    file_handle.filename = argv[1];
    file_handle.free_filename = 0;
    file_handle.type = ZEND_HANDLE_FILENAME;
    file_handle.opened_path = NULL;
    zend_op_array *op_array;
    op_array =  zend_compile_file(&file_handle, ZEND_INCLUDE TSRMLS_CC);
    if(!op_array) {
        printf("Error parsing script: %s\n", file_handle.filename);
        return 1;
    }
    PHP_EMBED_END_BLOCK();
    return 0;
}
