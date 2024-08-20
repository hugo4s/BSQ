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
}