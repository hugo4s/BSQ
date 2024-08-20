/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:24:16 by husamuel          #+#    #+#             */
/*   Updated: 2024/08/19 11:01:33 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int verify_map(char *map_path)
{
	if (get_number_of_columns(map_path) < 1 || get_number_of_lines(map_path) < 1)
	{
		ft_prt_error("map error\n");
                return (0);
	}
	if (verify_chars(map_path) == 0 || verify_line_breaks(map_path) == 0)
	{
		ft_prt_error("map error\n");
                return (0);
	}
	if (verify_lines_length(map_path, fd) == 0)
	{
		ft_prt_error("map error\n");
                return (0);
	}
	return(1);
}

int	verify_chars(char *map_path)
{
	char	v;
	char	o;
	int	fd;
	char	*file_buffer;
	int	size_file;
	int	i;
	int	bytes_read;

	v = get_char_void(map_path);
	o = get_char_obst(map_path);
	
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
	        return (0);
	}
	
	size_file = get_size_file(map_path);
	
	go_to_second_line(fd);
	
	file_buffer = malloc(get_size_file(map_path) * sizeof(char));
	if (file_buffer == NULL)
	{
		close(fd);
		return (0);
	}
	
	bytes_read = read(fd, file_buffer, size_file);
        file_buffer[bytes_read] = '\0';
	i = 0;
	while (file_buffer[i])
	{
        	if (file_buffer[i] != v && file_buffer[i] != o && file_buffer[i] != '\n')
			return (1);
		i++;
	}

	close(fd);
	free(file_buffer);
	
	return (1);
}

int	verify_line_end_with_breaks(char *map_path)
{
	int	columns;
	char	*file_buffer;
	int	fd;
	int	size_file;
	int	bytes_read;
	
	columns = get_number_of_columns(map_path);
	
	size_file = get_size_file(map_path);
	
	fd = open(map_path, O_RDONLY);
	
	go_to_second_line(fd);
	
	file_buffer = malloc(size_file * sizeof(char));
	if (file_buffer == NULL)
	{
		close(fd);
		return (1);
	}

	while ((bytes_read = read(fd, &file_buffer, columns)))
	{
		if (file_buffer[bytes_read - 1] != '\n')
		{
			return (1);
		}
	}

	free(file_buffer);
	close(fd);

	return (0);
}

int	verify_each_line(char *map_path)
{
	int	fd;
	int	columns;
	int	lines;
	int	i;
	int	j;
	
	columns = get_number_of_columns(map_path);
	lines = get_number_of_lines(map_path);
	
	fd = open(map_path, O_RDONLY);
	
	go_to_second_line(fd);
	
	i = 0;
	
	while (i < lines)
	{
		j = get_width_each_line(map_path, fd);
		if (columns != j)
			return (1);
		i++;
	}
	close(fd);
	return (0);
}
