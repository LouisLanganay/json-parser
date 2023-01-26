/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** json_parser_int
*/

#include "../jp.h"

void json_parser_int(char **str, parsed_data_t *data)
{
    int nb = my_getnbr(*str);
    
    for (; **str == '-' || (**str >= '0' && **str <= '9'); *str += 1);

    data->type = p_int;
    data->value.p_int = nb;
}