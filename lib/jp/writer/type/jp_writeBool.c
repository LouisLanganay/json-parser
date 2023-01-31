/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_writeBool
*/

#include "../../jp.h"

void jp_writeBool(int fd, bool_t value)
{
    if (value == b_true)
        jp_writeStr(fd, "true");
    else if (value == b_false)
        jp_writeStr(fd, "false");
}
