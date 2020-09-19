
.PHONY : all clean fclean re check_libft check_ft_printf

#MAKEFLAGS += --silent

NAME = ft_ssl

FLAGS = -Wall -Wextra -Werror

OBJ_DIR := objects/

SRC := $(shell cat files_list/main_files.txt)

HEADERS := $(shell cat files_list/headers.txt)

UTILS := $(shell cat files_list/utils_files.txt)

ALGO := $(shell cat files_list/algorithm_files.txt)

SRC_DIR = src/
UTILS_DIR = $(SRC_DIR)utils/
ALGO_DIR = $(SRC_DIR)algorithm/

INCLUDES_DIR = includes

VPATH := $(SRC_DIR):$(UTILS_DIR):$(ALGO_DIR)

LIBFT_PATH = libft/

LIBFT_HEADERS = $(LIBFT_PATH)includes

LIBFT = libft.a

HEADER_PATH = $(patsubst %.h, $(INCLUDES_DIR)/%.h, $(HEADERS))

OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))
OBJ += $(patsubst %.c, $(OBJ_DIR)%.o, $(UTILS))
OBJ += $(patsubst %.c, $(OBJ_DIR)%.o, $(ALGO))

MODE = 1

ifeq ($(MODE), 0)

all: $(NAME)

$(NAME): $(OBJ)

$(OBJ_DIR)%.o : %.c $(HEADERS_PATH)
	@printf "\r                                          "
	@printf "\r\033[92m--->Compiling $(@F)\033[0m"
	@gcc $(FLAGS) -I$(INCLUDES_DIR) -I$(LIBFT_HEADERS) -c $<
	@mkdir -p $(OBJ_DIR)
	@mv -f $(@F) $(OBJ_DIR)

else

all:  check_libft $(NAME)

$(NAME) : $(OBJ) $(LIBFT_PATH)$(LIBFT)
	gcc $(OBJ) -L$(LIBFT_PATH) -lft -o $(NAME)

$(OBJ_DIR)%.o: %.c $(HEADERS_PATH)
	@printf "\033[92mCompiling ft_ssl...\033[0m\n"
	@$(MAKE)  MODE=0
	@printf "\r                                          "
	@printf "\r\033[92mDone ft_ssl[\xE2\x9C\x94]\n\033[0m"

endif

check_libft:
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@printf "\033[92m<< Cleaning $(NAME) >>\n\033[0m"
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@printf "\r\033[92m<< Fcleaning $(NAME) >>\n\033[0m"
	@rm -f $(NAME)

re:	fclean
	@$(MAKE) 
