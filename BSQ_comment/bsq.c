#include "BSQ.h"

// Função principal que processa os arquivos de mapa passados como argumento
int main(int argc, char **argv)
{
    int i;

    i = 1;
    if (argc > 1) // Verifica se há mais de um argumento
    {
        while (i < argc) // Itera sobre todos os arquivos passados como argumento
        {
            if ((ft_verif_map(argv[i])) == 1) // Verifica se o mapa é válido
                return 0; // Se o mapa for inválido, não faz nada
            else
            {
                ft_print_solutions(i, argv); // Se o mapa for válido, imprime a solução
            }
            i++;
        }
    }
    else
        return (0); // Se não houver argumentos, retorna 0
}
