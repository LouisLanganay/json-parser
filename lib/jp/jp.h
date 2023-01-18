/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** json_parser
*/

#ifndef _JSON_PARSER_H__
    #define _JSON_PARSER_H__

    #include <stdio.h>
    #include <stdlib.h>

    typedef struct item_s {
        char *name;
        int id;
    } item_t;

    typedef struct inventory_s {
        item_t *items;
        int size;
    } inventory_t;

    typedef struct player_s {
        inventory_t *inventory;
    } player_t;

    typedef struct parsed_data_s {
        char *name;
        void *data;
    } parsed_data_t;

#endif
