#include "BSQ.h"

// Função que preenche o mapa com o maior quadrado possível
char **ft_fill_map(char **map, int c, int l, char o, char p)
{
    int i;
    int j;
    int length; // Tamanho do maior quadrado encontrado
    int pos; // Posição do canto inferior direito do maior quadrado

    // Obtém o tamanho e a posição do maior quadrado no mapa
    length = ft_biggest_square(map, c, l, o);
    pos = ft_find_position_square(map, c, l, o);

    // Calcula a linha inicial (superior) onde o quadrado começa
    i = (pos / (c - 1)) - length + 1;

    // Preenche o quadrado no mapa com o caractere 'p'
    while (i < (pos / (c - 1)) + 1)
    {
        j = (pos % (c - 1)) - length + 1; // Calcula a coluna inicial (esquerda)
        while (j < (pos % (c - 1)) + 1)
        {
            map[i][j] = p; // Preenche a posição atual com 'p'
            j++;
        }
        i++;
    }
    return (map); // Retorna o mapa preenchido
}

// Função que imprime a solução final para o mapa
void ft_print_solutions(int i, char **argv)
{
    int fd;
    char **map = NULL;
    int j;
    int c; // Número de colunas no mapa
    int l; // Número de linhas no mapa
    char o; // Caractere que representa os obstáculos
    char p; // Caractere que representa o preenchimento do quadrado

    j = 0;

    // Obtém os caracteres e dimensões do mapa
    o = ft_get_char_obst(argv[i]);
    p = ft_get_char_full(argv[i]);
    c = ft_get_number_columns(argv[i]);
    l = ft_get_number_lines(argv[i]);

    fd = open(argv[i], O_RDONLY); // Abre o arquivo do mapa para leitura
    if (fd >= 0)
    {
        map = ft_read_file(argv[i]); // Lê o conteúdo do arquivo para a matriz 'map'
    }

    // Preenche o mapa com o maior quadrado encontrado
    ft_fill_map(map, c, l, o, p);

    // Imprime o mapa modificado
    while (j < l)
    {
        ft_putstr(map[j]);
        ft_putchar('\n');
        j++;
    }

    // Libera a memória alocada para o mapa
    free(map);
    close(fd); // Fecha o arquivo do mapa
}


