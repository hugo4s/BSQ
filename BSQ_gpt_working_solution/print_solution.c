/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:17:38 by husamuel          #+#    #+#             */
/*   Updated: 2024/08/20 17:17:41 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char **populate_map(char **map, int rows, int cols, char obst_char, char square_char) {
    int square_first_pos[2];
    int *square_last_pos;
    int y;
    int x;

    square_last_pos = max_square_position(map, rows, cols, obst_char);
    if (square_last_pos == NULL) {
        return NULL;  // Se não houver um quadrado válido
    }

    // Correção do cálculo das posições
    square_first_pos[0] = square_last_pos[1] - square_last_pos[2] + 1;
    square_first_pos[1] = square_last_pos[0] - square_last_pos[2] + 1;

    y = square_first_pos[1];
    while (y <= square_last_pos[0]) {
        x = square_first_pos[0];
        while (x <= square_last_pos[1]) {
            if (x >= 0 && y >= 0 && x < cols && y < rows) {  // Verificação de limites
                map[y][x] = square_char;
            }
            x++;
        }
        y++;
    }

    free(square_last_pos);  // Libera memória alocada para `square_last_pos`
    return map;
}


void print_solution(int i, char **map_path) {
    char obst_char;
    char square_char;
    int fd;
    int num_of_rows;
    int num_of_columns;
    int j = 0;
    int k = 0;
    char **map = NULL;  // Inicializa a variável 'map' com NULL

    obst_char = get_char_obst(map_path[i]);
    square_char = get_char_full(map_path[i]);
    num_of_rows = get_number_lines(map_path[i]);
    num_of_columns = get_number_columns(map_path[i]);

    fd = open(map_path[i], O_RDONLY);
    if (fd >= 0) {
        map = read_file(map_path[i]);
        close(fd);  // Fechar o arquivo após a leitura
    } 

    if (map != NULL) {  // Verifica se 'map' foi inicializado corretamente
        if (populate_map(map, num_of_rows, num_of_columns, obst_char, square_char) != NULL) {
            while (j < num_of_rows) {
                ft_putstr(map[j]);
                ft_putchar('\n');
                j++;
            }
        }
        while (k < num_of_rows) {
            free(map[k]);
            k++;
        }
        free(map);
    }
   }