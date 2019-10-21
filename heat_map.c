/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:44:17 by jbouazao          #+#    #+#             */
/*   Updated: 2019/10/21 10:44:18 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "get_next_line.h"

static void fill_map(int i, int j, int score, t_P *map)
{
	if ((i - 1 >= 0) && (j - 1 >= 0) && map->map[i - 1][j - 1] == 0)
		map->map[i - 1][j - 1] = (map->map[i][j] == -2) ? 1 : score;
	if ((i - 1 >= 0) && map->map[i - 1][j] == 0)
		map->map[i - 1][j] = (map->map[i][j] == -2) ? 1 : score;
	if ((i - 1 >= 0) && (j + 1 < map->y) && map->map[i - 1][j + 1] == 0)
		map->map[i - 1][j + 1] = (map->map[i][j] == -2) ? 1 : score;
	if ((j - 1 >= 0) && map->map[i][j - 1] == 0)
		map->map[i][j - 1] = (map->map[i][j] == -2) ? 1 : score;
	if ((j - 1 >= 0) && (i + 1 < map->x) && map->map[i + 1][j - 1] == 0)
		map->map[i + 1][j - 1] = (map->map[i][j] == -2) ? 1 : score;
	if ((i + 1 < map->x) && map->map[i + 1][j] == 0)
		map->map[i + 1][j] = (map->map[i][j] == -2) ? 1 : score;
	if ((j + 1 < map->y) && map->map[i][j + 1] == 0)
		map->map[i][j + 1] = (map->map[i][j] == -2) ? 1 : score;
	if ((j + 1 < map->y) && (i + 1 < map->x) && map->map[i + 1][j + 1] == 0)
		map->map[i + 1][j + 1] = (map->map[i][j] == -2) ? 1 : score;
}

void		heat_map(t_P *map)
{
	int score;
	int	target;
	int i;
	int j;
	int k;

	target = -2;
	score = 1;
	k = -1;
	while (++k < map->y)
	{
		i = -1;
		while (++i < map->x)
		{
			j = -1;
			while (++j < map->y)
			{
				if (map->map[i][j] == target)
					fill_map(i, j, score, map);
			}
		}
		target = score;
		score++;
	}
}