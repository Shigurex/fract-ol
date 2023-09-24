CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
MANDATORY_SRCS_NAME = fract_ol.c \
	input.c \
	action.c \
	setup.c \
	mandelbrot.c \
	julia.c \
	burningship.c \
	border.c \
	display.c
BONUS_SRCS_NAME = fract_ol_bonus.c \
	input_bonus.c \
	action_bonus.c \
	setup_bonus.c \
	mandelbrot_bonus.c \
	julia_bonus.c \
	burningship_bonus.c \
	border_bonus.c \
	display_bonus.c
MANDATORY_SRCS = $(addprefix mandatory/, $(MANDATORY_SRCS_NAME))
BONUS_SRCS = $(addprefix bonus/, $(BONUS_SRCS_NAME))
MANDATORY_OBJS = $(MANDATORY_SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)
NAME = fract_ol

ifdef BONUS
	OBJS = $(BONUS_OBJS)
else
	OBJS = $(MANDATORY_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx-linux
	$(CC) $(OBJS) libft/libft.a $(LDFLAGS) ./minilibx-linux/libmlx_Darwin.a -o $(NAME)

clean:
	$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS)
	make clean -C ./minilibx-linux
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus:
	make BONUS=1 all

.PHONY: make clean fclean re bonus
