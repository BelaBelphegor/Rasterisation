/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 05:19:41 by tiboitel          #+#    #+#             */
/*   Updated: 2016/06/22 05:37:05 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterisation.h"

t_matrix	*matrix_create(char *preset)
{
	t_matrix	*matrix;

	if (!((matrix = (t_matrix *)ft_memalloc(sizeof(t_matric)))))
		return (NULL);
	matrix_init(matrix, preset);
	return (matrix);
}

int			matrix_init(t_matrix *this, char *preset)
{
	if (!this)
		return (-1);
	if (!ft_strcmp(preset, MATRIX_IDENTITY))
	{
		ft_bzero(matrix->value, sizeof(int) * 4 * 4);
		matrix->value[0][0] = 1;
		matrix->value[1][1] = 1;
		matrix->value[2][2] = 1;
		matrix->value[3][3] = 1;
	}
	else if (!ft_strcmp(preset, MATRIX))
	{
	}
	return (1);
}

void		matrix_destroy(t_matrix *this)
{
	free(this);
	this = NULL;
}
