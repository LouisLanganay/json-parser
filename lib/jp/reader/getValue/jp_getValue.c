/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_getValue
*/

#include "../../jp.h"

void jp_getValue(char **str, parsed_data_t *data)
{
    *str += 1;
    jp_skipSpaces(str);
    if (**str == '{') {
        *str += 1;
        data->type = p_obj;
        data->value.p_obj = load_object(str);
        return;
    }
    if (**str == '[') {
        data->type = p_arr;
        data->value.p_arr = load_array(str);
        return;
    }
    if (**str == '"') {
        data->type = p_str;
        data->value.p_str = jp_getValue_string(str);
        return;
    }
    if (**str >= '0' && **str <= '9') {
        jp_getValue_int(str, data);
        return;
    }
    if (**str == 't' || **str == 'f') {
        jp_getValue_bool(str, data);
        return;
    }
    jp_skipSpaces(str);
}
