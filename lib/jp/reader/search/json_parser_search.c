/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** json_parser_search
*/

#include "../../jp.h"

#include <string.h>

static int name_length(char *name)
{
    int i = 0;

    while (name[i] != '.' && name[i] != '\0')
        i++;
    return (i);
}

static char *get_name(char *name)
{
    int i = 0;
    char *tmp = malloc(sizeof(char) * name_length(name));

    while (name[i] != '.' && name[i] != '\0') {
        tmp[i] = name[i];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}

parsed_data_t *json_parser_search(parsed_data_t *data, char *name)
{
    parsed_data_t *tmp = data;
    char *tmp_name = get_name(name);

    while (tmp) {
        if (tmp->name && strcmp(tmp->name, tmp_name) == 0)
            if (name[name_length(name)] == '\0')
                return (tmp);
            else
                return (json_parser_search(tmp->value.p_obj, name + name_length(name) + 1));
        tmp = tmp->next;
    }
    return (NULL);
}
