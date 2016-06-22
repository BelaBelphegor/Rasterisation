# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/07 01:27:33 by tiboitel          #+#    #+#              #
#    Updated: 2016/06/22 02:14:35 by tiboitel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		 =	rasterisation
SRCS 		 = 	main.c \
				color.c \
				vertex.c \
				vector.c
INCLUDES	 =	./includes
SRCSPATH 	 =	./srcs/
LIBFTPATH 	 =  ./libft/
LIBFTINC 	 =  ./libft/includes

CC			 = gcc
CFLAGS		 = -Wall -Werror -Wextra -Ofast
INCLUDES_O	 = -I $(LIBFTINC) -I $(INCLUDES)
INCLUDES_C	 = -L $(LIBFTPATH) -lft

SRC			 = $(addprefix $(SRCSPATH), $(SRCS))
OBJS		 = $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(INCLUDES_C)

%.o: %.c libft/libft.a
			$(CC) -o $@ $(CFLAGS) $(INCLUDES_O) -c $<

libft/libft.a:
			make -C $(LIBFTPATH)

clean:
			make -C $(LIBFTPATH) clean
			rm -rf $(OBJS)

fclean: 	clean
			make -C $(LIBFTPATH) fclean
			rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
			
