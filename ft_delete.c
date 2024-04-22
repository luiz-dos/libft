#include "libft.h"

void    ft_delete(void *content)
{
    t_list  *node;

    if(content)
    {
        node = (t_list *)content;
        free(node);
    }
}
