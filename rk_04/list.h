#include <stdio.h>
#ifndef LIST_H__
#define LIST_H__
#define EXIT_SUCCESS 0

#define EALLOC -1
#define EFOPEN -2
#define EREAD -3

typedef struct node_t 
{
    struct node_t *next;
    char *data;
} node_t;

typedef struct 
{
    node_t *beg;
    node_t *end;
} list_head_t;


node_t *init_node(char *data);
void add_element(list_head_t **list, node_t *node);
int read(list_head_t **list, FILE *f);
void print(list_head_t list);
void free_list(list_head_t *list);
void tokenise(list_head_t **list);

#endif
