/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_writeData_name
*/

#include "../jp.h"

void jp_writeData_name(int fd, parsed_data_t *data, int tab_count)
{
    jp_writeTab(fd, tab_count);
    jp_writeStr(fd, "\"");
    jp_writeStr(fd, data->name);
    jp_writeStr(fd, "\": ");
}
