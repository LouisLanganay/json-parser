/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** json_parser_white_space
*/

#include "../jp.h"

void json_parser_white_space(char **str)
{
    for (; (**str == ' ' || **str == '\t' || **str == '\n') &&
        **str; *str += 1);
}
