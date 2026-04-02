NAME = fdf
CC = cc
MAIN = main.c
DMODE =
CFLAGS = -Wall -Wextra -Werror

ifeq ($1, debug)
	CFLAGS += -g
	DMODE += (debug mode)
endif

NEUTRAL = \033[0;0m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m

INCLUDES = includes

MATH = m

MLX = mlx
LIBMLX = libmlx.a
MLXDIR = src/mlx
INCMLX = $(INCLUDES)/$(LIBMLX)
SRCMLX = $(MLXDIR)/$(LIBMLX)

FT = ft
LIBFT = libft.a
LIBFTDIR = src/libft
INCFT = $(INCLUDES)/$(LIBFT)
SRCFT = $(LIBFTDIR)/$(LIBFT)

SRCS = $(MAIN) \
       fdf_utils.c \
       fdf_utils_shapes.c \
	   fdf_utils_iso.c \
	   fdf_utils_hooks.c \
	   fdf_utils_fdf.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

debug: $(NAME)

re: fclean all

$(NAME): $(OBJS) $(INCFT) $(INCMLX)
	@$(CC) $(CFLAGS) $(OBJS) -L$(INCLUDES) -l$(FT) -l$(MLX) -lXext -lX11 -l$(MATH) -o $@
	@printf "${YELLOW}Building ${BLUE}$@ ${YELLOW}${DMODE}\n${NEUTRAL}"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $^
	@printf "Compiling ${BLUE}$^ ${YELLOW}${DMODE}\n${NEUTRAL}"

$(INCFT):
	@make --silent -C $(LIBFTDIR)
	@mkdir -p $(INCLUDES) && cp $(SRCFT) $(INCLUDES)
	@make --silent -C $(LIBFTDIR) fclean
	@echo "${YELLOW}Copying libft archive to libraries folder\n${NEUTRAL}"

$(INCMLX):
	@make --silent -C $(MLXDIR)
	@mkdir -p $(INCLUDES) && cp $(SRCMLX) $(INCLUDES)
	@make --silent -C $(MLXDIR) clean
	@echo "${YELLOW}Copying MLX archive to libraries folder\n${NEUTRAL}"

fclean: clean
	@rm -rf $(INCLUDES) $(NAME)
	@printf "${RED}Deleting archives and binaries\n${NEUTRAL}"

clean:
	@rm -f $(OBJS) test.o
	@echo "${RED}Deleting object files\n${NEUTRAL}"

.PHONY: all fclean clean re debug test
