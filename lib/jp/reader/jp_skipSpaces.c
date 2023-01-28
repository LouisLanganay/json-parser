/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_skipSpaces
*/

#include "../jp.h"

void jp_skipSpaces(char **str)
{
    for (; (**str == ' ' || **str == '\t' || **str == '\n') &&
        **str; *str += 1);
}
