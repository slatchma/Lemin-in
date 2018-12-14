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

NAME = libft.a
CC = gcc -Wall -Wextra -Werror -g
FILES = ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_itoa ft_lstaffich ft_lstcompt ft_lstend ft_lstfirst ft_lstnsearch ft_lstsearch ft_lstsupdel ft_memalloc ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel ft_memmove ft_memset ft_putchar_fd ft_putchar ft_putendl_fd ft_putendl ft_putnbr_fd ft_putnbr ft_putstr_fd ft_putstr ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel ft_strdup ft_strequ ft_striter ft_striteri ft_strjoin ft_strlcat ft_strlen ft_strmap ft_strsupchr ft_strmapi ft_strncat ft_strncmp ft_strncpy ft_strnequ ft_strnew ft_strnstr ft_strrchr ft_strsplit ft_strstr ft_strsub ft_strtrim ft_tolower ft_toupper get_next_line ft_printf printf_putwchar printf_parsing printf_other printf_type_s ft_itoa_base printf_other_s printf_type_p printf_type_d printf_type_o printf_type_u printf_type_x printf_type_c printf_type_m printf_type_not printf_type_ws printf_type_wc ft_strndup
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
