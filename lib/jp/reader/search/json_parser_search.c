/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** json_parser_search
*/

#include "../../jp.h"

#include <string.h>

parsed_data_t *json_parser_search(parsed_data_t *data, char *name)
{
    parsed_data_t *tmp = data;

    while (tmp) {
        if (tmp->name && strcmp(tmp->name, name) == 0)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}
