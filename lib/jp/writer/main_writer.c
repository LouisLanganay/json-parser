/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** main_writer
*/

#include "../jp.h"

void json_writer(char *filepath, parsed_data_t *data)
{
    FILE *file = fopen(filepath, "w");
    write_object(file, data);
    fclose(file);
}