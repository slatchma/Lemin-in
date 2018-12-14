# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/16 15:32:25 by slatchma     #+#   ##    ##    #+#        #
#    Updated: 2018/04/23 16:56:06 by slatchma    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = lemin.a
CC = gcc -Wall -Wextra -Werror -g
FILES =	main			\
		error			\
		parsing			\
		room_parsing	\
		link_parsing	\
		lstroom			\
		lstlink			\
		backtracking	\
		treatment		\
		searchcomb		\
		wayunic			\
		other			\
		display			\
		print_ant		\
		initialize		\
		particular
FILESC = $(addsuffix .c, $(FILES))
FILESO = $(addsuffix .o, $(FILES))

all : $(NAME)

$(NAME) : $(FILESO)
	ar rc $(NAME) $(FILESO)
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $?

clean :
	/bin/rm -f $(FILESO)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
