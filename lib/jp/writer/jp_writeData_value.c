/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_writeData_value
*/

#include "../jp.h"

void jp_writeData_value(int fd, parsed_data_t *data, int tab_count)
{
    if (data->type == p_str) {
        jp_writeStr(fd, "\"");
        jp_writeStr(fd, data->value.p_str);
        jp_writeStr(fd, "\"");
    }
    if (data->type == p_int)
        jp_writeInt(fd, data->value.p_int);
    if (data->type == p_bool)
        jp_writeBool(fd, data->value.p_bool);
    if (data->type == p_obj)
        jp_writeData(fd, data->value.p_obj, tab_count + 1);
    if (data->type == p_arr)
        jp_writeArray(fd, data->value.p_arr, tab_count + 1);
}
