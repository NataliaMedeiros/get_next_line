#!/bin/bash

BOLD=$(tput bold)
RESET=$(tput sgr0)

rm -rf exec
mkdir exec

cc -Wall -Werror -Wextra -g \
	-D BUFFER_SIZE=1000000\
	main_bonus.c \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \
	-g -o exec/get_next_line_bonus

#	echo "Compiling file ${BOLD} ft_printf ${RESET}"
if [ -f exec/get_next_line_bonus ]; then
	echo "Compilation successful for file get_next_line_bonus. Starting tests"
	./exec/get_next_line_bonus
else
	echo "Compilation failed  for file get_next_line_bonus."
fi
