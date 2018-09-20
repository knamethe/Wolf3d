/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamethe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:18:46 by knamethe          #+#    #+#             */
/*   Updated: 2018/09/05 14:41:46 by knamethe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int				i;
	unsigned int	p;

	i = 0;
	p = x * (mlx->bpp / 8) + y * (mlx->size_line);
	while (i < (mlx->bpp / 8))
	{
		mlx->d[p + i] = color;
		color >>= 8;
		i++;
	}
}

int		ft_player_init(t_mlx *mlx, int j, int i)
{
	while (mlx->map[j])
	{
		i = 0;
		while (mlx->map[j][i])
		{
			if (mlx->map[j][i] == 'X')
			{
				mlx->player.xpos = j;
				mlx->player.ypos = i;
				mlx->player.xdir = -1;
				mlx->player.ydir = 0;
				mlx->player.mvspd = 0.2;
				mlx->player.rtspd = 0.05;
				mlx->player.sprint = 0;
				return (0);
			}
			i++;
		}
		j++;
	}
	ft_putendl("Error : Player is not found in map");
	return (-1);
}

int		ft_instructions(void)
{
	ft_putendl(" <<--INSTRUCTIONS-->> ");
	ft_putendl("< > : Rotate camera");
	ft_putendl("^ v : Movement");
	ft_putendl("shift : Activate/deactivate sprinting");
	ft_putendl("+/- : Increase/decrease wall height");
	ft_putendl("ESC : Close");
	return (0);
}

int		ft_linelen(char *buf, int k)
{
	int	len;

	len = 0;
	while (buf[k] != '\n' && buf[k] != '\0')
	{
		k++;
		len++;
	}
	return (len);
}

int		ft_checkchar(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
		i++;
	buf[i - 1] = '\0';
	i = 0;
	while (buf[i])
	{
		if (buf[i] != '\n' && buf[i] != '0' && buf[i] != '1'\
				&& buf[i] != 'X' && buf[i] != '\0')
		{
			ft_putendl("Error: Invalid characters in the map");
			return (-1);
		}
		i++;
	}
	if (ft_borders(buf, 0) == -1)
	{
		ft_putendl("Error: The Map must have borders");
		return (-1);
	}
	return (0);
}
