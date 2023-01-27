/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** json_parser_value
*/

#include "../jp.h"

void json_parser_value(char **str, parsed_data_t *data)
{
    *str += 1;
    json_parser_white_space(str);
    if (**str == '{') {
        *str += 1;
        data->type = p_obj;
        data->value.p_obj = load_object(str);
        return;
    }
    if (**str == '[') {
        data->type = p_obj;
        data->value.p_obj = load_array(str);
        return;
    }
    if (**str == '"') {
        data->type = p_str;
        data->value.p_str = json_parser_string(str);
        return;
    }
    if (**str >= '0' && **str <= '9') {
        json_parser_int(str, data);
        return;
    }
    if (**str == 't' || **str == 'f') {
        json_parser_bool(str, data);
        return;
    }
    json_parser_white_space(str);
}
