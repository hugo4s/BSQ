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

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char		get_char_void(char *argv);
char		get_char_obst(char *argv);
char		get_char_full(char *argv);

int			get_size_file(char *argv);
int			get_number_lines(char *argv);
int			get_number_columns(char *argv);
void		get_second_line(int fd);
char		**read_file(char *argv);

int			verify_map(char *argv);
int			verify_columns_one_line(char *argv, int fd);
int			verify_columns_all_lines(char *argv);
int			verify_end_breaks(char *argv);
int			verify_chars(char *argv);

char	**populate_map(char **map, int rows, int cols, char obst_char, char square_char);
void			print_solution(int i, char **map_path);

int	min(int num1, int num2, int num3);
int	**generate_map(int l, int c);
int	*max_square_position(char **map, int rows, int cols, char block_char);

void		ft_putnbr(int nb);
void		ft_putstr(char *str);
void		ft_putchar(char c);
char		*ft_strcpy(char *dest, char *src);
int		ft_strlen(char *str);

#endif
