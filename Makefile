CC          = cc
FLAGS       = -Wall -Wextra -Werror

NAME        = libftprintf.a

BUILD_DIR   = .build

INCLUDES_DIR = ./includes
INCLUDES_FILES = ft_printf.h \
INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(INCLUDES_FILES))

SRCS_DIR    = srcs
SRCS_FILES  = ft_printf.c \
			ft_strlen.c \
			put/ft_putchar_fd.c \
			put/ft_putendl_fd.c \
			put/ft_putnbr_base_fd.c \
			put/ft_putstr_fd.c \
			put/ft_putull_base_fd.c \
			callbacks/ft_print_char.c \
			callbacks/ft_print_hex_upper.c \
			callbacks/ft_print_hex.c \
			callbacks/ft_print_int.c \
			callbacks/ft_print_percent.c \
			callbacks/ft_print_pointer.c \
			callbacks/ft_print_string.c \
			callbacks/ft_print_unsigned_int.c \

SRCS        = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS        = $(patsubst $(SRCS_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)


$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES) Makefile
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDES_DIR)

all: $(NAME)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
