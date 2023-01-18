/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** main_reader
*/

#include "jp.h"

parsed_data_t json_parse_line(char *line, char *type)
{
    parsed_data_t *parsed_data = malloc(sizeof(parsed_data_t));
    char *name = malloc(sizeof(char) * 100);
    char *data = malloc(sizeof(char) * 100);
    int i = 0;
    int j = 0;

    for (i = 0; line[i] != ':'; i++);
    for (i = i + 2; line[i] != '"'; i++, j++)
        name[j] = line[i];
    name[j] = '\0';
    for (i = i + 2; line[i] != '"'; i++, j++)
        data[j] = line[i];
    data[j] = '\0';
    parsed_data->name = name;
    parsed_data->data = data;
    return parsed_data;
}

parsed_data_t *json_parse_file(char *file_path, char *type)
{
    FILE *file = fopen(file_path, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    parsed_data_t *parsed_data = malloc(sizeof(parsed_data_t));

    if (file == NULL)
        return NULL;
    while ((read = getline(&line, &len, file)) != -1) {
        if (line[0] == '{') {
            parsed_data = json_parse_line(line, type);
        }
    }
    fclose(file);
    if (line)
        free(line);
    return parsed_data;
}