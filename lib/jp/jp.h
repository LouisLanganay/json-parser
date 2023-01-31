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
    #include <unistd.h>
    #include <fcntl.h>

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
            p_arr,
            p_null
        } type_t;
    
        typedef union values_s {
            int p_int;
            double p_float;
            char *p_str;
            bool_t p_bool;
            parsed_data_t *p_arr;
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
    int my_nbrlen(long int nb);
    int my_strlen(char const *str);

    void jp_skipSpaces(char **str);
    void jp_getValue_int(char **str, parsed_data_t *data);
    void jp_getValue(char **str, parsed_data_t *data);
    void jp_getValue_bool(char **str, parsed_data_t *data);
    char *jp_getValue_string(char **str);

    parsed_data_t *load_array(char **str);
    parsed_data_t *load_object(char **str);
    parsed_data_t *json_parser(char *filepath);
    parsed_data_t *jp_search(parsed_data_t *data, char *name);

    void json_writer(char *filepath, parsed_data_t *object);
    void jp_writeData(int fd, parsed_data_t *data, int tab_count);
    void jp_writeStr(int fd, char *str);
    void jp_writeInt(int fd, int nb);
    void jp_writeBool(int fd, bool_t value);
    void jp_writeTab(int fd, int tab_count);
    void jp_writeArray(int fd, parsed_data_t *data, int tab_count);
    void jp_writeData_name(int fd, parsed_data_t *data, int tab_count);
    void jp_writeData_value(int fd, parsed_data_t *data, int tab_count);

#endif
