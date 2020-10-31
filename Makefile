.PHONY: all, $(NAME), norm, clean, fclean, re

NAME = wolf3D

FRAMEDIR = /Users/$(USER)/Library/Frameworks

SRC_PATH = ./sources/
OBJ_PATH = ./objects/
INC_PATH = ./includes/
LIB_PATH = ./libft/
MLX_PATH = ./mlx/
SDL_AUDIO_PATH = ./Simple-SDL2-Audio/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
INC_SDL = 		-I Frameworks/SDL2.framework/Versions/A/Headers 		\
				-I Frameworks/SDL2_image.framework/Versions/A/Headers 	\
				-I Frameworks/SDL2_ttf.framework/Versions/A/Headers 	\
				-I Frameworks/SDL2_mixer.framework/Versions/A/Headers/ 	\
				-F Frameworks/

FRAME = 	-F Frameworks/ -framework SDL2 -framework SDL2_image 		\
            -framework SDL2_ttf -framework SDL2_mixer -rpath Frameworks/

FLAGS = 	-Wall -Werror -Wextra -Ofast -g

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -framework OpenCL

SRC_NAME =	chooser_controls.c			chooser_data_load_2.c	chooser_data_load.c	\
			chooser_scroller_2.c		chooser_scroller.c		chooser.c			\
			close.c						ft_free.c				get_texture_name.c	\
			hooks.c 					init_env.c 				init_game_data.c 	\
			load_additional_buttons.c	load_textures.c 		main.c 				\
			menu_add_bttns_control.c	menu_controls.c			menu_data_load.c 	\
			menu.c 						mouse_controls.c 		move.c				\
			music_manager.c				player_weapon.c			ray_caster.c 		\
			reader_helper.c				reader.c 				renderer.c 			\
			settings_controls.c			settings_data_load.c	settings.c			\
			work_with_map.c				\

OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make lib_refresh
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -lm -L $(LIB_PATH) -L $(SDL_AUDIO_PATH) -lsdl_audio $(INC_SDL) $(FRAME) -lft -L $(MLX_PATH) $(MLX_FLAGS)
	 
$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC_PATH)/wolf3d.h $(INC_PATH)/define_value.h $(INC_PATH)/controls.h
	@mkdir -p $(OBJ_PATH)
	@gcc -g $(INC) $(INC_SDL) -o $@ -c $<

$(FRAMEDIR):
		@mkdir -p $(FRAMEDIR)
		@rm -rf $(FRAMEDIR)/*

lib_refresh:
	@make -C $(LIB_PATH)
	@make -C $(MLX_PATH)
	@make -C $(SDL_AUDIO_PATH)

norm:
	@echo "$(YELLOW)"
	@norminette -R CheckForbiddenSourceHeader

clean:
	@find . -name ".DS_Store" -delete
	@clear
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(SDL_AUDIO_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)
	@make clean -C $(MLX_PATH)
	@make fclean -C $(SDL_AUDIO_PATH)

re: fclean all