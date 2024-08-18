#include "BSQ.h"

// Função que calcula o tamanho do arquivo em bytes.
int ft_size_file(char *argv)
{
    int size = 0;
    char buf;
    int fd;
    // Abre o arquivo em modo de leitura.
    fd = open(argv, O_RDONLY);

    // Lê o arquivo byte a byte e incrementa o contador `size`.
    while (read(fd, &buf, 1))
    {
        size++;
    }
    // Libera a memória alocada e fecha o arquivo.
    close(fd);
    return (size);
}

// Função que obtém o número de linhas (número de linhas da matriz) do arquivo.
int ft_get_number_lines(char *argv)
{
    int i = 0;
    char *buf;
    int nb_l = 0;
    int fd;

    // Abre o arquivo em modo de leitura.
    fd = open(argv, O_RDONLY);

    buf = malloc(80 * sizeof(char));
    if (buf == NULL)
        return (0);

    // Lê a primeira linha (até encontrar um caractere que não seja um número).
    while (read(fd, &buf[i], 1))
    {
        // Se o caractere não for um número, interrompe o loop.
        if (buf[i] > '9' || buf[i] < '0')
            break;

        // Converte o caractere para número e acumula em `nb_l`.
        nb_l = nb_l * 10 + (buf[i] - '0');
        i++;
    }

    free(buf);
    close(fd);

    return (nb_l);
}

// Função que obtém o número de colunas (comprimento de cada linha) do arquivo.
int ft_get_number_columns(char *argv)
{
    char *buf;
    int j = 0;
    int size_file;
    int fd;

    // Abre o arquivo em modo de leitura.
    fd = open(argv, O_RDONLY);

    // Obtém o tamanho do arquivo em bytes.
    size_file = ft_size_file(argv);

    // Avança o ponteiro do arquivo para a segunda linha.
    ft_get_second_line(fd);

    // Usa -se o temanho do arquivo embora só queiramos uma linha para dar que sobra
    buf = malloc(size_file * sizeof(char));
    if (buf == NULL)
        return (0);

    // Lê a segunda linha do arquivo e conta o número de colunas (caracteres antes do '\n').
    while (read(fd, &buf[j], 1))
    {
        if (buf[j] == '\n')
            break;
        j++;
    }

    free(buf);
    close(fd);

    // Retorna o número de colunas (incrementado em 1 para incluir o '\n').
    return (j + 1);
}

// Função que avança o ponteiro do arquivo para a segunda linha.
void ft_get_second_line(int fd)
{
    int i = 0;
    char *buf;

    // Aloca um buffer de 4096 bytes (tamanho máximo para uma linha).
    buf = malloc(4096 * sizeof(char));
    if (buf == NULL)
        return;  // Retorna se a alocação falhar.

    // Lê o arquivo até encontrar o primeiro '\n', indicando o fim da primeira linha.
    while (read(fd, &buf[i], 1))
    {
        if (buf[i] == '\n')
            break;
        i++;
    }

    // O buffer não é liberado explicitamente aqui, o que pode causar vazamento de memória.
}

// Função que lê o conteúdo do arquivo e armazena em uma matriz de caracteres (mapa).
char **ft_read_file(char *argv)
{
    char **buf;
    int i = 0;
    int fd;
    int c;
    int ret;
    int l;

    // Obtém o número de colunas e linhas.
    c = ft_get_number_columns(argv);
    l = ft_get_number_lines(argv);

    // Abre o arquivo em modo de leitura.
    fd = open(argv, O_RDONLY);

    // Avança o ponteiro do arquivo para a segunda linha.
    ft_get_second_line(fd);

    // Aloca memória para a matriz de ponteiros (cada ponteiro aponta para uma linha).
    buf = malloc(l * sizeof(char*));
    if (buf == NULL)
        return NULL;

    // Aloca memória para cada linha da matriz.
    while (i < l)
    {
        buf[i] = malloc(c * sizeof(char));
        if (buf[i] == NULL)
            return NULL;  // Retorna NULL se a alocação falhar.
        i++;
    }

    // Reinicia o contador `i` para ler as linhas do arquivo.
    i = 0;
    while (i < l)
    {
        // Lê uma linha do arquivo e armazena em `buf[i]`.
        ret = read(fd, buf[i], c);
        if (ret == -1)
            return NULL; 

        // Adiciona o caractere nulo (`\0`) ao final da linha para marcar o fim da string.
        buf[i++][c - 1] = '\0';
    }

    close(fd);

    // Retorna a matriz de caracteres que representa o mapa.
    return (buf);
}

