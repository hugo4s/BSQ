#include "BSQ.h"

// Função para obter o caractere que representa o espaço vazio no mapa
char ft_get_char_void(char *argv)
{
    int i = 0;
    char *buf;
    int fd;
    char v; // Variável para armazenar o caractere vazio

    // Abre o arquivo em modo de leitura
    fd = open(argv, O_RDONLY);

    // Aloca memória para o buffer que vai armazenar a primeira linha
    if ((buf = malloc(80 * sizeof(char))) == NULL)
        return (0); // Retorna 0 se a alocação de memória falhar

    // Lê a primeira linha do arquivo até encontrar uma nova linha '\n'
    while (read(fd, &buf[i], 1))
    {
        if (buf[i] == '\n')
            break; // Interrompe a leitura quando encontra o caractere '\n'
        i++;
    }

    // O caractere que representa o espaço vazio está na posição i-3 da linha
    v = buf[i - 3];

    // Libera a memória alocada e fecha o arquivo
    free(buf);
    close(fd);

    return (v); // Retorna o caractere que representa o espaço vazio
}

// Função para obter o caractere que representa o obstáculo no mapa
char ft_get_char_obst(char *argv)
{
    int i = 0;
    char *buf;
    int fd;
    char o; // Variável para armazenar o caractere obstáculo

    // Abre o arquivo em modo de leitura
    fd = open(argv, O_RDONLY);

    // Aloca memória para o buffer que vai armazenar a primeira linha
    if ((buf = malloc(80 * sizeof(char))) == NULL)
        return (0); // Retorna 0 se a alocação de memória falhar

    // Lê a primeira linha do arquivo até encontrar uma nova linha '\n'
    while (read(fd, &buf[i], 1))
    {
        if (buf[i] == '\n')
            break; // Interrompe a leitura quando encontra o caractere '\n'
        i++;
    }

    // O caractere que representa o obstáculo está na posição i-2 da linha
    o = buf[i - 2];

    // Libera a memória alocada e fecha o arquivo
    free(buf);
    close(fd);

    return (o); // Retorna o caractere que representa o obstáculo
}

// Função para obter o caractere que representa o preenchimento no mapa
char ft_get_char_full(char *argv)
{
    int i = 0;
    char *buf;
    int fd;
    char p; // Variável para armazenar o caractere de preenchimento

    // Abre o arquivo em modo de leitura
    fd = open(argv, O_RDONLY);

    // Aloca memória para o buffer que vai armazenar a primeira linha
    if ((buf = malloc(80 * sizeof(char))) == NULL)
        return (0); // Retorna 0 se a alocação de memória falhar

    // Lê a primeira linha do arquivo até encontrar uma nova linha '\n'
    while (read(fd, &buf[i], 1))
    {
        if (buf[i] == '\n')
            break; // Interrompe a leitura quando encontra o caractere '\n'
        i++;
    }

    // O caractere que representa o preenchimento está na posição i-1 da linha
    p = buf[i - 1];

    // Libera a memória alocada e fecha o arquivo
    free(buf);
    close(fd);

    return (p); // Retorna o caractere que representa o preenchimento
}

