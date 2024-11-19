NAME = libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror -I .
HEADER = libft.h
BDIR = .build

SRCS_IS = ./is/ft_isalnum.c \
		./is/ft_isalpha.c \
		./is/ft_isascii.c \
		./is/ft_isdigit.c \
		./is/ft_isprint.c \

SRCS_MEM = ./mem/ft_bzero.c \
		./mem/ft_calloc.c \
		./mem/ft_memchr.c \
		./mem/ft_memcmp.c \
		./mem/ft_memcpy.c \
		./mem/ft_memmove.c \
		./mem/ft_memset.c \

SRCS_PUT = ./put/ft_putchar_fd.c \
		./put/ft_putendl_fd.c \
		./put/ft_putnbr_base_fd.c \
		./put/ft_putstr_fd.c \

SRCS_STR = ./str/ft_split.c \
		./str/ft_strchr.c \
		./str/ft_strdup.c \
		./str/ft_strjoin.c \
		./str/ft_strlcat.c \
		./str/ft_strlcpy.c \
		./str/ft_strlen.c \
		./str/ft_strmapi.c \
		./str/ft_strncmp.c \
		./str/ft_strnstr.c \
		./str/ft_strrchr.c \
		./str/ft_strtrim.c \
		./str/ft_substr.c \

SRCS_TO = ./to/ft_atoi_base.c \
		./to/ft_itoa_base.c \
		./to/ft_tolower.c \
		./to/ft_toupper.c \

SRCS_LST = ./lst/ft_lstadd_back.c \
		./lst/ft_lstadd_front.c \
		./lst/ft_lstclear.c \
		./lst/ft_lstdelone.c \
		./lst/ft_lstiter.c \
		./lst/ft_lstlast.c \
		./lst/ft_lstmap.c \
		./lst/ft_lstnew.c \
		./lst/ft_lstsize.c \

SRCS = $(SRCS_IS) $(SRCS_MEM) $(SRCS_PUT) $(SRCS_STR) $(SRCS_TO) $(SRCS_LST)
OBJS 	= $(SRCS:%.c=$(BDIR)/%.o)

$(NAME): $(OBJS) 
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)
	@mkdir -p $(@D)

$(BDIR)/%.o: %.c $(HEADER) Makefile
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c  $< -o $@

clean:
	rm -rf $(BDIR)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
