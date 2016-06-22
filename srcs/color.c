/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 20:28:57 by tiboitel          #+#    #+#             */
/*   Updated: 2016/06/21 21:49:19 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterisation.h"

/*
 * private:
 */

/*
 * public:
 */

t_color		*color_create(int rgb, char verbose)
{
	t_color		*color;

	color = NULL;
	if (!(color = (t_color *)ft_memalloc(sizeof(t_color))))
		return (NULL);
	color_init(color, rgb, verbose);
	return (color);
}

int			color_init(t_color *this, int rgb, char verbose)
{
	if (!this)
		return (-1);
	this->red = (rgb >> 16) & 0xFF;
	this->green = (rgb >> 8) & 0xFF;
	this->blue = rgb & 0XFF;
	this->verbose = verbose;
	this->add = &color_add;
	this->sub = &color_sub;
	this->mult = &color_mult;
	this->tostring = &color_tostring;
	this->destroy = &color_destroy;
	if (verbose == TRUE)
		printf("Color( red: %3d, green: %3d, blue: %3d ) constructed.\n", this->red, this->green, this->blue);
	return (1);
}

t_color		*color_add(t_color *this, t_color *add)
{
	t_color		*color;
	int			rgb;

	rgb = 0xFF000000 |
		((((this->red + add->red) % 255) << 16) & 0x00FF0000) |
		((((this->green + add->green) % 255) << 8) & 0x0000FF00) |
		(((this->blue + add->blue) % 255) & 0x0000000FF);
	color = color_create(rgb, FALSE);
	return (color);
}

t_color		*color_sub(t_color *this, t_color *add)
{
	t_color		*color;
	int			rgb;

	rgb = 0xFF000000 |
		((((this->red - add->red) % 255) << 16) & 0x00FF0000) |
		((((this->green - add->green) % 255) << 8) & 0x0000FF00) |
		(((this->blue - add->blue) % 255) & 0x0000000FF);	
	color = color_create(rgb, FALSE);
	return (color);
}

t_color		*color_mult(t_color *this, t_color *add)
{
	t_color		*color;
	int			rgb;

	rgb = 0xFF000000 |
		((((this->red * add->red) % 255) << 16) & 0x00FF0000) |
		((((this->green * add->green) % 255) << 8) & 0x0000FF00) |
		(((this->blue * add->blue) % 255) & 0x0000000FF);	
	color = color_create(rgb, FALSE);
	return (color);
}

void		color_tostring(t_color *color)
{
	printf("Color( red: %3d, green: %3d, blue: %3d )\n", color->red, color->green, color->blue);
}

void		color_destroy(t_color *color)
{
	if (color->verbose == TRUE)
		printf("Color( red: %3d, green: %3d, blue: %3d ) destructed.\n", color->red, color->green, color->blue);
	free(color);
	color = NULL;
}
