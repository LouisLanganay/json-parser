##
## EPITECH PROJECT, 2023
## json-parser
## File description:
## Makefile
##

NAME = unit_tests

TESTS_FILES := main.c

LIB_DIR := ../lib/jp
LIB_NAME := jp

INC_DIR := ../includes
FLAGS = --coverage -lcriterion -I${INC_DIR} -L${LIB_DIR} -l${LIB_NAME}

all: $(NAME) clean
	@ echo "Compilation done"
	

$(NAME): $(SRC)
	@ make -C ../lib/jp
	@ echo ${SRC} ${TESTS_FILES}
	@ gcc -o ${NAME} ${SRC} ${TESTS_FILES} ${FLAGS}

run_tests: $(NAME)
	@ mkdir -p ../includes
	@ ./$(NAME)
	@ gcovr --xml > coverage.xml
	
clean:
	@ $(RM) *.gcda
	@ $(RM) *.gcno
	@ $(RM)	$(OBJ)

fclean: clean
	@ $(RM) -r $(BUILD_DIR)
	@ $(RM)	$(NAME)
	@ $(RM) coverage.xml

re: fclean all

.PHONY: clean fclean re