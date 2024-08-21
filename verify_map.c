#include "bsq.h"

int ft_verif_chars(char *argv)
{
    int i = 0;
    int ret = 0;
    int fd;
    int size_file;
    char *buf;
    char v;
    char o;

    v = ft_get_char_void(argv);
    o = ft_get_char_obst(argv);

    size_file = ft_size_file(argv);

    fd = open(argv, O_RDONLY);

    ft_get_second_line(fd);

    buf = malloc(size_file * sizeof(char));
    if (buf == NULL)
        return (0);

    while ((ret = read(fd, buf, size_file)))
        buf[ret] = '\0';

    while (buf[i])
    {
        if (buf[i] != v && buf[i] != o && buf[i] != '\n')
            return (1);
        i++;
    }

    close(fd);
    free(buf);

    return (0);
}

int ft_get_next_columns(char *argv, int fd)
{
    char *buf;
    int j = 0;
    int size_file;

    size_file = ft_size_file(argv);

    buf = malloc(size_file * sizeof(char));
    if (buf == NULL)
        return (0);

    while (read(fd, &buf[j], 1))
    {
        if (buf[j] == '\n')
            break;
        j++;
    }

    free(buf);

    return (j + 1);
}

int ft_verif_columns(char *argv)
{
    int i = 0;
    int fd;
    int j;
    int c;
    int l;

    c = ft_get_number_columns(argv);
    l = ft_get_number_lines(argv);

    fd = open(argv, O_RDONLY);

    ft_get_second_line(fd);

    while (i < l)
    {
        j = ft_get_next_columns(argv, fd);
        if (j != c)
            return (1);
        i++;
    }

    close(fd);

    return (0);
}

int ft_verif_returns(char *argv)
{
    char *buf;
    int fd;
    int size_file;
    int ret = 0;
    int c;

    c = ft_get_number_columns(argv);

    size_file = ft_size_file(argv);

    fd = open(argv, O_RDONLY);

    ft_get_second_line(fd);

    buf = malloc(size_file * sizeof(char));
    if (buf == NULL)
        return (0);

    while ((ret = read(fd, buf, c)))
    {
        if (buf[ret - 1] != '\n')
            return (1);
    }

    free(buf);
    close(fd);

    return (0);
}

int ft_verif_map(char *argv)
{
    if (ft_get_number_columns(argv) < 1 || ft_get_number_lines(argv) < 1)
    {
        ft_putstr("map error\n");
        return (1);
    }

    if (ft_verif_chars(argv) == 1 || ft_verif_returns(argv) == 1)
    {
        ft_putstr("map error\n");
        return (1);
    }

    if (ft_verif_columns(argv) == 1)
    {
        ft_putstr("map error\n");
        return (1);
    }

    return (0);
}

