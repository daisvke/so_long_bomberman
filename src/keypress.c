/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:41:30 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/09/09 04:27:08 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	sl_get_free_slot_in_array(t_env *env, t_items *bombs, int x, int y)
{
	int	i;

	i = 0;
	while (i < env->tex.bomb.collected)
	{
		if (bombs[i].pos.x == x && bombs[i].pos.y == y)
			break ;
		if (bombs[i].draw == false)
			return (i);
		++i;
	}
	return (NO_AVAILABLE_SLOT);
}

void	sl_handle_keypress_b(t_env *env, int x, int y)
{
	int	i;

	i = sl_get_free_slot_in_array(env, env->tex.bomb.set_bombs, x, y);
	if (i != NO_AVAILABLE_SLOT)
	{
		++env->tex.bomb.set_bombs_nbr;
		sl_init_set_bomb(&env->tex.bomb.set_bombs[i], true, x, y, \
			env->tex.bomb.explode_size);
	}
}

bool	sl_find_no_current_direction(t_env *env)
{
	int	dir;
	
	dir = env->p1.curr_dir;
	if ((dir & CR_UP) || (dir & CR_DOWN) || (dir & CR_LEFT) || (dir & CR_RIGHT))
		return (false);
	else
		return (true);
}

int	sl_handle_keypress(int keycode, t_env *env)
{
	int	*dir;
	int	set_bombs;
	int	collected_bombs;

	if (keycode == XK_Escape)
		sl_exit_game(env);
	dir = &env->p1.curr_dir;
	if (sl_find_no_current_direction(env))
	{
		if (keycode == XK_w || keycode == XK_z)
			*dir |= CR_UP;
		if (keycode == XK_s)
			*dir |= CR_DOWN;
		if (keycode == XK_a || keycode == XK_q)
			*dir |= CR_LEFT;
		if (keycode == XK_d || keycode == XK_d)
			*dir |= CR_RIGHT;
	}
	set_bombs = env->tex.bomb.set_bombs_nbr;
	collected_bombs = env->tex.bomb.collected;
    if (keycode == XK_b && set_bombs < collected_bombs)
		sl_handle_keypress_b(env, env->p1.pos.x, env->p1.pos.y);
	return (0);
}

/*
int	sl_handle_keyrelease(int keycode, t_env *env)
{
	int			x;
	int			y;

	x = env->p1.pos.x;
	y = env->p1.pos.y;
	if (keycode == XK_w || keycode == XK_z)
		env->p1.curr_dir.up = false;
	if (keycode == XK_s)
		env->p1.curr_dir.down = false;
	if (keycode == XK_a || keycode == XK_q)
		env->p1.curr_dir.left = false;
	if (keycode == XK_d || keycode == XK_d)
		env->p1.curr_dir.right = false;
	return (0);
}
*/
