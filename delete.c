#include "libft.h"

void    delete(void *content)
{
    t_list  *node;

    if(content)
    {
        node = (t_list *)content;
        free(node);
    }
}
