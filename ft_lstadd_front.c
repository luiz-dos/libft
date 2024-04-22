/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:31:58 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/04/19 16:32:04 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Adds the node ’new’ at the beginning of the list.
lst: The address of a pointer to the first link of a list.
new: The address of a pointer to the node to be added to the list. */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
int	main(void)
{
	t_list	*list;

	list = ft_lstnew("Luiz");
	ft_lstadd_front(&list, ft_lstnew("Henrique"));
	ft_lstadd_front(&list, ft_lstnew("Maciel"));
	ft_lstadd_back(&list, ft_lstnew("Joao"));
	ft_lstiter(list, print_content);
	return (0);
}
