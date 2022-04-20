# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 13:19:03 by iomayr            #+#    #+#              #
#    Updated: 2022/03/08 15:28:08 by iomayr           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 

CFLAGS = -Wall -Wextra -Werror

PRINTF = ft_printf/libftprintf.a

SRC = main.c errors.c split.c read_map.c utiles_libft.c \
      print_map.c mvt.c extra_utiles.c

OBJ = ${SRC:%.c=%.o}

SRC_B = main_bonus.c errors_bonus.c split_bonus.c read_map_bonus.c \
		utiles_libft_bonus.c  print_map_bonus.c \
		mvt_bonus.c enemy_bonus.c fr.c extra_utiles_bonus.c

OBJ_B = ${SRC_B:%.c=%.o}

NAME_B = so_long_bonus

NAME = so_long

all: ${NAME}

bonus: ${NAME_B}

${NAME}: ${OBJ} so_long.h
	make -C ft_printf
	#cc -I /usr/local/include main.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit
	${CC} ${CFLAGS} ${OBJ} -lmlx -framework OpenGL -framework AppKit -o so_long ${PRINTF}

${NAME_B}: ${OBJ_B} so_long_bonus.h
	make -C ft_printf
	#cc -I /usr/local/include main.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit
	${CC} ${CFLAGS} ${OBJ_B} -lmlx -framework OpenGL -framework AppKit -o so_long_bonus ${PRINTF}
 

clean :
	make fclean -C ft_printf
	rm -rf ${OBJ}
	rm -rf ${OBJ_B}

fclean:clean
	rm -rf so_long	
	rm -rf so_long_bonus

re :fclean all