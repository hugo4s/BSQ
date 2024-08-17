/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:24:04 by husamuel          #+#    #+#             */
/*   Updated: 2024/08/17 18:24:09 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
#define BSQ_H

// Function declarations
char *read_map(const char *filename);
int validate_map(char *map);
void free_map(char *map);
void print_map_with_square(char *map);
void init_square_matrix(int **matrix, int rows, int cols);
void update_square_matrix(int **matrix, char *map, int rows, int cols);
void calculate_largest_square(int **matrix, int *size, int *x, int *y);
int ft_atoi(const char *str);
void ft_putchar(char c);
void ft_putnbr(int n);

#endif

