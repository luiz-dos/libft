#include "libft.h"
#include <stdio.h>

static void	ft_delete(void *node)
{
    free((t_list *)node);
}

static void	ft_print_content(void  *content)
{
	printf("%s\n", (char *)content);
}

static void	*ft_toupper_v2(void *content)
{
	char	*str;
	char	*result;
	int		i;

	str = (char *)content;
	result = ft_strdup(str);
	i = 0;
	while(result[i])
	{
		result[i] = ft_toupper(result[i]);
		i++;
	}
	return (result);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	t_list	*node5;
	t_list	*current;
	t_list	*save;
	t_list	*last;
	t_list	*new_list;
	int		list_size;

	node1 = ft_lstnew(ft_strdup("Luiz"));
	node2 = ft_lstnew(ft_strdup("Henrique"));
	node3 = ft_lstnew(ft_strdup("Maciel"));
	node4 = ft_lstnew(ft_strdup("Joao"));
	node5 = ft_lstnew(ft_strdup("Maria"));

	node1->next = node2;
	
	printf("\n--List--\n");
	ft_lstiter(node1, ft_print_content);
	last = ft_lstlast(node1);
	printf("\nLast node: %s\n", (char *)last->content);
	printf("List size: %d\n", list_size = ft_lstsize(node1));

	printf("\n--List after adding node3--\n");
	ft_lstadd_front(&node1, node3);
	ft_lstiter(node3, ft_print_content);
	last = ft_lstlast(node3);
	printf("\nLast node: %s\n", (char *)last->content);
	printf("List size: %d\n", list_size = ft_lstsize(node3));

	printf("\n--List after adding node4--\n");
	ft_lstadd_back(&node3, node4);
	ft_lstiter(node3, ft_print_content);
	last = ft_lstlast(node3);
	printf("\nLast node: %s\n", (char *)last->content);
	printf("List size: %d\n", list_size = ft_lstsize(node3));

	printf("\n--List after adding node5--\n");
	ft_lstadd_back(&node3, node5);
	ft_lstiter(node3, ft_print_content);
	last = ft_lstlast(node3);
	printf("\nLast node: %s\n", (char *)last->content);
	printf("List size: %d\n", list_size = ft_lstsize(node3));

	current = node3;
	save = NULL;
	while (current && current != node4)
	{
		save = current;
		current = current->next;
	}
	save->next = current->next;
	
	printf("\n--List after deleting node4--\n");
	ft_lstdelone(node4, ft_delete);
	ft_lstiter(node3, ft_print_content);
	last = ft_lstlast(node3);
	printf("\nLast node: %s\n", (char *)last->content);
	printf("List size: %d\n", list_size = ft_lstsize(node3));

	printf("\n--New list created by ft_lstmap--\n");
	new_list = ft_lstmap(node3, ft_toupper_v2, ft_delete);
	ft_lstiter(new_list, ft_print_content);
	last = ft_lstlast(new_list);
	printf("\nLast node: %s\n", (char *)last->content);
	printf("List size: %d\n", list_size = ft_lstsize(new_list));

	printf("\n--Deleted list--\n");
	ft_lstclear(&node3, ft_delete);
	if(!node3)
		printf("Empty list\n");
	printf("\nList size: %d\n", list_size = ft_lstsize(node3));

	printf("\n--New deleted list--\n");
	ft_lstclear(&new_list, ft_delete);
	if(!new_list)
		printf("Empty list\n");
	printf("\nList size: %d\n", list_size = ft_lstsize(new_list));
	return (0);
}