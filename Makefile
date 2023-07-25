#---------------------------------------------------#
#                   FdF MAKEFILE                    #
#---------------------------------------------------#

# Executable Name #
NAME	=	fdf

# Define some color codes for pretty printing
RED = \033[91m
YELLOW = \033[93m
WHITE = \033[97m
GREEN = \033[92m
DEF_CL = \033[m
RESET  = \e[0m
CYAN = \033[96m

#---------------------------------------------------#
#                   COMPILER SETTINGS               #
#---------------------------------------------------#

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Command to remove files
RM = rm -f

#---------------------------------------------------#
#                   SOURCE FILES                    #
#---------------------------------------------------#

# libft Variables
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

# MiniLibX Variables
MLX = -lmlx -framework OpenGL -framework AppKit
MLX_DIR = ./minilibx

# Source Variables
SRC	= 

# Headers
INC		=	-I. -I$(LIBFT_DIR) -I$(MLX_DIR)

_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]
_READY 		= 	$(GREEN)ready.$(RESET)
_REMOVED    =   $(YELLOW)removed.$(RESET)

# Debugger
ifeq ($(DEBUG), 1)
	D_FLAG	=	-g
endif

# Fsanitize
ifeq ($(SANITIZE), 1)
	D_FLAG	=	-fsanitize=leak -g
endif

#---------------------------------------------------#
#                   MAIN TARGET                     #
#---------------------------------------------------#

all: $(NAME)

$(NAME): $(LIBFT)
	@ $(CC) $(D_FLAG) $(CFLAGS) $(SRC) $(LIBFT) $(MLX) $(INC) -o $(NAME)
	@printf "$(_SUCCESS) $(NAME) $(_READY)\n"

$(LIBFT):
	@ $(MAKE) DEBUG=$(DEBUG) -C $(LIBFT_DIR)

# Rule to clean up object files and dependencies
clean:
	@ $(RM) $(NAME)
	@printf "$(_INFO) $(NAME) $(_REMOVED)\n"

# Rule to remove the compiled library file and cleaned object files
fclean:
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(RM) $(NAME)
	@printf "$(_INFO) $(NAME) $(_REMOVED)\n"

# Rule to completely rebuild the program from scratch
re: fclean all

# Rule to tell make that the listed targets do not correspond to actual files.
.PHONY: all clean fclean re $(NAME) $(LIBFT)
