/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:22:24 by husamuel          #+#    #+#             */
/*   Updated: 2024/08/17 18:22:29 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *read_map(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        return (NULL);
    }
    // Implement reading map logic here
    close(fd);
    return (NULL);
}

int validate_map(char *map) {
    // Implement map validation logic here
    return (1);
}

void free_map(char *map) {
    free(map);
}

