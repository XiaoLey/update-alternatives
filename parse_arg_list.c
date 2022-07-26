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
        size_t szValues = us_getArgValueSize(item);
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

bool ua_addArgValue(ArgItem *item, const char *value)
{
    if (item->values) {
        size_t szValues = us_getArgValueSize(item) + 1;
        char **ptr      = (char **)((size_t *)item->values - 1);

        ptr = realloc(ptr, sizeof(size_t) + sizeof(char *) * szValues);
        if (!ptr) return false;

        item->values               = ptr;
        *(size_t *)(item->values)  = szValues;
        item->values               = (char **)((size_t *)item->values + 1);
        item->values[szValues - 1] = strdup(value);
        return true;
    }
    else {
        item->values = (char **)calloc(1, sizeof(size_t) + sizeof(char *));
        if (!item->values) return false;

        *(size_t *)(item->values) = 1;
        item->values              = (char **)((size_t *)item->values + 1);
        item->values[0]           = strdup(value);
        return true;
    }
}


inline size_t us_getArgValueSize(const ArgItem *item)
{
    return ((size_t *)item->values)[-1];
}
