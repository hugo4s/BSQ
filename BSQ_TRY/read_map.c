/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:55:14 by husamuel          #+#    #+#             */
/*   Updated: 2024/08/19 12:56:19 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	get_size_file(map_path)
{
	int	fd;
	char	temp_buf;
	int	size;
	
	fd = open(man_path, O_RDONLY);
	
	while(read(fd, &buf_temp, 1))
	{
		size++;
	}
	
	close(fd);
	return (size)
}

void	go_to_second_line(int fd)
{
	char *max_line_buffer;
	int	i;
	
	i = 0;
	max_line_buffer = malloc(4098 * sizeof(char));
	if (max_line_buffer == NULL)
	{
		return;
	}
	while(read(fd, &max_line_buffer[i], 1))
	{
		if(max_line_buffer[i] == '\n')
		{
			break ;
		}
		i++;
	}
}

int	get_number_of_lines(map_path)
{
	int	fd;
	char	*buffer;
	int	i;
	int	number_of_lines;
	
	fd = open(map_path, O_RDONLY);
	
	buffer = malloc(80 * sizeof(char));
	if (buf == NULL)
	{
		return (0);
	}
	
	i = 0;
	while ( read(fd, &buffer[i], 1))
	{
		if (buffer[i] > '9' || buffer[i] < '0')
		{
			break;
		}
		number_of_lines = number_of_lines * 10 + (buffer[i] - '0');
		i++;
	}
	
	free(buffer);
	close(fd);
	
	return (number_of_lines);
}

int	get_number_of_columns(map_path)
{
	int	fd;
	char	*buffer;
	int	i;
	int	size_file;
	
	fd = open(map_path, O_RDONLY);
	
	size_file = get_size_file(map_path);
	
	go_to_second_line(fd)
	
	buffer = malloc(sizeof(char) * size_file(man_path));
	if (buffer == NULL)
	{
		return (0);	
	}
	i = 0;
	while (read(fd, &buffer[i], 1))
	{
		if (buffer[i] == '\n')
		{
			break;
		}
		i++;
	}
	
	free(buffer);
	close(fd);
	
	return (i + 1);	
}

//Verificar e alterar
char **ft_read_file(char *argv)
{
    char **buf;
    int i = 0;
    int fd;
    int c;
    int ret;
    int l;

    c = get_number_columns(argv);
    l = get_number_lines(argv);

    fd = open(argv, O_RDONLY);

    get_second_line(fd);

    buf = malloc(l * sizeof(char*));
    if (buf == NULL)
        return NULL;

    while (i < l)
    {
        buf[i] = malloc(c * sizeof(char));
        if (buf[i] == NULL)
            return NULL;
        i++;
    }

    i = 0;
    while (i < l)
    {
        ret = read(fd, buf[i], c);
        if (ret == -1)
            return NULL; 

        buf[i++][c - 1] = '\0';
    }

    close(fd);

    return (buf);
}

int	get_width_each_line(char *argv, int fd)
{
    char *buf;
    int j = 0;
    int size_file;

    size_file = ft_size_file(argv);

    buf = malloc(size_file * sizeof(char));
    if (buf == NULL)
        return (0);

    while (read(fd, &buf[j], 1))
    {
        if (buf[j] == '\n')
            break;
        j++;
    }

    free(buf);

    return (j + 1);
}
