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
    #include <aio.h>

    typedef struct parsed_data_s parsed_data_t;

    // Structures
    #ifndef _JSON_PARSER_STRUCT_H__
        #define _JSON_PARSER_STRUCT_H__

        typedef enum bool_s {
            b_false,
            b_true
        } bool_t;

        typedef enum type_s {
            p_int,
            p_bool,
            p_str,
            p_obj,
            p_null
        } type_t;
    
        typedef union values_s {
            int p_int;
            double p_float;
            char *p_str;
            bool_t p_bool;
            parsed_data_t *p_obj;
        } values_t;
        
        typedef struct parsed_data_s {
            char *name;
            type_t type;
            values_t value;
            struct parsed_data_s *next;
        } parsed_data_t;

    #endif

    void load_file_in_str(char const *filepath, char **str);
    int my_getnbr(char *str);
    int my_strlen(char const *str);

    void json_parser_white_space(char **str);
    void json_parser_int(char **str, parsed_data_t *data);
    void json_parser_value(char **str, parsed_data_t *data);
    void json_parser_bool(char **str, parsed_data_t *data);
    char *json_parser_string(char **str);

    parsed_data_t *json_parser(char *filepath);
    parsed_data_t *load_array(char **str);
    parsed_data_t *load_object(char **str);


#endif