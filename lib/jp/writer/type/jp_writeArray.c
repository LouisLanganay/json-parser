/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_writeArray
*/

#include "../../jp.h"

void jp_writeArray(int fd, parsed_data_t *data, int tab_count)
{
    parsed_data_t *tmp = data;
    jp_writeStr(fd, "[\n");
    while (tmp != NULL) {
        jp_writeTab(fd, tab_count);
        jp_writeData_value(fd, tmp, tab_count);
        tmp = tmp->next;
        if (tmp)
            jp_writeStr(fd, ",");
        jp_writeStr(fd, "\n");
    }
    jp_writeTab(fd, tab_count - 1);
    jp_writeStr(fd, "]");
}
