NAME = fractal
CC = gcc
CFLAGS = 
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
LIBS = -lX11 -lXext -lm 

SRCS = 	main.c \
	initializes.c \
	str_utils.c \
	vangogh.c \
   calculate.c \
   
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBS)

clean:
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(MLX_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
