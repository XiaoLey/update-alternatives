//
// Created by XiaoLey on 2022-07-25.
//

#include "parse_arg_list.h"

#include <stdlib.h>
#include <string.h>

ArgItem *ua_newArgItem()
{
    ArgItem *item = (ArgItem *)calloc(1, sizeof(ArgItem));
    return item;
}


void ua_deleteArgItem(ArgItem *item)
{
    if (item->arg) {
        free(item->arg);
        item->arg = NULL;
    }

    if (item->values) {
        size_t szValues = ((size_t *)item->values)[-1];
        for (size_t i = 0; i < szValues; ++i) {
            free(item->values[i]);
        }

        free(((size_t *)item->values) - 1);
    }

    free(item);
}


void ua_setArgSign(ArgItem *item, const char *sign)
{
    if (item->arg) free(item->arg);
    item->arg = strdup(sign);
}

void ua_setAddValue(ArgItem *item, const char *value)
{
    // TODO: 此处编写添加参数值的逻辑，注意，参数值指针的前方存储了参数值的个数
    if (item->values) {
        size_t szValues = ((size_t *)item->values)[-1];
    }
    else {
    }
}
