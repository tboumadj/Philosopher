# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 20:55:08 by tboumadj@student  #+#    #+#              #
#    Updated: 2022/11/06 18:37:00 by tboumadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#FLAG
NAME 	=	philo
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
CHECK	=	-fsanitize=address

#PATH
HEADER	=	philo.h

SRCS	=	main.c \
		error.c \
		utils.c \
		check.c \
		init.c \
		thread.c

OBJS	=	$(SRCS:.c=.o)

#COLORS
_RED    =   $'\x1b[31m
_GREEN  =   $'\x1b[32m

##
.o : .c $(HEADER) Makefile
		@$(CC) $(FLAGS) -c $< -o $(<:c=o) $@

$(NAME): $(OBJS)
		@echo "$(_RED)Compilation de Pipex en cours...$(_END)"
		$(CC) $(OBJS) $(FLAGS) -lpthread -o $(NAME) $(CHECK)
		@echo "$(_GREEN)$(_BOLD)Fin de la compilation!$(_END)"

.SILENT : $(OBJS) $(NAME)

all     :   $(NAME)

clean   :
			@$(RM) $(OBJS)

fclean  :	clean
			@$(RM) $(NAME)
			@echo "$(_GREEN)$(_BOLD)Exec & .o have been erased!$(_END)"

re      :   fclean all

.PHONY  :   all clean fclean re