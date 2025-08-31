#include "libft.h"

void ft_lstremove_if(list_t **lst, cmp_t cmp, void *data, void (*del)(void *)) {
	list_t *current;
	list_t *prev;

	current = *lst;
	prev = NULL;
	while (current) {
		if (cmp(current->content, data)) {
			list_t *temp = current;
			if (prev)
				prev->next = current->next;
			else
				*lst = current->next;
			current = current->next;
			del(temp->content);
			free(temp);
		} else {
			prev = current;
			current = current->next;
		}
	}
}