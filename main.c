#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "const.h"
#include "unique_name.h"

int main(void)
{
    size_t capacity = 1;
    FILE *f;
    size_t len = 0;
    size_t size = 0;

    unique_name_t *arr = malloc(capacity * sizeof(unique_name_t));

    if (!arr)
        return EALLOC;

    f = fopen("in.txt", "r");
    if (!f)
    {
        free(arr);
        return EFOPEN;
    }
    read_unique_arr(&arr, &size, &capacity, f);
    fclose(f);

    qsort(arr, size, sizeof(unique_name_t), compare_names);

    f = fopen("out.txt", "w");
    if (!f)
    {
        free_arr(&arr, size);
        return EFOPEN;
    }

    print_arr(f, &arr, size);

    free_arr(&arr, size);
    fclose(f);

    return EXIT_SUCCESS;
}
