#include "BSQ.h"

int main(int argc, char **argv)
{
    int i;

    i = 1;
    if (argc > 1)
    {
        while (i < argc)
        {
            if ((ft_verif_map(argv[i])) == 1)
                return 0;
            else
            {
                ft_print_solutions(i, argv);
            }
            i++;
        }
    }
    else
        return (0);
}