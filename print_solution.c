/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:17:38 by husamuel          #+#    #+#             */
/*   Updated: 2024/08/20 17:17:41 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**populate_map(char **map, int rows, int cols, char obst_char, char square_char) {
	int	square_first_pos[2];
	int	*square_last_pos;
	int	y;
	int	x;

	square_last_pos = max_square_position(map, rows, cols, obst_char);
	if (square_last_pos == NULL)
		return NULL;
	square_first_pos[0] = square_last_pos[0] - square_last_pos[2] + 1;
	square_first_pos[1] = square_last_pos[1] - square_last_pos[2] + 1;

	y = square_first_pos[1];
	while (y <= square_last_pos[1])
	{
		x = square_first_pos[0];
		while (x <= square_last_pos[0])
		{
			if (x >= 0 && y >= 0 && x < cols && y < rows)
				map[y][x] = square_char;
			x++;
		}
		y++;
	}
	free(square_last_pos);
	return map;
}

void	print_solution(int i, char **map_path)
{
	char	obst_char;
	char	square_char;
	int	fd;
	int	num_of_rows;
	int	num_of_columns;
	int	j;
	char	**map;

	map = NULL;
	j = 0;
	obst_char = ft_get_char_obst(map_path[i]);
	square_char = ft_get_char_full(map_path[i]);
	num_of_rows = ft_get_number_lines(map_path[i]);
	num_of_columns = ft_get_number_columns(map_path[i]);
	fd = open(map_path[i], O_RDONLY);
	if (fd >= 0)
		map = ft_read_file(map_path[i]);
	if (map != NULL)
	{
		if (populate_map(map, num_of_rows, num_of_columns, obst_char, square_char) != NULL)
		{
			while (j < num_of_rows)
			{
				ft_putstr(map[j]);
				ft_putchar('\n');
				j++;
			}
			ft_putchar('\n');
		}
		j = 0;
		while (j < num_of_rows)
		{
			free(map[j]);
			j++;
		}
		free(map);
	}
	close(fd);
}
