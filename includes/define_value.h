/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_value.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:40:02 by memelia           #+#    #+#             */
/*   Updated: 2020/05/17 23:40:55 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_VALUE_H
# define DEFINE_VALUE_H

# include "wolf3d.h"

typedef enum				e_type_menu
{
	Menu,
	Choose,
	Game,
	Settings,
	Editor
}							t_type_menu;

typedef enum				e_type_boolean
{
	No,
	Yes
}							t_type_boolean;

typedef enum				e_id_of_special_texture
{
	North = 85,
	South,
	East,
	West
}							t_id_of_special_texture;

typedef enum				e_type_walls
{
	T_11 = 58,
	T_12,
	T_13,
	T_14,
	T_15,
	T_16,
	T_17,
	T_18,
	T_19,
	T_20,
	T_21,
	T_22,
	T_23,
	T_24,
	T_25,
	T_26,
	T_27,
	T_28,
	T_29,
	T_30,
	T_31,
	T_32,
	T_33,
	T_34,
	T_35,
	T_36,
	T_37,
	T_38
}							t_type_walls;

typedef enum				e_music
{
	music_flag_0,
	music_flag_1,
	music_flag_2,
	music_flag_3,
	music_flag_4
}							t_music;

# define WIDTH				1920
# define HEIGHT				1080

# define VIEW_HEIGHT_LIM	1310

# define NBR_TEXTURES		38

# define LOGO_ALPHA 		0xCD

# define BUTTONS_ALPHA		0x77

# define TEX_SIZE 			64

# define FLOOR_COLOR		0x353C44
# define CEILING_COLOR		0x525252
# define EMPTY_COLOR		0x980088

# define X 					0
# define Y 					1

# define START 				0
# define FINISH 			1

# define V 					0
# define H 					1

# define BG_IMG 			"assets/menu/XPM/main/background.xpm"
# define LG_IMG 			"assets/menu/XPM/main/logo.xpm"
# define LG_BASE 			"assets/menu/XPM/main/logo_base.xpm"
# define BT1 				"assets/menu/XPM/main/bt1.xpm"
# define BT2 				"assets/menu/XPM/main/bt2.xpm"
# define BT3 				"assets/menu/XPM/main/bt3.xpm"
# define BT4 				"assets/menu/XPM/main/bt4.xpm"
# define BT1_ACTIVE 		"assets/menu/XPM/main/bt5.xpm"
# define BT2_ACTIVE 		"assets/menu/XPM/main/bt6.xpm"
# define BT3_ACTIVE 		"assets/menu/XPM/main/bt7.xpm"
# define BT4_ACTIVE 		"assets/menu/XPM/main/bt8.xpm"
# define SCRL 				"assets/menu/XPM/scroller.xpm"

# define MV_STTNG			"assets/menu/XPM/settings/moving_title.xpm"
# define RT_STTNG			"assets/menu/XPM/settings/rotation_title.xpm"
# define VLM_STTNG			"assets/menu/XPM/settings/volume_title.xpm"
# define DPTH_STTNG			"assets/menu/XPM/settings/depth_title.xpm"
# define CNTRL_RLLR			"assets/menu/XPM/settings/settings_roller.xpm"

# define BCK_BTN			"assets/menu/XPM/back_button.xpm"
# define RFSH_BTN			"assets/menu/XPM/refresh_button.xpm"

# define MAPS_FOLDER		"maps/"

# define MAPS_LIMIT			15

# define BAD_GUY			"assets/textures/xpm/bad_guy/bad_guy"
# define BAD_GUY_2			"assets/textures/xpm/bad_guy/bad_guy_2"
# define DEAD_GUY			"assets/textures/xpm/bad_guy/dead_guy"

# define BAZUKA				"assets/textures/xpm/gun/bazuka"
# define PISTOLS			"assets/textures/xpm/gun/pistols"

# define GUN_1				"assets/textures/xpm/gun/gun_1.xpm"
# define GUN_2				"assets/textures/xpm/gun/gun_2.xpm"
# define GUN_3				"assets/textures/xpm/gun/gun_3.xpm"
# define GUN_4				"assets/textures/xpm/gun/gun_4.xpm"
# define GUN_5				"assets/textures/xpm/gun/gun_5.xpm"

# define WALL0				"assets/textures/xpm/walls/WALL0.xpm"
# define WALL3				"assets/textures/xpm/walls/WALL3.xpm"
# define WALL7				"assets/textures/xpm/walls/WALL7.xpm"
# define WALL10				"assets/textures/xpm/walls/WALL10.xpm"
# define WALL13				"assets/textures/xpm/walls/WALL13.xpm"
# define WALL14				"assets/textures/xpm/walls/WALL14.xpm"
# define WALL16				"assets/textures/xpm/walls/WALL16.xpm"
# define WALL18				"assets/textures/xpm/walls/WALL18.xpm"
# define WALL21				"assets/textures/xpm/walls/WALL21.xpm"
# define WALL32				"assets/textures/xpm/walls/WALL32.xpm"
# define WALL33				"assets/textures/xpm/walls/WALL33.xpm"
# define WALL35				"assets/textures/xpm/walls/WALL35.xpm"
# define WALL40				"assets/textures/xpm/walls/WALL40.xpm"
# define WALL51				"assets/textures/xpm/walls/WALL51.xpm"
# define WALL55				"assets/textures/xpm/walls/WALL55.xpm"
# define WALL64				"assets/textures/xpm/walls/WALL64.xpm"
# define WALL71				"assets/textures/xpm/walls/WALL71.xpm"
# define WALL72				"assets/textures/xpm/walls/WALL72.xpm"
# define WALL74				"assets/textures/xpm/walls/WALL74.xpm"
# define WALL76				"assets/textures/xpm/walls/WALL76.xpm"
# define WALL77				"assets/textures/xpm/walls/WALL77.xpm"
# define WALL79				"assets/textures/xpm/walls/WALL79.xpm"
# define WALL80				"assets/textures/xpm/walls/WALL80.xpm"
# define WALL81				"assets/textures/xpm/walls/WALL81.xpm"
# define WALL85				"assets/textures/xpm/walls/WALL85.xpm"
# define WALL89				"assets/textures/xpm/walls/WALL89.xpm"
# define WALL92				"assets/textures/xpm/walls/WALL92.xpm"
# define WALL96				"assets/textures/xpm/walls/WALL96.xpm"
# define SPECIAL_WALL		"1"

# define SONG_0				"music/wolf3d_menu.mp3"
# define SONG_1				"music/song_1.mp3"
# define SONG_2				"music/song_2.mp3"
# define SHOT				"music/shot.wav"
# define OPEN_EDITOR		"music/oh-shit-iam-sorry.wav"
# define CHOOSER_ERROR		"music/fisting-is-300.wav"
#endif
