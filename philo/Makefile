# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 20:55:08 by tboumadj@student  #+#    #+#              #
#    Updated: 2022/10/29 21:33:04 by tboumadj@student ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#FLAG
NAME 	=	philo
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -g
RM		=	rm -f
CHECK	=	-fsanitize=address

#PATH
HEADER	=	philo.h

SRCS	=	main.c \
		error.c \
		utils.c

OBJS	=	$(SRCS:.c=.o)

#COLORS
_RED    =   $'\x1b[31m
_GREEN  =   $'\x1b[32m

##
.o : .c $(HEADER) Makefile
		@$(CC) $(FLAGS) -c $< -o $(<:c=o) $@

$(NAME): $(OBJS)
		@echo "$(_RED)Compilation de Pipex en cours...$(_END)"
		$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(CHECK)
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