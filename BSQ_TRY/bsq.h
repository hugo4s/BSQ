/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:01:15 by husamuel          #+#    #+#             */
/*   Updated: 2024/08/19 18:05:26 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef
# define BSQ_H

#include <unistd.h>
#include <stdlib.h>

//get_chars.c
char ft_get_char_void(char *map_path);
char ft_get_char_obst(char *map_path);
char ft_get_char_full(char *map_path);

//read_map.c
int	get_size_file(map_path);
void	go_to_second_line(int fd);
int	get_number_of_lines(map_path);
int	get_number_of_columns(map_path);

//verify_map.c
int verify_map(char *map_path);
int	verify_chars(char *map_path);
int	verify_line_breaks(char *map_path);
int	verify_columns_length(map_path);
int	length_of_line(char *man_path, int fd);


#endif
