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
	if (verify_lines_length(map_path) == 0)
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
	
	ft_get_second_line(fd);
	
	file_buffer = malloc(get_size_file(map_path) * sizeof(char));
	if (file_buffer == NULL)
	{
		close(fd);
		return (0);
	}
	
	bytes_read = read(fd, file_buffer, size_file))
        file_buffer[bytes_read] = '\0';
	i = 0;
	while (buf[i])
	{
        	if (buf[i] != v && buf[i] != o && buf[i] != '\n')
			return (1);
		i++;
	}

	close(fd);
	free(file_buffer);
	
	return (1);
}

int	verify_line_breaks(char *map_path)
{
	int	collumns;
	char	*file_buffer;
	int	fd;
	int	size_file;
	int	bytes_read;
	
	columns = get_number_of_columns(map_path);
	
	size_file = ft_size_file(map_path);
	
	fd = open(argv, O_RDONLY);
	
	go_to_second_line(fd);
	
	file_buffer = malloc(size_file * sizeof(char));
	if (bufer == NULL)
	{
		close(fd);
		return (1);
	}
	
	while ((bytes_read = read(fd, file_buffer, collumns)))
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

int	verify_columns_length(map_path)
{
	int	fd;
	int	columns;
	int	lines;
	int	i;
	
	columns = get_number_of_columns();
	lines = get_number_of_lines
	
	fd = open(man_path);
	
	go_to_second_line(fd);
	
	i = 0;
	
	while (i < lines)
	{
		if ()
	}
}

int	length_of_line(char *man_path, int fd)
{
	int	size_file;
	char	*buffer;
	int	i;
	
	size_file = get_size_file(man_path);
	
	buffer = malloc(size_file * sizeof(char));
	if (buffer == NULL)
	{
		return (0);
	}
	
	while (read(fd, &buffer[i], 1))
	{
		if (buffer[i] == '\n')
		{
			break;
		}
		i++;
	}
	free(buffer);
	return (i + 1;)
}


