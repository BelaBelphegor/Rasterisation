/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <tiboitel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 18:50:28 by tiboitel          #+#    #+#             */
/*   Updated: 2015/05/08 18:59:53 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtolower(char *src)
{
	int		i;

	i = -1;
	while (src[++i])
		src[i] = ft_tolower(src[i]);
	return (src);
}
