# Colores para resaltar la información
COLOR_RESET   = \033[0m
COLOR_BOLD    = \033[1m
COLOR_RED     = \033[91m
COLOR_GREEN   = \033[92m
COLOR_CYAN    = \033[96m

CELEBRATION_ICON = 🎉

NAME        := so_long
BONUS_NAME  := so_long_bonus
CFLAGS      := -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX      := ./MLX42
LIBFT       := ./Libft/libft.a
SRCDIR      := SRC
SRCDIR_BONUS := SRC_BONUS
SRCS        := $(wildcard $(SRCDIR)/*.c)
SRCS_BONUS  := $(wildcard $(SRCDIR_BONUS)/*.c)
HEADERS     := -I ./include -I $(LIBMLX)/include
OBJS        := ${SRCS:.c=.o}
OBJS_BONUS  := ${SRCS_BONUS:.c=.o}

UNAME       := $(shell uname -s)

ifeq ($(UNAME),Linux)
    LIBS    := $(LIBMLX)/libmlx42.a -ldl -lglfw -pthread -lm
else ifeq ($(UNAME),Darwin)
    LIBS    := $(LIBMLX)/libmlx42.a -ldl -I include -lglfw -L "/Users/cosorio-/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit -pthread -lm 
else
    $(error $(COLOR_RED)Unsupported operating system: $(UNAME)$(COLOR_RESET))
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME) && \
		{ \
			i=0; \
			while [ $$i -le 50 ]; do \
				printf "[$(COLOR_GREEN)%-50s$(COLOR_RESET)] $(COLOR_BOLD)%d%%$(COLOR_RESET)\r" "$$(printf '=%.0s' $$(seq 1 $$i))" $$((2 * $$i)); \
				sleep 0.01; \
				i=$$((i+1)); \
			done; \
			printf "\n$(COLOR_BOLD)$(CELEBRATION_ICON) Programa $(NAME) compilado con éxito! $(CELEBRATION_ICON)$(COLOR_RESET)\n"; \
		}


bonus: $(LIBFT) $(OBJS_BONUS)
	@if [ ! -f $(BONUS_NAME) ] || [ -n "$$(find $(SRCDIR_BONUS) -name '*.c' -newer $(BONUS_NAME))" ]; then \
		$(CC) $(OBJS_BONUS) $(LIBFT) $(LIBS) -o $(BONUS_NAME) && \
			{ \
				i=0; \
				while [ $$i -le 50 ]; do \
					printf "[$(COLOR_GREEN)%-50s$(COLOR_RESET)] $(COLOR_BOLD)%d%%$(COLOR_RESET)\r" "$$(printf '=%.0s' $$(seq 1 $$i))" $$((2 * $$i)); \
					sleep 0.01; \
					i=$$((i+1)); \
				done; \
				printf "\n$(COLOR_BOLD)$(CELEBRATION_ICON) Programa $(BONUS_NAME) compilado con éxito! $(CELEBRATION_ICON)$(COLOR_RESET)\n"; \
			}; \
	else \
		printf "$(COLOR_GREEN)Sin cambios en archivos bonus. No se requiere relink.$(COLOR_RESET)\n"; \
	fi

$(LIBFT):
	@$(MAKE) -C ./Libft

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && \
		printf "$(COLOR_GREEN)Compilando ->$(COLOR_RESET) $(COLOR_CYAN)$(notdir $<)$(COLOR_RESET)\n"

clean:
	@$(MAKE) clean -C ./Libft
	@rm -f $(OBJS) $(OBJS_BONUS) && \
		printf "$(COLOR_GREEN)Borrando objetos$(COLOR_RESET)\n"

fclean: clean
	@$(MAKE) fclean -C ./Libft
	@rm -f $(NAME) $(BONUS_NAME) && \
		printf "$(COLOR_GREEN)Borrando $(NAME) y $(BONUS_NAME)$(COLOR_RESET)\n"

re: fclean all

.PHONY: all bonus clean fclean re