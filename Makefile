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

EXEC = lem-in
CC = gcc -Wall -Wextra -Werror -g

all :
	make -C libft/
	make -C lemin/
	$(CC) lemin/lemin.a libft/libft.a -o $(EXEC)

clean :
	make -C libft/ clean
	make -C lemin/ clean

fclean : clean
	make -C libft/ fclean
	make -C lemin/ fclean
	rm -f $(EXEC)

re : fclean all
