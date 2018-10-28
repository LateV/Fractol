NAME		=	fractol

SRC	=	main.c 					\
		ft_mouse_keyboard.c 	\
		ft_windows.c 			\
		ft_mouse.c 				\
		ft_putpixel.c 			\
		ft_render.c 			\
		ft_opr.c 				\
		ft_col.c 				\
		mandelbrot_t.c 			\
		mandelbrot.c 			\
		julia.c 				\
		ft_map.c 				\
		ft_create.c 			\
		burningship.c 			\
		ft_move_mouse.c 		\
		ft_tree.c 				\
		dnk.c 					\
		tricorn.c 				\
		mandelbrot4.c 			\
		ship.c 					\
		ft_hook.c 				\
		ft_errors.c 			\
		ft_mouse_keyboard1.c 	\
		ft_opr1.c 				\
		ft_instr.c 				\

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR		=	./src/

OBJ_DIR		=	./obj/

INC_DIR		=	./inc/

LIB_DIR		=	./libft/

LIBFT_DIR	=	$(LIB_DIR)libft/

LIBFT		=	$(LIBFT_DIR)libft.a

PRINTF_DIR	=	$(LIB_DIR)ft_printf/

LIBPRINTF	=	$(PRINTF_DIR)libftprintf.a

HEAD_PRINTF	=	$(PRINTF_DIR)$(INC_DIR)ft_printf.h
HEAD_LIBFT	=	$(LIBFT_DIR)$(INC_DIR)libft.h

HEAD_FR	=	$(INC_DIR)fractol.h

HEAD_FLAGS	=	-I $(INC_DIR) -I $(PRINTF_DIR)$(INC_DIR) -I $(LIBFT_DIR)$(INC_DIR)

LIBS_FLAGS	=	-L $(PRINTF_DIR) -lft -L $(LIBFT_DIR) -lftprintf -lncurses

CC_FLAGS	=	-Wall -Werror -Wextra -std=c11 -g

FLAGM 		= 	-lmlx -framework OpenGL -framework AppKit -O2 -Ofast

CC			=	gcc

BG			=	"\033[32;1m"
BR			=	"\033[31;1m"
EOC			=	"\033[0m"

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBPRINTF)
	@make -C $(LIBFT_DIR)

$(LIBPRINTF):
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJ)
	@$(CC) $(FLAGM) $(OBJ) -o $(NAME) $(LIBS_FLAGS)
	@echo ${BG}"fractol is ready"${EOC}

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEAD_FR) 
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEAD_FLAGS) 
	@echo ${BG}"[✓] $<"

clean:
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ)
	@echo ${BR}"[✗] clean"

fclean: clean
	@make fclean -C $(PRINTF_DIR)
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo ${BR}"[✗] $(NAME)"

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all fclean clean re $(LIBFT) $(LIBPRINTF)