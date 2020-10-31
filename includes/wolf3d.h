/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:41:58 by memelia           #+#    #+#             */
/*   Updated: 2020/05/17 23:42:13 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <SDL.h>
# include <SDL_mixer.h>
# include <time.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <dirent.h>
# include <string.h>
# include <stdint.h>
# include <stdbool.h>

# include "../Simple-SDL2-Audio/audio.h"
# include "../libft/includes/libft.h"
# include "menu.h"
# include "errors.h"
# include "controls.h"
# include "define_value.h"

typedef struct			s_draw_column
{
	int					y[2];
	int					tex_coord[2];
	int					d;
	char				tex_id;
	double				wall_x;
}						t_draw_column;

typedef struct			s_map
{
	char				*name;
	int					width;
	int					height;
	char				**level;
	struct s_map		*next;
}						t_map;

typedef struct			s_tex
{
	char				id;
	int					width;
	int					height;
	void				*tex_ptr;
	char				*data;
	int					bts_pr_px;
	int					sz_ln;
	int					endian;
	struct s_tex		*next;
	struct s_tex		*prev;
}						t_tex;

typedef struct			s_ray
{
	double				v_dir[2];
	double				angle;
	int					m_pos[2];
	double				s_dist[2];
	double				d_dist[2];
	char				side;
	char				tex_side;
}						t_ray;

typedef struct			s_cast
{
	t_ray				*ray;
	double				time[2];
	int					step[2];
	double				distance;
	int					wall_height;
}						t_cast;

typedef	struct			s_cam
{
	double				pos[2];
	double				v_dir[2];
	double				v_plane[2];
	double				c_v_plane[2];
	double				c_v_dir[2];
	char				depth;
	int					view_height;
	float				m_speed;
	float				r_speed;
	t_tex				*weapon;
}						t_cam;

typedef struct			s_lvl_crd
{
	char				id;
	char				*level_name;
	int					pos;
	t_tex				*background;
	unsigned int		font_color;
	char				selected;
	struct s_lvl_crd	*next;
	struct s_lvl_crd	*prev;
}						t_lvl_crd;

typedef struct			s_menu_controls
{
	int					v_pos;
	int					m_pos;
	int					r_pos;
	int					s_pos;
	int					d_pos;
	char				scroller_status;
	char				id_first_card;
	char				num_of_cards;
	char				pressed[5];
	int					push_coord;
}						t_menu_controls;

typedef struct			s_menu
{
	int					bg_off[2];
	char				sel_button;
	t_tex				*first_tex[4];
	t_tex				*main;
	t_tex				*chooser;
	t_tex				*settings;
	t_tex				*back_button;
	t_tex				*refresh_button;
	t_lvl_crd			*cards;
	t_menu_controls		*controls;
	struct dirent		*file_name;
	DIR					*dir_ptr;
}						t_menu;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	int					sz_ln;
	int					endian;
	int					bts_pr_px;
	char				*data_addr;
	char				mode;
	Mix_Music			*music[4];
	int					volume;
	t_map				*map;
	t_tex				*tex;
	t_cam				*cam;
	t_cast				*cast;
	t_menu				*menu;
	t_cntrls			*cntrls;
}						t_env;

void					check_card_selection(int x, int y, t_env *env);
void					chooser_controls(int x, int y, t_env *env);
void					change_bg_color(t_lvl_crd *card, unsigned int color);

void					create_background(t_env *env, t_lvl_crd *card);

void					read_map_files(t_env *env, t_menu *menu);
void					load_chooser_data(t_env *env);

void					check_validation(const char *map_loc, t_env *env);

void					resset_card_coords(t_env *env);
void					scrolling(t_env *env, char sign, int old_value);
void					move_scroller(int y, t_env *env);
void					push_scroller(int x, int y, t_env *env);

void					draw_chooser(t_env *env);

int						x_close(t_env *env);

bool					ft_free(char **var_1, char **var_2);
void					ft_free_tex(t_env *env);

char					*get_texture_name(int i, char *arr_id_tex);

void					rotate(int key, t_env *env);
void					init_key_hooks(t_env *env);

t_env					*env_init(void);

t_tex					*tex_init(t_tex *prev, t_tex *next);
t_cam					*cam_init();
t_ray					*ray_init();
t_cast					*cast_init();

void					load_back_button(t_env *env);
void					load_refresh_button(t_env *env);

void					load_textures(t_env *env);

void					check_add_button_select(int x, int y, t_env *env);
void					draw_add_buttons(t_env *env);
void					check_push_add_buttons(int x, int y, t_env *env);

void					bg_paralax(int x, int y, t_env *env);
void					menu_push_buttons(int x, int y, t_env *env);
void					menu_controls(int x, int y, t_env *env);

void					load_menu_data(t_env *env);

void					set_alpha(char *data, int width, int height,
							unsigned int alpha_value);
void					draw_main_menu(t_env *env);

int						push_buttons(int button, int x, int y, t_env *env);
int						mouse_move(int x, int y, t_env *env);
int						mouse_release(int button, int x, int y, t_env *env);

void					player_move(int key, t_env *env);

void					init_sdl_music(Mix_Music **music, int *volume);
void					change_music(int flag, Mix_Music **music);

void					load_weapon_texture(t_env *env);

void					cast_a_ray(t_cast *cast, t_cam *cam, t_env *env);

bool					reader_error(t_map **map);
size_t					ft_strlen_without_symb(char symb, const char *s);
char					*ft_strnew_without_symb(char symb, char *str);
char					*read_file(t_map *map);

bool					read_map(const char *level_name, t_map *map);

void					renderer(t_env *env);

void					settings_push_buttons(int x, int y, t_env *env);
void					settings_controls(int x, int y, t_env *env);

void					load_settings_data(t_env *env);

void					draw_settings(t_env *env);

t_map					*map_init(char *name);
t_map					*find_current_map(const char *name, t_map **map);
void					delete_list_maps(t_map **map);

#endif
