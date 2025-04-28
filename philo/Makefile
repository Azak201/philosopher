SRCS = srcs/checks.c  srcs/create_thr.c	srcs/main.c

OBJ = $(SRCS:srcs/%.c=obj/%.o)

CC = cc 
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./include 
NAME = philo

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $^  $(LIB_L) -o $@

obj/%.o : srcs/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) $(INCLUDE) $(INC2) -c $< -o $@

clean :
	rm -f $(OBJ)
	rm -rf obj
	echo "Cleaned"

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re 