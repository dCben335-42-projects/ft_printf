NAME		= libftprintf.a

CC 			= cc
FLAGS 		= -Wall -Wextra -Werror -I . -I ./libft

HEADERS 	= ./ft_printf.h \
	./libft/libft.h \

B_DIR 		= ./.build

SRCS_DIR 	= ./srcs
SRCS		= ./libft/libft.a \
	$(SRCS_DIR)/ft_printf.c \
	$(SRCS_DIR)/utils/ft_print_char.c \
	$(SRCS_DIR)/utils/ft_print_hex_upper.c \
	$(SRCS_DIR)/utils/ft_print_hex.c \
	$(SRCS_DIR)/utils/ft_print_int.c \
	$(SRCS_DIR)/utils/ft_print_percent.c \
	$(SRCS_DIR)/utils/ft_print_pointer.c \
	$(SRCS_DIR)/utils/ft_print_string.c \
	$(SRCS_DIR)/utils/ft_print_unsigned_int.c \

OBJS 		= $(SRCS:%.c=$(B_DIR)/%.o)

$(NAME): $(OBJS) 
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)
	@mkdir -p $(@D)

$(B_DIR)/%.o: %.c $(HEADERS) Makefile
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c  $< -o $@

clean:
	rm -rf $(B_DIR)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
