/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** load_array
*/

#include "../../jp.h"

parsed_data_t *load_array(char **str)
{
    parsed_data_t *data = malloc(sizeof(parsed_data_t));
    parsed_data_t *tmp = data;

    for (; **str; *str += (**str == ',')) {
        json_parser_value(str, data);
        data->name = NULL;
        json_parser_white_space(str);
        if (**str == ']')
            break;
        data->next = malloc(sizeof(parsed_data_t));
        data = data->next;
    }
    *str += (**str == ']');
    data->next = NULL;
    return (tmp);
}
