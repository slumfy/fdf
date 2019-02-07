/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:24:13 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/08 00:24:42 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_lst	*ft_create_elem(char *data, size_t len)
{
	t_lst	*new;

	if (!(new = (t_lst*)ft_memalloc(sizeof(t_lst))))
		exit(0);
	new->data = data;
	new->len = len;
	new->next = NULL;
	return (new);
}

void	ft_list_pushback(t_lst **begin_list, char *line)
{
	t_lst	*tmp;

	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(line, ft_strlen(line));
	}
	else
		*begin_list = ft_create_elem(line, ft_strlen(line));
}
