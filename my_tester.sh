#!/bin/bash

BOLD=$(tput bold)
RESET=$(tput sgr0)

rm -rf exec
mkdir exec

cc -Wall -Werror -Wextra -g \
	-D BUFFER_SIZE=42 \
	main.c \
	get_next_line.c \
	get_next_line_utils.c \
	-g -o exec/get_next_line

#	echo "Compiling file ${BOLD} ft_printf ${RESET}"
if [ -f exec/get_next_line ]; then
	echo "Compilation successful for file ft_printf. Starting tests"
	./exec/get_next_line
else
	echo "Compilation failed  for file ft_printf."
fi
