/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamethe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:18:01 by knamethe          #+#    #+#             */
/*   Updated: 2018/09/04 15:55:45 by knamethe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_borders(char *buf, int i)
{
	while (buf[i] != '\n')
	{
		if (buf[i] != '1')
			return (-1);
		i++;
	}
	while (buf[i])
	{
		i++;
		if (buf[i] != '1')
			return (-1);
		while (buf[i] != '\0' && buf[i] != '\n')
			i++;
		if (buf[i - 1] != '1')
			return (-1);
	}
	i--;
	while (buf[i] != '\n')
	{
		if (buf[i] != '1')
			return (-1);
		i--;
	}
	return (0);
}

static int	ft_wall_colors(t_mlx *mlx)
{
	int		color;

	if (mlx->draw.side == 0 && mlx->cam.xdir >= 0)
		color = ORANGE;
	else if (mlx->draw.side == 0 && mlx->cam.xdir < 0)
		color = BLUE;
	else if (mlx->draw.side == 1 && mlx->cam.ydir >= 0)
		color = RED;
	else
		color = YELLOW;
	if (mlx->draw.side == 1)
		color = color / 2;
	return (color);
}

static void	ft_ini_drawing(t_mlx *mlx)
{
	mlx->cam.x = 2 * mlx->draw.x / (double)WIN_W - 1;
	mlx->draw.side = 0;
	mlx->draw.hit = 0;
	mlx->cam.xpos = mlx->player.xpos;
	mlx->cam.ypos = mlx->player.ypos;
	mlx->cam.xdir = mlx->player.xdir + mlx->cam.xplane * mlx->cam.x;
	mlx->cam.ydir = mlx->player.ydir + mlx->cam.yplane * mlx->cam.x;
	mlx->draw.xmap = (int)mlx->cam.xpos;
	mlx->draw.ymap = (int)mlx->cam.ypos;
	mlx->draw.xdelta_dist = sqrt(1 + pow(mlx->cam.ydir / mlx->cam.xdir, 2));
	mlx->draw.ydelta_dist = sqrt(1 + pow(mlx->cam.xdir / mlx->cam.ydir, 2));
}

static void	ft_slices_drawing(t_mlx *mlx)
{
	int		y;
	int		color;

	y = 0;
	while (y < WIN_H)
	{
		if (y < mlx->draw.start)
			color = SKY;
		else if (y > mlx->draw.end)
			color = GRAY;
		else
		{
			if (mlx->draw.hit == 1)
				color = ft_wall_colors(mlx);
		}
		ft_put_pixel(mlx, mlx->draw.x, y, color);
		y++;
	}
}

void		ft_drawing(t_mlx *mlx)
{
	mlx->draw.x = 0;
	while (mlx->draw.x < WIN_W)
	{
		ft_ini_drawing(mlx);
		ft_raycasting(mlx);
		ft_slices_drawing(mlx);
		mlx->draw.x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
