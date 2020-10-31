/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 00:01:19 by memelia           #+#    #+#             */
/*   Updated: 2020/05/18 00:01:44 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			init_sdl_music(Mix_Music **music, int *volume)
{
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
		ft_exit(ERROR_INIT_SDL);
	initAudio();
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	*volume = 59;
	Mix_VolumeMusic(*volume);
	if (!(music[0] = Mix_LoadMUS(SONG_0)))
		ft_exit(MIX_LOADMUS);
	if (!(music[1] = Mix_LoadMUS(SONG_1)))
		ft_exit(MIX_LOADMUS);
	if (!(music[2] = Mix_LoadMUS(SONG_2)))
		ft_exit(MIX_LOADMUS);
	if (!(music[3] = Mix_LoadMUS(SHOT)))
		ft_exit(MIX_LOADMUS);
}

void			change_music(int flag, Mix_Music **music)
{
	Mix_PauseMusic();
	if (music_flag_0 == flag)
		Mix_PlayMusic(music[0], 10);
	else if (music_flag_1 == flag)
		Mix_PlayMusic(music[1], 10);
	else if (music_flag_2 == flag)
		Mix_PlayMusic(music[2], 10);
	else if (music_flag_3 == flag)
		Mix_PlayMusic(music[3], 10);
}
