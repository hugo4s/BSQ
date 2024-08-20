#include "bsq.h"

int min(int num1, int num2, int num3) {
    if (num1 <= num2 && num1 >= num3)
        return num1;
    else if (num2 <= num1 && num2 >= num3)
        return num2;
    else
        return num3;
}

int **generate_map(int l, int c) {
    int **gen_map;
    int i;

    i = 0;
    gen_map = malloc(l * sizeof(int*));
    if (gen_map == NULL) {
        return NULL;
    }
    while (i < l) {
        gen_map[i] = malloc(c * sizeof(int));
        if (gen_map[i] == NULL) {
            return NULL;
        }
        i++;
    }
    return gen_map;
}

int *max_square_position(char **map, int rows, int cols, char obst_char) {
    int x;
    int y;
    int **f_m;
    int *largest_value_pos;
	int i;

	f_m = NULL;
	largest_value_pos = malloc(3 * sizeof(int));
    if (largest_value_pos == NULL) {
        return NULL;
    }
    largest_value_pos[2] = 1;
    f_m = generate_map(rows, cols);
    if (f_m == NULL) {
        free(largest_value_pos);
        return NULL;
    }
    x = 0;
    while (x < rows) {
        y = 0;
        while (y < cols) {
            if (map[x][y] == obst_char)
                f_m[x][y] = 0;
            else if (x == 0 || y == 0)
                f_m[x][y] = 1;
            else {
                f_m[x][y] = min(f_m[x - 1][y], f_m[x][y - 1], f_m[x - 1][y - 1]) + 1;
            }

            if (largest_value_pos[2] < f_m[x][y]) {
                largest_value_pos[2] = f_m[x][y];
                largest_value_pos[0] = x;
                largest_value_pos[1] = y;
            }
            y++;
        }
        x++;
    }
	i = 0;
    while (i < rows)
	{
        free(f_m[i]);
		i++;
    }
    free(f_m);
    return largest_value_pos;
}
