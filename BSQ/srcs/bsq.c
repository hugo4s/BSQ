/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:22:02 by husamuel          #+#    #+#             */
/*   Updated: 2024/08/17 18:22:06 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        write(2, "Usage: ./bsq <file1> [file2 ...]\n", 32);
        return (1);
    }

    for (int i = 1; i < argc; i++) {
        char *map = read_map(argv[i]);
        if (validate_map(map)) {
            print_map_with_square(map);
        } else {
            write(2, "map error\n", 10);
        }
        free(map);
    }
    return (0);
}

