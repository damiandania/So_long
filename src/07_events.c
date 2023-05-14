/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:13:10 by ddania-c          #+#    #+#             */
/*   Updated: 2023/05/14 13:43:18 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		exit_fail(data, "Closing window\n");
	else if (keysym == A || keysym == S || keysym == W || keysym == D)
		player_move(data, keysym);
	return (0);
}

int	press_exit(t_data *data)
{
	exit_fail(data, "Closing window\n");
	return (0);
}
