/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 13:10:58 by rbusseti          #+#    #+#             */
/*   Updated: 2014/12/09 13:47:51 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H

# define LIST_H

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_hist
{
	struct s_list	*first;
	unsigned int	time;
}					t_hist;

typedef struct		s_chara
{
	char			chara;
}					t_chara;

t_list				*ft_create_elem(void *content);
void				ft_list_push(t_list **list, void *content);

#endif
