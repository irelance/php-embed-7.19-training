#include <stdio.h>
#include "php_embed.h"

int main(int argc, char *argv[]) {
    zend_file_handle script;
    /* 基本的参数检查 */
    if ( argc <= 1 ) {
        fprintf(stderr, "Usage: %s <filename.php> <arguments>\n", argv[0]);
        return -1;
    }
    /* 设置⼀一个文件处理结构 */
    script.type=ZEND_HANDLE_FP;
    script.filename=argv[1];
    script.opened_path=NULL;
    script.free_filename=0;
    if (!(script.handle.fp = fopen(script.filename, "rb")) ) {
        fprintf(stderr, "Unable to open: %s\n", script.filename);
        return -1;
    }
    /* 在将命令行参数注册给php时(php中的$argv/$argc), 忽略第一个命令行参数, 因为它对php脚本无意义 */
    argc --;
    argv ++;
    PHP_EMBED_START_BLOCK(argc, argv)
        php_execute_script(&script TSRMLS_CC);
    PHP_EMBED_END_BLOCK()
    return 0;
}
