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

#ifndef BSQ_H
# define BSQ_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

//get_chars.c
char	get_char_void(char *map_path);
char	get_char_obst(char *map_path);
char	get_char_square(char *map_path);

//read_map.c
int	get_size_file(char *map_path);
void	go_to_second_line(int fd);
int	get_number_of_lines(char *map_path);
int	get_number_of_columns(char *map_path);
int	get_width_each_line(char *argv, int fd);
char	**ft_read_file(char *argv)

//verify_map.c
int	verify_map(char *map_path);
int	verify_chars(char *map_path);
int	verify_line_end_with_breaks(char *map_path);
int	verify_each_line(char *map_path);

//print_solution.c
char	**populate_map(char **map, int rows, int cols, char obst_char, char square_char);
void	print_solution(int i, char **map_path);

//find_solution.c
int	min(int num1, int num2, int num3);
int	**generate_map(int l, int c);
int	*max_square_position(char **map, int rows, int cols, char block_char);

//functions.c
void	ft_putchar(char c);
void	ft_prtstr(char *str);
void	ft_prt_error(char *str);
char	*ft_strcpy(char *dest, char *src);
void	ft_putnbr(int nb);

#endif
