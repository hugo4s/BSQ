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
char ft_get_char_void(char *argv);
char ft_get_char_obst(char *argv);
char ft_get_char_full(char *argv);

//read_map.c
int ft_size_file(char *argv);
int ft_get_number_lines(char *argv);
int ft_get_number_columns(char *argv);
void ft_get_second_line(int fd);
char **ft_read_file(char *argv);

//verify_map.c
int ft_verif_map(char *argv);
int ft_get_next_columns(char *argv, int fd);
int ft_verif_columns(char *argv);
int ft_verif_returns(char *argv);
int ft_verif_chars(char *argv);

//print_solution.c
char	**populate_map(char **map, int rows, int cols, char obst_char, char square_char);
void	print_solution(int i, char **map_path);

//find_solution.c
int	min(int num1, int num2, int num3);
int	**generate_map(int l, int c);
int	*max_square_position(char **map, int rows, int cols, char block_char);

//functions.c
void		ft_putnbr(int nb);
void		ft_putstr(char *str);
void		ft_putchar(char c);
char		*ft_strcpy(char *dest, char *src);
int		ft_strlen(char *str);

#endif
