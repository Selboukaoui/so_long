CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
NAME_B = so_long_bonus

SRC = Mandatory/solong.c Mandatory/utils/ft_atoi.c Mandatory/utils/ft_strcmp.c Mandatory/utils/ft_strlen.c \
	  Mandatory/utils/grb_coll.c Mandatory/utils/map_stuff.c Mandatory/utils/errors.c Mandatory/utils/ft_strlcpy.c \
	  Mandatory/utils/map_utils.c  Mandatory/utils/ft_strdup.c Mandatory/utils/print_map.c Mandatory/utils/movement.c \
	  Mandatory/utils/get_next_line.c Mandatory/utils/get_next_line_utils.c 

SRCB = Bonus/solong_bonus.c Bonus/utils/ft_atoi.c Bonus/utils/ft_strcmp.c Bonus/utils/ft_strlen.c \
	   Bonus/utils/grb_coll_bonus.c Bonus/utils/map_stuff_bonus.c Bonus/utils/errors_bonus.c Bonus/utils/ft_strlcpy.c \
	   Bonus/utils/map_utils_bonus.c  Bonus/utils/ft_strdup.c Bonus/utils/print_map_bonus.c Bonus/utils/movement_bonus.c \
	   Bonus/utils/get_next_line.c Bonus/utils/get_next_line_utils.c bonus/utils/utils.c 

SRCPRF = ft_printf/ft_adress.c ft_printf/ft_printf.c ft_printf/ft_printhex.c \
		 ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putstr.c ft_printf/ft_putunbr.c

FT_PRINTF_DIR = ft_printf

FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

OBJB = $(SRCB:.c=.o)
OBJS = $(SRC:.c=.o)

INCLUDES = -Iincludes -I$(FT_PRINTF_DIR) 

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(FT_PRINTF_LIB) $(NAME)

bonus: $(FT_PRINTF_LIB) $(NAME_B)

$(NAME): $(OBJS) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) $(MLX_FLAGS) -o $(NAME)

$(NAME_B): $(OBJB) $(FT_PRINTF_LIB) 
	$(CC) $(CFLAGS) $(OBJB) $(FT_PRINTF_LIB) $(MLX_FLAGS) -o $(NAME_B)

$(FT_PRINTF_LIB): $(SRCPRF) ft_printf/ft_printf.h
	make -C $(FT_PRINTF_DIR)

%.o: %.c Mandatory/solong.h ft_printf/ft_printf.h 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

Bonus/%.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJB): Bonus/solong_bonus.h

clean:
	rm -f $(OBJS) 
	rm -f $(OBJB) 
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_B)
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: clean