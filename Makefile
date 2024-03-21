NAME = cub3D

SRCS_COMMON = \
	main.c \
	parse/parse.c \
	parse/map_parse.c \
	parse/make_path.c \
	parse/make_color.c \
	parse/texture_parse.c \
	parse/check.c \
	parse/free.c \
	parse/utils.c \
	parse/get_next_line.c \
	parse/get_next_line_utils.c \
	init.c \
	init_from_info.c \
	texture.c \
	color.c \
	vec.c \
	vec_utils.c \
	math_utils.c \
	draw.c \
	draw_column.c \
	raycast.c \
	raycast_utils.c \
	hooks.c \

SRCS_MANDATORY = \
	move.c \
	draw_minimap.c \
	mouse_hook.c \

SRCS_BONUS = \
	move_bonus.c \
	draw_minimap_bonus.c \
	draw_minimap_view_field_bonus.c \
	mouse_hook_bonus.c \

SRCS = $(SRCS_COMMON) $(if $(filter bonus, $(MAKECMDGOALS)), $(SRCS_BONUS), $(SRCS_MANDATORY))
OBJS = $(SRCS:.c=.o)

SRCS_ALL = $(SRCS_COMMON) $(SRCS_MANDATORY) $(SRCS_BONUS)
OBJS_ALL = $(SRCS_ALL:.c=.o)
DEPS_ALL = $(SRCS_ALL:.c=.d)

LIBMLX_DIR = libmlx
LIBMLX_NAME = libmlx.dylib
LIBMLX_FLAGS = -L $(LIBMLX_DIR) -lmlx -framework Metal -framework Metalkit

LIBFT_DIR = libft
LIBFT_NAME = libft.a
LIBFT_FLAGS = -L $(LIBFT_DIR) -lft

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -MMD -MP
CFLAGS += -I $(LIBMLX_DIR)
CFLAGS += -I $(LIBFT_DIR)
CFLAGS += -I .
CFLAGS += -I parse
CFLAGS += -O3

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBMLX_DIR) $(LIBMLX_NAME)
	cp $(LIBMLX_DIR)/$(LIBMLX_NAME) .
	make -C $(LIBFT_DIR) $(LIBFT_NAME)
	$(CC) $(CFLAGS) -lm $(LIBMLX_FLAGS) $(LIBFT_FLAGS) -o $@ $^

bonus: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBMLX_DIR) $@
	make -C $(LIBFT_DIR) $@
	$(RM) $(OBJS_ALL) $(DEPS_ALL)

fclean: clean
	$(RM) $(LIBMLX_NAME)
	$(RM) $(LIBFT_DIR)/$(LIBFT_NAME)
	$(RM) $(NAME)

re: fclean all

-include $(DEPS_ALL)
