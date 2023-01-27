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
        json_parser_white_space(str);
        if (**str == '}') {
            data->type = p_null;
            break;
        }
        data->name = json_parser_string(str);
        printf("Data_Name:\t %s\n", data->name);
        json_parser_white_space(str);
        for (; **str && **str != ':'; *str += 1);
        json_parser_value(str, data);
        if (data->type == p_str)
            printf("Data_Value:\t %s\n", data->value.p_str);
        else if (data->type == p_int)
            printf("Data_Value:\t %d\n", data->value.p_int);
        else if (data->type == p_bool)
            printf("Data_Value:\t %d\n", data->value.p_bool);
        printf("\n");
        if (**str == '}')
            break;
        data->next = malloc(sizeof(parsed_data_t));
        data = data->next;
    }
    *str += (**str == '}');
    return (tmp);
}
