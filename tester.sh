#!/bin/bash

PINK='\033[35m'
RED='\033[31m'
RESET='\033[0m'

rm -rf exec
mkdir exec

cc -Wall -Werror -Wextra -g \
	-D BUFFER_SIZE=1 \
	main_mandatory.c \
	get_next_line.c \
	get_next_line_utils.c \
	-o exec/get_next_line

if [ -f exec/get_next_line ]; then
	echo -e "${PINK}Starting tests Mandatory BUFFER_SIZE = 1${RESET}"
	./exec/get_next_line
else
	echo "${RED}Compilation failed  for file get_next_line BUFFER 1.${RESET}"
fi

rm -rf exec
mkdir exec

cc -Wall -Werror -Wextra -g \
	-D BUFFER_SIZE=42 \
	main_mandatory.c \
	get_next_line.c \
	get_next_line_utils.c \
	-o exec/get_next_line

#	echo "Compiling file ${BOLD} ft_printf ${RESET}"
echo -e "\n"
if [ -f exec/get_next_line ]; then
	echo -e "${PINK}Starting tests Mandatory BUFFER_SIZE = 42${RESET}"
	./exec/get_next_line
else
	echo -e "${RED}Compilation failed  for file get_next_line BUFFER 42.\n${RESET}"
fi

rm -rf exec
mkdir exec

cc -Wall -Werror -Wextra -g \
	-D BUFFER_SIZE=1000000 \
	main_mandatory.c \
	get_next_line.c \
	get_next_line_utils.c \
	-o exec/get_next_line

#	echo "Compiling file ${BOLD} ft_printf ${RESET}"
echo -e "\n"
if [ -f exec/get_next_line ]; then
	echo -e "${PINK}Starting tests Mandatory BUFFER_SIZE = 1000000${RESET}"
	./exec/get_next_line
else
	echo -e "${RED}Compilation failed  for file get_next_line BUFFER 1000000.\n${RESET}"
fi

if [ -f get_next_line_bonus.c ]; then

	rm -rf exec
	mkdir exec

	cc -Wall -Werror -Wextra -g \
		-D BUFFER_SIZE=1\
		main_bonus.c \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
		-g -o exec/get_next_line_bonus

	echo -e "\n"
	if [ -f exec/get_next_line_bonus ]; then
		echo -e "${PINK}Starting tests Bonus BUFFER_SIZE = 1${RESET}"
		./exec/get_next_line_bonus
	else
		echo "${RED}Compilation failed  for file get_next_line_bonus.${RESET}"
	fi

	rm -rf exec
	mkdir exec

	cc -Wall -Werror -Wextra -g \
		-D BUFFER_SIZE=42 \
		main_bonus.c \
		get_next_line.c \
		get_next_line_utils.c \
		-o exec/get_next_line

	#	echo "Compiling file ${BOLD} ft_printf ${RESET}"
	echo -e "\n"
	if [ -f exec/get_next_line ]; then
		echo -e "${PINK}Starting tests Bonus BUFFER_SIZE = 42${RESET}"
		./exec/get_next_line
	else
		echo -e "${RED}Compilation failed  for file get_next_line BUFFER 42.\n${RESET}"
	fi

	rm -rf exec
	mkdir exec

	cc -Wall -Werror -Wextra -g \
		-D BUFFER_SIZE=1000000 \
		main_bonus.c \
		get_next_line.c \
		get_next_line_utils.c \
		-o exec/get_next_line

	#	echo "Compiling file ${BOLD} ft_printf ${RESET}"
	echo -e "\n"
	if [ -f exec/get_next_line ]; then
		echo -e "${PINK}Starting tests Bonus BUFFER_SIZE = 1000000${RESET}"
		./exec/get_next_line
	else
		echo -e "${RED}Compilation failed  for file get_next_line BUFFER 1000000.\n${RESET}"
	fi

fi

