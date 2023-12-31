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
CFLAGS = -Werror -Wall -Wextra

# Command to remove files
RM = rm -f

#---------------------------------------------------#
#                   SOURCE FILES                    #
#---------------------------------------------------#

# libft Variables
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

# Printf Variables
PRINTF		=	./ft_printf/libftprintf.a
PRINTF_DIR	=	./ft_printf

# MiniLibX Variables
MINILIBX = ./minilibx_macos/libmlx.a
MINILIBX_DIR = ./minilibx_macos

# Source Variables
SRC	= srcs/fdf.c srcs/general_functions.c srcs/aux.c \
      srcs/read_fdf.c srcs/drawing.c srcs/color.c

# Headers
INC		=	-I. -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MINILIBX_DIR)

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

$(NAME): $(LIBFT) $(PRINTF) $(MINILIBX)
	@ $(CC) $(D_FLAG) $(CFLAGS) $(SRC) $(LIBFT) $(PRINTF) $(MINILIBX) $(INC) -framework OpenGL -framework AppKit -framework Cocoa -framework Foundation -o $(NAME)
	@printf "$(_SUCCESS) $(NAME) $(_READY)\n"

$(LIBFT):
	@ $(MAKE) DEBUG=$(DEBUG) -C $(LIBFT_DIR)

$(PRINTF):
	@ $(MAKE) DEBUG=$(DEBUG) -C $(PRINTF_DIR)

$(MINILIBX):
	@ $(MAKE) -C $(MINILIBX_DIR)

# Rule to clean up object files and dependencies
clean:
	@ $(RM) $(NAME)
	@printf "$(_INFO) $(NAME) $(_REMOVED)\n"

# Rule to remove the compiled library file and cleaned object files
fclean:
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(MAKE) fclean -C $(PRINTF_DIR)
	@ $(MAKE) clean -C $(MINILIBX_DIR)
	@ $(RM) $(NAME)
	@printf "$(_INFO) $(NAME) $(_REMOVED)\n"

# Rule to completely rebuild the program from scratch
re: fclean all

# Rule for telling make that the listed targets do not correspond to actual files.
.PHONY: all clean fclean re $(NAME) $(LIBFT) $(PRINTF) $(MINILIBX)
