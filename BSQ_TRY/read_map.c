/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:55:14 by husamuel          #+#    #+#             */
/*   Updated: 2024/08/19 12:56:19 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// Função para obter o tamanho do arquivo
int get_size_file(char *map_path) {
    int fd;
    char buf_temp;
    int size = 0;

    fd = open(map_path, O_RDONLY);
    if (fd < 0)
        return 0;

    while (read(fd, &buf_temp, 1)) {
        size++;
    }

    close(fd);
    return (size);
}

// Função para pular para a segunda linha do arquivo
void go_to_second_line(int fd) {
    char *max_line_buffer;
    int i;

    i = 0;
    max_line_buffer = malloc(4098 * sizeof(char));
    if (max_line_buffer == NULL) {
        return;
    }
    while (read(fd, &max_line_buffer[i], 1)) {
        if (max_line_buffer[i] == '\n') {
            break;
        }
        i++;
    }
    free(max_line_buffer);
}

// Função para obter o número de linhas do arquivo
int get_number_of_lines(char *map_path) {
    int fd;
    char *buffer;
    int i = 0;
    int number_of_lines = 0;

    fd = open(map_path, O_RDONLY);
    if (fd < 0)
        return 0;

    buffer = malloc(80 * sizeof(char));
    if (buffer == NULL) {
        return 0;
    }

    while (read(fd, &buffer[i], 1)) {
        if (buffer[i] > '9' || buffer[i] < '0') {
            break;
        }
        number_of_lines = number_of_lines * 10 + (buffer[i] - '0');
        i++;
    }

    free(buffer);
    close(fd);

    return (number_of_lines);
}

// Função para obter o número de colunas do arquivo
int get_number_of_columns(char *map_path) {
    int fd;
    char *buffer;
    int i = 0;
    int size_file;

    fd = open(map_path, O_RDONLY);
    if (fd < 0)
        return 0;

    size_file = get_size_file(map_path);
    go_to_second_line(fd);

    buffer = malloc(sizeof(char) * size_file);
    if (buffer == NULL) {
        return 0;    
    }
    while (read(fd, &buffer[i], 1)) {
        if (buffer[i] == '\n') {
            break;
        }
        i++;
    }

    free(buffer);
    close(fd);

    return (i + 1);    
}

// Função para ler o arquivo e armazená-lo em uma matriz
char **ft_read_file(char *argv) {
    char **buf;
    int i = 0;
    int fd;
    int c;
    int ret;
    int l;

    c = get_number_of_columns(argv);  // Corrigido para chamar a função correta
    l = get_number_of_lines(argv);  // Corrigido para chamar a função correta

    fd = open(argv, O_RDONLY);

    go_to_second_line(fd);  // Corrigido para chamar a função correta

    buf = malloc(l * sizeof(char*));
    if (buf == NULL)
        return NULL;

    while (i < l) {
        buf[i] = malloc(c * sizeof(char));
        if (buf[i] == NULL)
            return NULL;
        i++;
    }

    i = 0;
    while (i < l) {
        ret = read(fd, buf[i], c);
        if (ret == -1)
            return NULL; 

        buf[i++][c - 1] = '\0';
    }

    close(fd);

    return (buf);
}

int get_width_each_line(char *argv) {
    char *buf;
    int j = 0;
    int size_file;
    int fd;

    fd = open(argv, O_RDONLY);

    size_file = get_size_file(argv);

    go_to_second_line(fd);

    buf = malloc(size_file * sizeof(char));
    if (buf == NULL)
        return (0);

    while (read(fd, &buf[j], 1)) {
        if (buf[j] == '\n')
            break;
        j++;
    }

    free(buf);
    close(fd);

    return (j + 1);
}
