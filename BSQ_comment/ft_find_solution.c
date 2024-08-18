#include "BSQ.h"

// Função para encontrar o menor valor entre três inteiros
int ft_min(int a, int b, int c)
{
    // Verifica qual dos três valores é o menor e o retorna
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

// Função para gerar um mapa 2D de inteiros com 'l' linhas e 'c' colunas
int **ft_generate_map(int l, int c)
{
    int **map2;
    int i;

    i = 0;
    // Aloca memória para um array de ponteiros, onde cada ponteiro representa uma linha do mapa
    if ((map2 = malloc(l * sizeof(int*))) == NULL)
        return NULL; // Retorna NULL se a alocação falhar

    // Para cada linha, aloca um array de inteiros que representará as colunas
    while (i < l)
    {
        if ((map2[i] = malloc(c * sizeof(int))) == NULL)
            return NULL; // Retorna NULL se a alocação falhar
        i++;
    }
    return (map2); // Retorna o mapa 2D alocado
}

// Função para encontrar o tamanho do maior quadrado de espaços vazios no mapa
int ft_biggest_square(char **map, int c, int l, char o)
{
    int i;
    int j;
    int **c_m = NULL; // Matriz de inteiros usada para calcular o tamanho dos quadrados
    int count_max; // Variável para armazenar o tamanho do maior quadrado encontrado

    i = 0;
    count_max = 0;
    c_m = ft_generate_map(l, c); // Gera a matriz 2D para armazenar os tamanhos dos quadrados
    while (i < l)
    {
        j = 0;
        while (j < c - 1)
        {
            if (map[i][j] == o) // Se o caractere atual é um obstáculo
                c_m[i][j] = 0; // O tamanho do quadrado é 0
            else if (i == 0 || j == 0)
                c_m[i][j] = 1; // Se está na primeira linha ou coluna, o maior quadrado possível é de tamanho 1
            else
                c_m[i][j] = ft_min(c_m[i-1][j], c_m[i][j-1], c_m[i-1][j-1]) + 1; // Calcula o tamanho do quadrado
            if (c_m[i][j] > count_max)
                count_max = c_m[i][j]; // Atualiza o tamanho do maior quadrado encontrado
            j++;
        }
        i++;
    }
    free(c_m); // Libera a memória alocada para a matriz
    return (count_max); // Retorna o tamanho do maior quadrado
}

// Função para encontrar a posição do maior quadrado de espaços vazios no mapa
int ft_find_position_square(char **map, int c, int l, char o)
{
    int i;
    int j;
    int **c_m = NULL; // Matriz de inteiros usada para calcular o tamanho dos quadrados
    int count_max; // Variável que armazena o tamanho do maior quadrado encontrado
    int p; // Variável que armazenará a posição do quadrado

    i = 0;
    p = 0;
    count_max = ft_biggest_square(map, c, l, o); // Encontra o tamanho do maior quadrado
    c_m = ft_generate_map(l, c); // Gera a matriz 2D para armazenar os tamanhos dos quadrados
    while (i < l)
    {
        j = 0;
        while (j < c - 1)
        {
            if (map[i][j] == o) // Se o caractere atual é um obstáculo
                c_m[i][j] = 0; // O tamanho do quadrado é 0
            else if (i == 0 || j == 0)
                c_m[i][j] = 1; // Se está na primeira linha ou coluna, o maior quadrado possível é de tamanho 1
            else
                c_m[i][j] = ft_min(c_m[i-1][j], c_m[i][j-1], c_m[i-1][j-1]) + 1; // Calcula o tamanho do quadrado
            if (c_m[i][j] == count_max)
            {
                p = i * (c - 1) + j; // Calcula a posição do quadrado na matriz 1D
                break; // Interrompe o loop ao encontrar a posição do maior quadrado
            }
            j++;
        }
        i++;
    }
    free(c_m); // Libera a memória alocada para a matriz
    return (p); // Retorna a posição do maior quadrado
}

