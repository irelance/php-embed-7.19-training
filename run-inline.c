#include "php_embed.h"

int main(int argc, char * argv[]){
    PHP_EMBED_START_BLOCK(argc,argv);
    char * script = " var_dump($_GLOBALS);";
    zend_eval_string(script, NULL,
                                      "Simple Hello World App" TSRMLS_CC);
    PHP_EMBED_END_BLOCK();
    return 0;
}
