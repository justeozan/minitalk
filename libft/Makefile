# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 14:21:01 by ozasahin          #+#    #+#              #
#    Updated: 2024/02/12 14:21:01 by ozasahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# .DEFAULT_GOAL:	all

# # Archive file name
# NAME	=	libft.a

# # Source file paths
# SRCS	=	\
# 			file/ft_putchar_fd.c\
# 			file/ft_putendl_fd.c\
# 			file/ft_putnbr_fd.c\
# 			file/ft_putstr_fd.c\
# 			\
# 			gnl/get_next_line_utils.c\
# 			gnl/get_next_line.c\
# 			\
# 			is/ft_isalnum.c\
# 			is/ft_isalpha.c\
# 			is/ft_isascii.c\
# 			is/ft_isdigit.c\
# 			is/ft_isprint.c\
# 			\
# 			lst/ft_lstadd_back.c\
# 			lst/ft_lstadd_front.c\
# 			lst/ft_lstclear.c\
# 			lst/ft_lstdelone.c\
# 			lst/ft_lstiter.c\
# 			lst/ft_lstlast.c\
# 			lst/ft_lstmap.c\
# 			lst/ft_lstnew.c\
# 			lst/ft_lstsize.c\
# 			\
# 			mem/ft_memset.c\
# 			mem/ft_bzero.c\
# 			mem/ft_calloc.c\
# 			mem/ft_memchr.c\
# 			mem/ft_memcmp.c\
# 			mem/ft_memcpy.c\
# 			mem/ft_memmove.c\
# 			\
# 			nbr/ft_atoi.c\
# 			nbr/ft_atol.c\
# 			nbr/ft_itoa.c\
# 			\
# 			printf/ft_printf.c\
# 			printf/ft_printf_utils.c\
# 			\
# 			str/ft_split.c\
# 			str/ft_strrchr.c\
# 			str/ft_strdup.c\
# 			str/ft_striteri.c\
# 			str/ft_strjoin.c\
# 			str/ft_strlcat.c\
# 			str/ft_strlcpy.c\
# 			str/ft_strlen.c\
# 			str/ft_strmapi.c\
# 			str/ft_strncmp.c\
# 			str/ft_strnstr.c\
# 			str/ft_strrchr.c\
# 			str/ft_strtrim.c\
# 			str/ft_substr.c\
# 			str/ft_tolower.c\
# 			str/ft_toupper.c\
# 			\

# OBJS	=	$(SRCS:.c=.o)

# #Commands
# CC		=	gcc
# CFLAGS	=	-Wall -Wextra -Werror
# RM		=	rm -f

# all:		$(NAME)

# $(NAME):	$(OBJS)
# 			@ar rc $(NAME) $(OBJS)

# .c.o:		libft.h
# 			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

# clean:
# 			@$(RM) $(OBJS)

# fclean:		clean
# 			@$(RM) $(NAME)

# re:			fclean all

# .PHONY:		all clean fclean re

# =====================================================================================
# NEW MAKEFILE
# =====================================================================================

.DEFAULT_GOAL:	all

# Archive file name
NAME	=	libft.a

# Source file paths
SRCS	=	\
			file/ft_putchar_fd.c\
			file/ft_putendl_fd.c\
			file/ft_putnbr_fd.c\
			file/ft_putstr_fd.c\
			\
			gnl/get_next_line_utils.c\
			gnl/get_next_line.c\
			\
			is/ft_isalnum.c\
			is/ft_isalpha.c\
			is/ft_isascii.c\
			is/ft_isdigit.c\
			is/ft_isprint.c\
			\
			lst/ft_lstadd_back.c\
			lst/ft_lstadd_front.c\
			lst/ft_lstclear.c\
			lst/ft_lstdelone.c\
			lst/ft_lstiter.c\
			lst/ft_lstlast.c\
			lst/ft_lstmap.c\
			lst/ft_lstnew.c\
			lst/ft_lstsize.c\
			\
			mem/ft_memset.c\
			mem/ft_bzero.c\
			mem/ft_calloc.c\
			mem/ft_memchr.c\
			mem/ft_memcmp.c\
			mem/ft_memcpy.c\
			mem/ft_memmove.c\
			\
			nbr/ft_atoi.c\
			nbr/ft_atol.c\
			nbr/ft_itoa.c\
			\
			printf/ft_printf.c\
			printf/ft_printf_utils.c\
			\
			str/ft_split.c\
			str/ft_strrchr.c\
			str/ft_strdup.c\
			str/ft_striteri.c\
			str/ft_strjoin.c\
			str/ft_strlcat.c\
			str/ft_strlcpy.c\
			str/ft_strlen.c\
			str/ft_strmapi.c\
			str/ft_strncmp.c\
			str/ft_strnstr.c\
			str/ft_strrchr.c\
			str/ft_strtrim.c\
			str/ft_substr.c\
			str/ft_tolower.c\
			str/ft_toupper.c\
			\

# OBJS	=	$(SRCS:.c=.o)

OBJS	=	$(patsubst %/%.c, obj/%/%.o, $(SRCS))

#Commands
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rc $(NAME) $(OBJS)

# .c.o:		libft.h
# 			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

%.o:		%.c libft.h Makefile | obj
			@$(CC) $(CFLAGS) -c $< -o $@

obj:
			mkdir -p obj

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re