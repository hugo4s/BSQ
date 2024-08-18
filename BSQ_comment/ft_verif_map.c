#include "BSQ.h"

// Verifica se os caracteres no mapa são válidos
int ft_verif_chars(char *argv)
{
    int i = 0;
    int ret = 0;
    int fd;
    int size_file;
    char *buf;
    char v; // Caractere vazio (área aberta)
    char o; // Caractere obstáculo

    // Obtém os caracteres "void" e "obstáculo" do arquivo
    v = ft_get_char_void(argv);
    o = ft_get_char_obst(argv);

    // Obtém o tamanho do arquivo
    size_file = ft_size_file(argv);

    // Abre o arquivo em modo de leitura
    fd = open(argv, O_RDONLY);

    // Pula a primeira linha para começar a ler a matriz de caracteres
    ft_get_second_line(fd);

    // Aloca memória para o buffer de leitura
    buf = malloc(size_file * sizeof(char));
    if (buf == NULL)
        return (0); // Retorna 0 se a alocação falhar

    // Lê o restante do arquivo e armazena no buffer
    while ((ret = read(fd, buf, size_file)))
        buf[ret] = '\0'; // Adiciona o caractere nulo no final da leitura

    // Verifica se todos os caracteres no mapa são válidos
    while (buf[i])
    {
        // Se encontrar um caractere que não seja vazio, obstáculo ou nova linha, retorna erro
        if (buf[i] != v && buf[i] != o && buf[i] != '\n')
            return (1);
        i++;
    }

    // Fecha o arquivo e libera a memória
    close(fd);
    free(buf);

    return (0); // Retorna 0 se todos os caracteres são válidos
}

// Obtém o número de caracteres até a próxima nova linha (indicando o fim de uma coluna)
int ft_get_next_columns(char *argv, int fd)
{
    char *buf;
    int j = 0;
    int size_file;

    // Obtém o tamanho do arquivo
    size_file = ft_size_file(argv);

    // Aloca memória para o buffer de leitura
    buf = malloc(size_file * sizeof(char));
    if (buf == NULL)
        return (0); // Retorna 0 se a alocação falhar

    // Lê o arquivo até encontrar uma nova linha
    while (read(fd, &buf[j], 1))
    {
        if (buf[j] == '\n')
            break;
        j++;
    }

    // Libera a memória alocada
    free(buf);

    // Retorna o número de caracteres na linha (número de colunas)
    return (j + 1);
}

// Verifica se todas as linhas têm o mesmo número de colunas
int ft_verif_columns(char *argv)
{
    int i = 0;
    int fd;
    int j;
    int c; // Número de colunas esperado
    int l; // Número de linhas esperado

    // Obtém o número de colunas e linhas do mapa
    c = ft_get_number_columns(argv);
    l = ft_get_number_lines(argv);

    // Abre o arquivo em modo de leitura
    fd = open(argv, O_RDONLY);

    // Pula a primeira linha para começar a ler a matriz de caracteres
    ft_get_second_line(fd);

    // Verifica cada linha do arquivo para garantir que todas têm o mesmo número de colunas
    while (i < l)
    {
        j = ft_get_next_columns(argv, fd);
        if (j != c) // Se uma linha tiver um número diferente de colunas, retorna erro
            return (1);
        i++;
    }

    // Fecha o arquivo
    close(fd);

    return (0); // Retorna 0 se todas as linhas têm o mesmo número de colunas
}

// Verifica se todas as linhas terminam com um caractere de nova linha '\n'
int ft_verif_returns(char *argv)
{
    char *buf;
    int fd;
    int size_file;
    int ret = 0;
    int c; // Número de colunas

    // Obtém o número de colunas
    c = ft_get_number_columns(argv);

    // Obtém o tamanho do arquivo
    size_file = ft_size_file(argv);

    // Abre o arquivo em modo de leitura
    fd = open(argv, O_RDONLY);

    // Pula a primeira linha para começar a ler a matriz de caracteres
    ft_get_second_line(fd);

    // Aloca memória para o buffer de leitura
    buf = malloc(size_file * sizeof(char));
    if (buf == NULL)
        return (0); // Retorna 0 se a alocação falhar

    // Verifica cada linha para garantir que termina com '\n'
    while ((ret = read(fd, buf, c)))
    {
        if (buf[ret - 1] != '\n') // Se a linha não terminar com '\n', retorna erro
            return (1);
    }

    // Libera a memória alocada e fecha o arquivo
    free(buf);
    close(fd);

    return (0); // Retorna 0 se todas as linhas terminam corretamente com '\n'
}

// Função principal para verificar a validade do mapa
int ft_verif_map(char *argv)
{
    // Verifica se o número de colunas ou linhas é menor que 1, o que é inválido
    if (ft_get_number_columns(argv) < 1 || ft_get_number_lines(argv) < 1)
    {
        ft_putstr("map error\n");
        return (1);
    }

    // Verifica se os caracteres no mapa são válidos e se todas as linhas terminam com '\n'
    if (ft_verif_chars(argv) == 1 || ft_verif_returns(argv) == 1)
    {
        ft_putstr("map error\n");
        return (1);
    }

    // Verifica se todas as linhas têm o mesmo número de colunas
    if (ft_verif_columns(argv) == 1)
    {
        ft_putstr("map error\n");
        return (1);
    }

    // Se tudo estiver correto, retorna 0
    return (0);
}

