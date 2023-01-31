/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_writeStr
*/

#include "../../jp.h"

void jp_writeStr(int fd, char *str)
{
    write(fd, str, my_strlen(str));
}
