
CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror -W

LDFLAG	=

NAME	= epikong

SRCS	= src/display.c \
	  src/parser.c \
	  src/main.c

OBJS	= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lSDL -lSDLmain -lSDL_image

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
