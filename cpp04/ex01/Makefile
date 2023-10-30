# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 15:14:10 by lbaumann          #+#    #+#              #
#    Updated: 2023/10/30 14:28:35 by lbaumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brain

CC = c++ -std=c++98 -Werror -Wextra -Wall
CFLAGS = 
MAKEFLAGS   += --no-print-directory

ifeq ($(NOFLAGS), 1)
CFLAGS = 
endif

ifeq ($(DEBUG), 1)
CFLAGS = -g
all: fclean
endif

SRCDIR := srcs
OBJDIR := objs

HEADERS = -I includes

SRCS = \
	main.cpp \
	Cat.cpp \
	Animal.cpp \
	Dog.cpp \
	Brain.cpp \
	
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
.SILENT:
