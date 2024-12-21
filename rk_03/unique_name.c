#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "unique_name.h"
#include "const.h"

int compare_names(const void *a, const void *b)
{
    unique_name_t *name_a = (unique_name_t *)a;
    unique_name_t *name_b = (unique_name_t *)b;
    int res = strcmp(name_a->name, name_b->name);
    return res;
}

int add_name(unique_name_t **arr, size_t *size, size_t *capacity, const char *name)
{
    for (size_t i = 0; i < *size; i++)
    {
        if (strcmp((*arr)[i].name, name) == 0)
        {
            (*arr)[i].amount_in_file++;
            return 0;
        }
    }

    if (*size == *capacity)
    {
        (*capacity) *= 2;
        unique_name_t *new_arr = realloc(*arr, *capacity * sizeof(unique_name_t));
        if (!new_arr)
            return EALLOC;
        *arr = new_arr;
    }

    (*arr)[*size].name = strdup(name);
    if (!(*arr)[*size].name)
        return EALLOC;
    (*arr)[*size].amount_in_file = 1;
    (*size)++;

    return 0;
}


void free_arr(unique_name_t **arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
        free((*arr)[i].name);
    free(*arr);
}

void print_arr(FILE *f, unique_name_t **arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
        fprintf(f, "%s: %d\n", (*arr)[i].name, (*arr)[i].amount_in_file);
}

int read_unique_arr(unique_name_t **arr, size_t *size, size_t *capacity, FILE *f)
{
    char *line = NULL;
    ssize_t read;
    size_t len = 0;
    while ((read = getline(&line, &len, f)) != -1)
    {   
        line[read - 1] = '\0';
        if (add_name(arr, size, capacity, line) != 0)
        {
            fclose(f);
            free(line);
            free_arr(arr, *size);
            return EALLOC;
        }
    }
    free(line);
    return EXIT_SUCCESS;
}
