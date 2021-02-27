NAME := test
CC := gcc
CFLAGS := -Wall -Werror -Wextra
SRCDIR := ../
SRCS := $(SRCDIR)get_next_line.c $(SRCDIR)get_next_line_utils.c
BSRCS := $(SRCDIR)get_next_line_bonus.c $(SRCDIR)get_next_line_utils_bonus.c
BUFSIZE := 1024
BUFF := -D BUFFER_SIZE=$(BUFSIZE)
TEST = test_gnl.c

.PHONY: all
all: $(NAME)

$(NAME): $(TEST) $(SRCS)
	$(CC) $(BUFF) -D MANDATORY $(CFLAGS) -o $@ $^ 

std: $(SRCS)
	$(CC) $(BUFF) $(CFLAGS) -o $(NAME) $^ test_std.c

bonus: $(TEST) $(BSRCS)
	$(CC) $(CFLAGS) $(BUFF) -D BONUS -o $(NAME) $^

debug: $(TEST) $(SRCS)
	$(CC) $(BUFF) -D MANDATORY -g $(CFLAGS) -o $(NAME) $^

clean:
	rm -fr $(NAME)

re: clean all
.PHONY: all std bonus debug clean re
