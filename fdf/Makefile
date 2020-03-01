# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhobert <hhobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 10:05:27 by hhobert           #+#    #+#              #
#    Updated: 2020/01/29 22:42:59 by lulee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CFILE = main.c drawing.c error_and_key_part.c init_coord.c keyboard.c read_file_and_color_init.c calc_part1.c calc_part2.c brezenzem.c
OFILE = main.o drawing.o error_and_key_part.o init_coord.o keyboard.o read_file_and_color_init.o calc_part1.o calc_part2.o brezenzem.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -c $(CFILE)
	gcc $(FLAGS) -o $(NAME) $(OFILE) -L"libft" -lft -lmlx -framework OpenGL -framework AppKit
	
clean:
	make -C libft/ clean
	rm -f $(OFILE)

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
