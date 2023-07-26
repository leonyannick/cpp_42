# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 15:14:10 by lbaumann          #+#    #+#              #
#    Updated: 2023/07/26 14:38:28 by lbaumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
MAKEFLAGS   += --no-print-directory

ifeq ($(NOFLAGS), 1)
CFLAGS = 
endif

ifeq ($(DEBUG), 1)
CFLAGS = -g -std=c++98
all: fclean
endif

SRCDIR := srcs
OBJDIR := objs

HEADERS = -I/includes

SRCS = \
	main.cpp \
	Contact.cpp \
	PhoneBook.cpp \

#append directory in front of srcs/objs
SRCS		:= $(SRCS:%=$(SRCDIR)/%)
OBJS		:= $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	$(info CREATED $(NAME))

#	'$@': target
#	'$<': prerequisite
#	'$(@D)': represents the directory part of target file
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<
	$(info CREATED $@)

clean:
	rm -rf $(OBJDIR)
	$(info DELETED $(OBJDIR))

fclean: clean
	rm -f $(NAME)
	$(info DELETED $(NAME))

re: fclean all

.PHONY: all clean fclean re
#.SILENT:
