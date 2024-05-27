CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line.c
OBJS = $(SRCS:.c=.o)
NAME  = get_next_line.a

all : $(NAME)
		
$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)	

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
		 
clean:
		rm -f $(OBJS)

fclean: clean 
		rm -f $(NAME)
		
re:  fclean all

.PHONY: all clean fclean re