/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 21:36:07 by tiboitel          #+#    #+#             */
/*   Updated: 2016/06/22 01:26:38 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterisation.h"

t_vertex	*vertex_create(float x, float y, float z, float w,
		t_color *color, char verbose)
{
	t_vertex	*vertex;

	vertex = NULL;
	if (!(vertex = (t_vertex *)ft_memalloc(sizeof(t_vertex))))
		return (NULL);
	vertex_init(vertex, x, y, z, w, color, verbose);
	return (vertex);
}

int			vertex_init(t_vertex *this, float x, float y, float z, float w, t_color *color,
		char verbose)
{
	if (!this)
		return (-1);
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
	this->color = (color) ? color : color_create(0xFFFFFFFF, FALSE);
	this->verbose = verbose;
	this->tostring = &vertex_tostring;
	this->destroy = &vertex_destroy;
	if (verbose == TRUE)
		printf("Vertex ( x: %0.2f, y: %0.2f, z: %0.2f, w: %0.2f) constructed.\n",
			this->x, this->y, this->z, this->w);
	return (1);
}

void		vertex_tostring(t_vertex *this)
{
	printf("Vertex ( x: %0.2f, y: %0.2f, z: %0.2f, w: %0.2f) constructed.\n",
			this->x, this->y, this->z, this->w);
	if (this->verbose == TRUE)
		this->color->tostring(this->color);
}

void		vertex_destroy(t_vertex *this)
{
	if (this->verbose == TRUE)
		printf("Vertex ( x: %0.2f, y: %0.2f, z: %0.2f, w: %0.2f) destructed.\n",
			this->x, this->y, this->z, this->w);
	if (this->color != NULL)
		free(this->color);
	free(this);
	this = NULL;
}
