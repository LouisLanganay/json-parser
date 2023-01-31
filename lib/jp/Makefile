##
## EPITECH PROJECT, 2023
## json-parser
## File description:
## Makefile
##

include Makefile_colors.mk

NAME = libjp.a


VPATH := reader
VPATH += utils
VPATH += writer
VPATH += writer/type
VPATH += reader/loaders
VPATH += reader/search
VPATH += reader/getValue

vpath %.c $(VPATH)

SRC := main_reader.c
SRC += my_strlen.c
SRC += my_nbrlen.c
SRC += load_file_in_str.c
SRC += jp_skipSpaces.c
SRC += jp_getValue_string.c
SRC += jp_getValue_int.c
SRC += jp_getValue.c
SRC += jp_getValue_bool.c
SRC += jp_search.c
SRC += load_array.c
SRC += load_object.c
SRC += my_getnbr.c
SRC += main_writer.c
SRC += jp_writeStr.c
SRC += jp_writeData.c
SRC += jp_writeData_name.c
SRC += jp_writeData_value.c
SRC += jp_writeInt.c
SRC += jp_writeBool.c
SRC += jp_writeTab.c
SRC += jp_writeArray.c


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