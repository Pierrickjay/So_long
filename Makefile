CC=clang
CFLAGS=-Wall -Werror -Wextra -g3
INCLUDE=-Lminilibx-linux -lmlx_Linux -lXext -lX11 -I minilibx-linux ft_printf/libftprintf.a
SRC=main.c \
	hook_check.c \
	sprites.c \
	init_game.c \
	the_moove.c \
	make_moove.c \
	free.c \
	pathing/get_next_line_bonus.c \
	pathing/get_next_line_utils_bonus.c \
	pathing/check_map.c \
	pathing/check_map_2.c \
	pathing/ft_split.c \
	pathing/create_map.c \


OBJ=$(SRC:%.c=build/%.o)

NAME=so_long

all : $(NAME)

.PHONY: all

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(INCLUDE) -o $(NAME)

build/%.o : %.c
		make -C ./ft_printf
		mkdir -p build
		mkdir -p build/pathing
		$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf build
	rm -rf ft_printf/build

.PHONY: clean

fclean : clean
	rm -f $(NAME)

.PHONY: fclean

re : fclean all

.PHONY: re
