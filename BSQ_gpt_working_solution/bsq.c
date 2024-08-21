/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:23:15 by husamuel          #+#    #+#             */
/*   Updated: 2024/08/21 11:23:19 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			if ((verify_map(argv[i])) == 1)
				return (0);
			else
			{
				print_solution(i, argv);
				if (argv[i + 1] != NULL)
				{
					ft_putchar('\n');
				}
			}
			i++;
		}
	}
	else
		return (0);
}
