# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liperman <liperman@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 10:24:51 by liperman          #+#    #+#              #
#    Updated: 2022/10/31 16:56:59 by liperman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = so_long
LIBFT = ./libft/libft.a
CLIBFT = make -C libft clean
FCLIBFT = make -C libft fclean
MLX = make -C mlx &> /dev/null
CMLX = make -C mlx clean
INCLUDE = -L ./mlx -lmlx -framework OpenGL -framework AppKit
SRC = so_long.c movements.c ./code_map/path_validation.c ./code_map/map_gen.c ./code_map/map_validation.c ./code_map/map_to_img.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(MLX)
	make -C ./libft
	$(CC) $(FLAGS) $(SRC) $(LIBFT) $(INCLUDE) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(CLIBFT)
	$(CMLX)

fclean:
	rm -f $(NAME)
	$(FCLIBFT)
	$(CMLX)

re: fclean all

.PHONY: all clean fclean re
