#include "bsq.h"

char	**populate_map(char **map, int rows, int cols, char obst_char, char square_char)
{
	int	square_first_pos[2];
	int	*square_last_pos;
	int	y;
	int 	x;

	square_last_pos = max_square_position(map, rows, cols, obst_char);
	square_first_pos[0] = square_last_pos[0] - square_last_pos[2];
	square_first_pos[1] = square_last_pos[1] - square_last_pos[2];
	y = square_first_pos[1];
	x = square_first_pos[0];
	while (y <= rows)
	{
		while (x <= cols)
		{
			//preenche a linha a partir da primeira posicao do quadrado com o char
			while (x >= square_first_pos[0] && x >= square_first_pos[0] + square_last_pos[2])
			{
				map[x][y] = square_char;
				x++;
			}
			x++;
		}
		if (y > square_last_pos[1] - square_last_pos[2])
			break ;
		y++;
	}
	return (map)
}

void	print_solution(int i, char **map_path)
{
	char	obst_char;
	char	square_char;
	char	void_char;
	int	fd;
	int	num_of_rows;
	int	num_of_columns;
	int	j;
	
	
	j = 0;
	obst_char = get_char_obst(map_path[i]);
	square_char = get_char_square(map_path[i]);
	void_char = get_char_void(map_path[i]);
	num_of_rows = get_number_of_lines(map_path);
	num_of_columns = get_number_of_columns(map_path)
	
	
	
	fd = open(map_path[i], O_RDONLY);
	
	if (fd >= 0)
	        map = read_file(map_path[i]); //Fazer read_file()
	populate_map(map, num_of_rows, num_of_columns, obst_char, square_char);
	
	while (i < num_of_rows)
	{
        	ft_putstr(map[j]);
        	ft_putchar('\n');
        	j++;
        }

	free(map);
	close(fd);
}
