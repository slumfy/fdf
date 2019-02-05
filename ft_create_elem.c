/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:30:31 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/05 02:48:07 by rvalenti         ###   ########.fr       */
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
