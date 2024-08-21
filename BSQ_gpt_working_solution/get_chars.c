/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:18:19 by husamuel          #+#    #+#             */
/*   Updated: 2024/08/21 11:18:23 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	get_char_void(char *argv)
{
	int		i;
	char	*buf;
	int		fd;
	char	v;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	buf = malloc(80 * sizeof(char));
	if (buf == NULL)
		return (0);
	while (read(fd, &buf[i], 1))
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	v = buf[i - 3];
	free(buf);
	close(fd);
	return (v);
}

char	get_char_obst(char *argv)
{
	int		i;
	char	*buf;
	int		fd;
	char	o;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	buf = malloc(80 * sizeof(char));
	if (buf == NULL)
		return (0);
	while (read(fd, &buf[i], 1))
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	o = buf[i - 2];
	free(buf);
	close(fd);
	return (o);
}

char	get_char_full(char *argv)
{
	int		i;
	char	*buf;
	int		fd;
	char	p;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	buf = malloc(80 * sizeof(char));
	if (buf == NULL)
		return (0);
	while (read(fd, &buf[i], 1))
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	p = buf[i - 1];
	free(buf);
	close(fd);
	return (p);
}