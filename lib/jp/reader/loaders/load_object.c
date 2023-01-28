/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** load_object
*/

#include "../../jp.h"

parsed_data_t *load_object(char **str)
{
    parsed_data_t *data = malloc(sizeof(parsed_data_t));
    parsed_data_t *tmp = data;

    if (**str == '{')
        *str += 1;

    for (; **str; *str += (**str == ',')) {
        data->next = NULL;
        jp_skipSpaces(str);
        if (**str == '}') {
            data->type = p_null;
            break;
        }
        data->name = jp_getValue_string(str);
        jp_skipSpaces(str);
        for (; **str && **str != ':'; *str += 1);
        jp_getValue(str, data);
        if (**str == '}')
            break;
        data->next = malloc(sizeof(parsed_data_t));
        data = data->next;
    }
    *str += (**str == '}');
    return (tmp);
}
