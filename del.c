#include "libft.h"

void    del(void *content)
{
    t_list  *node;

    if(content)
    {
        node = (t_list *)content;
        free(node);
    }
}