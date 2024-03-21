NAME = libft.a

SRCS = \
	ft_strlen.c \
	ft_memset.c \
	ft_strlcpy.c \
	ft_strchr.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_substr.c \
	ft_strtrim.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -MMD -MP

ARFLAGS = rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)
