#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

node_t *init_node(char *data)
{
    node_t *node = malloc(sizeof(node_t));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

void add_element(list_head_t **list, node_t *node)
{
    if ((*list)->end) 
    {
        (*list)->end->next = node;
        (*list)->end = node;
    }
    else  
    {
        (*list)->beg = node;
        (*list)->end = node;
    }
}

int read(list_head_t **list, FILE *f)
{
    char *buf = malloc(sizeof(char));
    ssize_t len = 0;
    size_t len_buf = 0;
    int initialised = 0;
    while ((len = getline(&buf, &len_buf, f)) != -1)
    {
        char *str = strdup(buf);
        str[len - 1] = '\0';  
        node_t *cur_node = init_node(str);
        if (!cur_node)
        {
            free(buf);
            return EALLOC;
        }
        if (!initialised)
        {
            (*list)->beg = cur_node;
            (*list)->end = cur_node;
            initialised = 1;
        }
        add_element(list, cur_node);
    }
    free(buf);

    return EXIT_SUCCESS;
}

void print(list_head_t list)
{
    node_t *ptr = list.beg;
    while (ptr != NULL)
    {
        printf("%s\n", ptr->data);
        ptr = ptr->next;
    }
}

void free_list(list_head_t *list)
{
    node_t *ptr = list->beg;
    while (ptr != NULL)
    {
        node_t *next_ptr = ptr->next;
        free(ptr->data); 
        free(ptr);  
        ptr = next_ptr;
    }
    free(list);
}

void tokenise(list_head_t **list)
{
    node_t *ptr = (*list)->beg;
    while (ptr != NULL)
    {
        node_t *next_ptr = ptr->next;
        char *temp_buf = strdup(ptr->data); 

        char *t = strtok(temp_buf, " ");  
        node_t *beg_chain = NULL;
        node_t *cur_ptr_chain = NULL;

        while (t != NULL)
        {
            node_t *new_node = init_node(strdup(t));  
            if (beg_chain == NULL)
            {
                beg_chain = new_node;
            }
            else
            {
                cur_ptr_chain->next = new_node;
            }
            cur_ptr_chain = new_node;
            t = strtok(NULL, " ");
        }

        if (beg_chain != NULL)
        {
            free(ptr->data); 
            ptr->data = beg_chain->data;
            ptr->next = beg_chain->next; 
        }

        free(temp_buf);
        ptr = next_ptr;
    }
}
