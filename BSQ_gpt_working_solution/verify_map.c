/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:29:44 by husamuel          #+#    #+#             */
/*   Updated: 2024/08/21 18:54:28 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	verify_chars(char *argv)
{
	int		i;
	int		fd;
	char	*buf;

	fd = open(argv, O_RDONLY);
	get_second_line(fd);
	buf = malloc(get_size_file(argv) * sizeof(char));
	if (buf == NULL)
		return (0);
	while (read(fd, buf, get_size_file(argv)))
		buf[get_size_file(argv)] = '\0';
	i = 0;
	while (buf[i++])
	{
		if (buf[i] != gc_void(argv)
			&& buf[i] != gc_obst(argv) && buf[i] != '\n')
		{
			free(buf);
			close(fd);
			return (1);
		}
	}
	close(fd);
	free(buf);
	return (0);
}

int	verify_columns_one_line(char *argv, int fd)
{
	char	*buf;
	int		j;
	int		size_file;

	j = 0;
	size_file = get_size_file(argv);
	buf = malloc(size_file * sizeof(char));
	if (buf == NULL)
		return (0);
	while (read(fd, &buf[j], 1))
	{
		if (buf[j] == '\n')
			break ;
		j++;
	}
	free(buf);
	return (j + 1);
}

int	verify_columns_all_lines(char *argv)
{
	int		i;
	int		fd;
	int		j;
	int		c;
	int		l;

	i = 0;
	c = get_number_columns(argv);
	l = get_number_lines(argv);
	fd = open(argv, O_RDONLY);
	get_second_line(fd);
	while (i < l)
	{
		j = verify_columns_one_line(argv, fd);
		if (j != c)
			return (1);
		i++;
	}
	close(fd);
	return (0);
}

int	verify_end_breaks(char *argv)
{
	char	*buf;
	int		fd;
	int		size_file;
	int		ret;
	int		c;

	c = get_number_columns(argv);
	size_file = get_size_file(argv);
	fd = open(argv, O_RDONLY);
	get_second_line(fd);
	buf = malloc(size_file * sizeof(char));
	if (buf == NULL)
		return (0);
	while (read(fd, buf, c))
	{
		if (buf[ret - 1] != '\n')
			return (1);
	}
	free(buf);
	close(fd);
	return (0);
}

int	verify_map(char *argv)
{
	if (get_number_columns(argv) < 1 || get_number_lines(argv) < 1)
	{
		ft_putstr("map error\n");
		return (1);
	}
	if (verify_chars(argv) == 1 || verify_end_breaks(argv) == 1)
	{
		ft_putstr("map error\n");
		return (1);
	}
	if (verify_columns_all_lines(argv) == 1)
	{
		ft_putstr("map error\n");
		return (1);
	}
	return (0);
}
