#ifndef UNIQUE_NAME_H__
#define UNIQUE_NAME_H__
typedef struct
{
    char *name;
    int amount_in_file;
} unique_name_t;

int compare_names(const void *a, const void *b);
int add_name(unique_name_t **arr, size_t *size, size_t *capacity, const char *name);
void free_arr(unique_name_t **arr, size_t size);
void print_arr(FILE *f, unique_name_t **arr, size_t size);
int read_unique_arr(unique_name_t **arr, size_t *size, size_t *capacity, FILE *f);

#endif
