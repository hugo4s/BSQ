#include "BSQ.h"

int ft_size_file(char *argv)
{
    int size = 0;
    char buf;
    int fd;

    fd = open(argv, O_RDONLY);

    while (read(fd, &buf, 1))
    {
        size++;
    }
    close(fd);
    return (size);
}

int ft_get_number_lines(char *argv)
{
    int i = 0;
    char *buf;
    int nb_l = 0;
    int fd;

    fd = open(argv, O_RDONLY);

    buf = malloc(80 * sizeof(char));
    if (buf == NULL)
        return (0);

    while (read(fd, &buf[i], 1))
    {
        if (buf[i] > '9' || buf[i] < '0')
            break;

        nb_l = nb_l * 10 + (buf[i] - '0');
        i++;
    }

    free(buf);
    close(fd);

    return (nb_l);
}

int ft_get_number_columns(char *argv)
{
    char *buf;
    int j = 0;
    int size_file;
    int fd;

    fd = open(argv, O_RDONLY);

    size_file = ft_size_file(argv);

    ft_get_second_line(fd);

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
    close(fd);

    return (j + 1);
}

void ft_get_second_line(int fd)
{
    int i = 0;
    char *buf;

    buf = malloc(4096 * sizeof(char));
    if (buf == NULL)
        return;

    while (read(fd, &buf[i], 1))
    {
        if (buf[i] == '\n')
            break;
        i++;
    }

}

char **ft_read_file(char *argv)
{
    char **buf;
    int i = 0;
    int fd;
    int c;
    int ret;
    int l;

    c = ft_get_number_columns(argv);
    l = ft_get_number_lines(argv);

    fd = open(argv, O_RDONLY);

    ft_get_second_line(fd);

    buf = malloc(l * sizeof(char*));
    if (buf == NULL)
        return NULL;

    while (i < l)
    {
        buf[i] = malloc(c * sizeof(char));
        if (buf[i] == NULL)
            return NULL;
        i++;
    }

    i = 0;
    while (i < l)
    {
        ret = read(fd, buf[i], c);
        if (ret == -1)
            return NULL; 

        buf[i++][c - 1] = '\0';
    }

    close(fd);

    return (buf);
}

