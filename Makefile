NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

MLX_DIR = minilibx-linux

MLX = $(MLX_DIR)/libmlx_Linux.a

LIBS = -lX11 -lXext -lm 

SRCS = src/main.c \
	src/initializes.c \
	src/str_utils.c \
	src/vangogh.c \
   	src/calculate.c \
	src/keyboard.c \
	src/check.c \
   	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBS)

clean:
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re