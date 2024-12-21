#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"


int main(void)
{
    FILE *f;

    f = fopen("in.txt", "r");
    if (!f)
        return EFOPEN;
    
    list_head_t *list = malloc(sizeof(list_head_t));
    list->beg = NULL;
    list->end = NULL;

    if (read(&list, f) != EXIT_SUCCESS)
    {
        fclose(f);
        return EREAD;
    }
    fclose(f);

    print(*list);

    tokenise(&list);

    print(*list);

    free_list(list);

    return EXIT_SUCCESS;
}
