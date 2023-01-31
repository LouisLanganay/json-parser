/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_writeTab
*/

#include "../jp.h"

void jp_writeTab(int fd, int tab_count)
{
    for (int i = 0; i < tab_count; i++)
        jp_writeStr(fd, "\t");
}
