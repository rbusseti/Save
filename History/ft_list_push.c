/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 13:35:34 by rbusseti          #+#    #+#             */
/*   Updated: 2014/12/09 13:45:30 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push(t_list **list, void *content)
{
	t_list	*temp;
	t_list	*new;

	new = ft_create_elem(content);
	temp = *list;
	if (temp->next)
		temp->next->prev = new;
	new->next = temp->next;
	new->prev = temp;
	temp->next = new;
	*list = new;
}
