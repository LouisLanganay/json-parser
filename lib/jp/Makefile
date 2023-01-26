##
## EPITECH PROJECT, 2023
## json-parser
## File description:
## Makefile
##

include Makefile_colors.mk

NAME = libjp.a


VPATH := reader
VPATH += reader/utils
VPATH += reader/loaders

vpath %.c $(VPATH)

SRC := main_reader.c
SRC += my_strlen.c
SRC += load_file_in_str.c
SRC += json_parser_white_space.c
SRC += json_parser_string.c
SRC += json_parser_int.c
SRC += json_parser_value.c
SRC += json_parser_bool.c
SRC += load_array.c
SRC += load_object.c
SRC += my_getnbr.c


INC_DIR := ../../includes
INC_NAME := jp.h
BUILD_DIR = build
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)
	@ echo -e "${_B_GREEN}[SUCCES]${_END} Compilation done"

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(@D)
	@ $(CC) -g $(LIBFLAGS) -c $< -o $@
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(CC)    $<${_END}"

$(NAME): $(OBJ) $(SRC)
	@ mkdir -p $(BUILD_DIR)
	@ ar rc $(NAME) $(OBJ)
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(AR)    $(NAME)${_END}"
	@ cp ${INC_NAME} ${INC_DIR}
	@ echo -e "${_BLACK}${_BB_WHITE}-> cp      ${INC_NAME} ${INC_DIR}${_END}"

clean:
	@ $(RM) *.gcda
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(RM)    *.gcda${_END}"
	@ $(RM) *.gcno
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(RM)    *.gcno${_END}"
	@ $(RM)	$(OBJ)
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(RM)    $(OBJ)${_END}"
	@ echo -e "${_B_RED}[CLEAN]${_END} Clean done"

fclean: clean
	@ $(RM) -r $(BUILD_DIR)
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(RM)    $(BUILD_DIR)${_END}"
	@ $(RM)	$(NAME)
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(RM)    $(NAME)${_END}"
	@ echo -e "${_B_RED}[FCLEAN]${_END} Fclean done"

re: fclean all

.PHONY: clean fclean re