NAME	=	push_swap
NAMEBS  = checker

SRCS	=	everything/*.c push_swap.c

SRCS_BONUS = everything/*.c bonnus/*.c

OBJCT	=	${all:.c=.o}

OBJCTB	=	${all:.c=.o}

RM		=	rm -f

CC		=	gcc -Wall -Wextra -Werror #-g -fsanitize=address

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC)  $(SRCS) -o $(NAME)

clean :
	${RM} ${OBJCT}

fclean : clean
	${RM} ${NAME} ${NAMEBS}

bonus : ${OBJCTB}
	$(CC) $(SRCS_BONUS) -o $(NAMEBS)

re : fclean all