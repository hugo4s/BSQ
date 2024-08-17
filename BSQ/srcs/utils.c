/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:23:49 by husamuel          #+#    #+#             */
/*   Updated: 2024/08/17 18:23:56 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>

int ft_atoi(const char *str) {
    int result = 0;
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result;
}

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_putnbr(int n) {
    char buffer[10];
    int i = 9;
    buffer[10] = '\0';
    if (n == 0) {
        ft_putchar('0');
        return;
    }
    while (n > 0) {
        buffer[i--] = (n % 10) + '0';
        n /= 10;
    }
    while (++i < 10) {
        ft_putchar(buffer[i]);
    }
}

