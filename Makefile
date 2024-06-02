CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line.c get_next_line_utils.c
BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
NAME  = get_next_line.a

ifdef BONUS_FLAG
	OBJS += $(BONUS_OBJS)
endif

all : $(NAME)
		
$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)	

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
		 
clean:
		rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean 
		rm -f $(NAME)
		
re:  fclean all

bonus:
	make BONUS_FLAG=1

.PHONY: all bonus clean fclean re