NAME = libft.a
NAME_B = libft_b.a
AR = ar
ARFLAG = -rcs
GCMP = gcc
GCFLAG = -Wall -Werror -Wextra
SRCS = ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c \
				ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c \
				ft_isprint.c ft_putchar_fd.c ft_strlcat.c ft_substr.c\
				ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_strlcpy.c ft_tolower.c\
				ft_bzero.c ft_memccpy.c ft_putnbr_fd.c ft_strlen.c ft_toupper.c\
				ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strmapi.c ft_isalnum.c\
				ft_memcmp.c ft_split.c ft_strncmp.c ft_isalpha.c\
				ft_memcpy.c ft_strchr.c ft_strnstr.c
SRCS_B = ft_lstadd_back.c ft_lstdelone.c ft_lstmap.c\
				ft_lstadd_front.c ft_lstiter.c ft_lstnew.c\
				ft_lstclear.c ft_lstlast.c ft_lstsize.c
OBJ = $(SRCS:.c=.o)
OBJ_B = $(SRCS_B:.c=.o)

.SUFFIXES: .c .o

all: $(NAME)

bonus: $(NAME_B)

.c.o:
		$(GCMP) $(GCFLAG) -I ./ -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
		$(AR) $(ARFLAG) $@ $^

$(NAME_B): $(NAME) $(OBJ_B)
		$(AR) $(ARFLAG) $(NAME) $(OBJ_B)

clean:
		rm -rf $(OBJ) $(OBJ_B)

fclean: clean
		rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
