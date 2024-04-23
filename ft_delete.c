#include "libft.h"

void    ft_delete(void *node)
{
    free((t_list *)node);
}