/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:24:28 by husamuel          #+#    #+#             */
/*   Updated: 2024/08/19 10:41:18 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if(argc > 1)
	{
		while(i < argc)
		{
			if(verify_map(argv[i]) == 0)
			{
				return (0);
			}
			else
			{
				print_solutions(i, argv); //Rever nome
			}
			i+;
		}
	}
	else
	{
		return (0);
	}
}
