/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 00:11:10 by tiboitel          #+#    #+#             */
/*   Updated: 2016/06/22 04:55:46 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterisation.h"

/*
 * dest		Vertex de destination du vecteur.
 * orig		(optionnel) Vertex d'origine du vecteur. X: 0, Y: 0, Z: 0, W: 1.0.
 * @return	Retourne un nouveau vecteur.
 */
t_vector	*vector_create(t_vertex *dest, t_vertex *orig, char verbose)
{
	t_vector	*vector;

	if (!(vector = (t_vector *)ft_memalloc(sizeof(t_vector))))
		return (NULL);
	vector_init(vector, dest, orig, verbose);
	return (vector);
}

int			vector_init(t_vector *this, t_vertex *orig, t_vertex *dest, char verbose)
{
	if (!this || !dest)
		return (-1);
	if (orig == NULL)
		orig = vertex_create(0.0, 0.0, 0.0, 1.0, NULL, FALSE);
	this->x = dest->x - orig->x;
	this->y = dest->y - orig->y;
	this->z = dest->z - orig->z;
	this->w = 0.0;
	this->verbose = verbose;
	this->magnitude = &vector_magnitude;
	this->normalize = &vector_normalize;
	this->add = &vector_add;
	this->sub = &vector_sub;
	this->opposite = &vector_opposite;
	this->scalarproduct = &vector_scalarproduct;
	this->dotproduct = &vector_dotproduct;
	this->tostring = &vector_tostring;
	this->destroy = &vector_destroy;
	this->crossproduct = &vector_crossproduct;
	this->cos= &vector_cos;
	if (this->verbose)
		printf("Vector ( x:%0.2f, y:%0.2f, z:%0.2f, w:%0.2f ) constructed.\n", this->x, this->y, this->z, this->w);
	return (1);
}

/*
 * @return	Retoune la longueur ou "norme" du vecteur.
 */
float		vector_magnitude(t_vector *this)
{
	return (sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2)));
}

/*
 * @return Retourne le vecteur normalise, s'il est deja retourne une copie du vecteur.
 */
t_vector	*vector_normalize(t_vector *this)
{
	t_vector	*vector;
	t_vertex	*dest;
	float		x;
	float		y;
	float		z;

	x = this->x / this->magnitude(this);
	y = this->y / this->magnitude(this);
	z = this->z / this->magnitude(this);
	dest = vertex_create(x, y, z, 1.0, NULL, FALSE);
	vector = vector_create(NULL, dest, FALSE);
	return (vector);
}

/*
 * @return Retourne un nouveau vecteur produit de deux vecteurs.
 */
t_vector	*vector_add(t_vector *this, t_vector *rhs)
{
	t_vector	*vector;
	t_vertex	*dest;
	float		x;
	float		y;
	float		z;

	x = this->x + rhs->x;
	y = this->y + rhs->y;
	z = this->z + rhs->z;
	dest = vertex_create(x, y, z, 1.0, NULL, FALSE);
	vector = vector_create(NULL, dest, FALSE);
	return (vector);
}

/*
 * @return Retourne un nouveau vecteur soustrait de deux vecteurs.
 */
t_vector	*vector_sub(t_vector *this, t_vector *rhs)
{
	t_vector	*vector;
	t_vertex	*dest;
	float		x;
	float		y;
	float		z;

	x = this->x - rhs->x;
	y = this->y - rhs->y;
	z = this->z - rhs->z;
	dest = vertex_create(x, y, z, 1.0, NULL, FALSE);
	vector = vector_create(NULL, dest, FALSE);
	return (vector);
}

/*
 * @return	Retourne un nouveau vecteur oppose du vecteur actuel.
 */
t_vector	*vector_opposite(t_vector *this)
{
	t_vector	*vector;
	t_vertex	*dest;
	float		x;
	float		y;
	float		z;

	x = this->x * -1;
	y = this->y * -1;
	z = this->z * -1;
	dest = vertex_create(x, y, z, 1.0, NULL, FALSE);
	vector = vector_create(NULL, dest, FALSE);
	free(dest);
	return (vector);

}

/*
 * @return 	Retourne un nouveau vecteur resultant du produit d'un vecteur par un scalaire.
 */
t_vector	*vector_scalarproduct(t_vector *this, float k)
{
	t_vector	*vector;
	t_vertex	*dest;
	float		x;
	float		y;
	float		z;

	x = this->x * k;
	y = this->y * k;
	z = this->z * k;
	dest = vertex_create(x, y, z, 1.0, NULL, FALSE);
	vector = vector_create(NULL, dest, FALSE);
	free(dest);
	return (vector);
}

/*
 * @return Retourne le produit scalaire de deux vecteurs.
 */ 
float		vector_dotproduct(t_vector *this, t_vector *rhs)
{
	float		x;
	float		y;
	float		z;

	x = this->x * rhs->x;
	y = this->y * rhs->y;
	z = this->z * rhs->z;
	return (x + y + z);
}

/*
* @return Retourne le cosinus de l'angle entre deux vecteurs.
*/
float		vector_cos(t_vector *this, t_vector *rhs)
{
	return (this->dotproduct(this, rhs) / (this->magnitude(rhs) * this->magnitude(this)));
}

/*
 * @return Retourne le produit en croix de deux vecteurs (repere main droite)
 */
t_vector	*vector_crossproduct(t_vector *this, t_vector *rhs)
{
	t_vector	*vector;
	t_vertex	*dest;
	float		x;
	float		y;
	float		z;

	x = this->y * rhs->z - rhs->y * this->z;
	y = this->z * rhs->x - rhs->z * this->x;
	z = this->x * rhs->y - rhs->x * this->y;
	dest = vertex_create(x, y, z, 1.0, NULL, FALSE);
	vector = vector_create(NULL, dest, FALSE);
	free(dest);
	return (vector);
}

void		vector_tostring(t_vector *this)
{
	printf("Vector ( x:%0.2f, y:%0.2f, z:%0.2f, w:%0.2f )\n", this->x, this->y, this->z, this->w);
}

void		vector_destroy(t_vector *this)
{
	if (this->verbose)
		printf("Vector ( x:%0.2f, y:%0.2f, z:%0.2f, w:%0.2f ) destructed.\n", this->x, this->y, this->z, this->w);
	free(this);
	this = NULL;
}
