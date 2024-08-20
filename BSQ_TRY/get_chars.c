/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:03:07 by husamuel          #+#    #+#             */
/*   Updated: 2024/08/19 12:35:34 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char ft_get_char_void(char *map_path)
{
	int	fd;
	char	*first_line;
	int	i;

	fd = open(map_path, O_RDONLY);
	first_line = malloc(80 * sizeof(char));

	if (first_line == NULL)
	{
		return (0);
	}
	i = 0;
	while(read(fd, &first_line[i], 1))
	{
		if(&first_line[i] == '\n')
		{
			break ;
		}
		i++;
	}

	v = first_line[i - 3];

	free(first_line);
	close(fd);

	return (v);	
}

char ft_get_char_obst(char *map_path)
{
	int	fd;
	char	*first_line;
	int	i;
	char	o;

	fd = open(map_path, O_RDONLY);
	
	first_line = malloc(80 * sizeof(char))
	if (first_line == NULL)
	{
		return (0);
	}
	i = 0;
	while(read(fd, &first_line[i], 1))
	{
		if(&first_line[i] == '\n')
		{
			break;
		}
		i++;
	}

	o = first_line[i - 2];
	free(first_line);
	close(fd);
	
	return (o);

}

char ft_get_char_full(char *map_path)
{
	int     fd;
        char    *first_line;
        int     i;
        char    x;

        fd = open(map_path, O_RDONLY);

        first_line = malloc(80 * sizeof(char))
        if (first_line == NULL)
        {
                return (0);
        }
        i = 0;
        while(read(fd, &first_line[i], 1))
        {
                if(&first_line[i] == '\n')
                {
                        break;
                }
                i++;
        }
        x = first_line[i - 1];
        
	free(first_line);
        close(fd);

        return (x);
}
