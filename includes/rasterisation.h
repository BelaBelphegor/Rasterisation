/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterisation.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 20:24:50 by tiboitel          #+#    #+#             */
/*   Updated: 2016/06/22 05:37:39 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RASTERISATION_H
#define FT_RASTERISATION_H

#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# define TRUE 1
# define FALSE 0
# define MATRIX_IDENTITY "MATRIX_IDENTITY"
# 
typedef struct			s_color
{
	unsigned char		red;
	unsigned char		green;
	unsigned char		blue;
	char				verbose;
	struct s_color		*(*add)(struct s_color *this, struct s_color *add);
	struct s_color		*(*sub)(struct s_color *this, struct s_color *sub);
	struct s_color		*(*mult)(struct s_color *this, struct s_color *mult);
	void				(*tostring)(struct s_color *this);
	void				(*destroy)(struct s_color *this);
}						t_color;

typedef	struct			s_vertex
{
	float				x;
	float				y;
	float				z;
	float				w;
	t_color				*color;
	char				verbose;
	void				(*tostring)(struct s_vertex *this);
	void				(*destroy)(struct s_vertex *this);
}						t_vertex;

typedef struct			s_vector
{
	float				x;
	float				y;
	float				z;
	float				w;
	char				verbose;
	float				(*magnitude)(struct s_vector *this);
	struct s_vector		*(*normalize)(struct s_vector *this);
	struct s_vector		*(*add)(struct s_vector *this, struct s_vector *rhs);
	struct s_vector		*(*sub)(struct s_vector *this, struct s_vector *rhs);
	struct s_vector		*(*opposite)(struct s_vector *this);
	struct s_vector		*(*scalarproduct)(struct s_vector *this, float k);
	float				(*dotproduct)(struct s_vector *this, struct s_vector *rhs);
	float				(*cos)(struct s_vector *this, struct s_vector *rhs);
	struct s_vector		*(*crossproduct)(struct s_vector *this, struct s_vector *rhs);
	void				(*tostring)(struct s_vector *this);
	void				(*destroy)(struct s_vector *this);

}						t_vector;

typedef struct			s_matrix
{
	int					value[4][4];

}						t_matrix;
t_color					*color_create(int rgb, char verbose);
int						color_init(t_color *this, int rgb, char verbose);
t_color					*color_add(t_color *this, t_color *add);
t_color					*color_sub(t_color *this, t_color *add);
t_color					*color_mult(t_color *this, t_color *add);
void					color_tostring(t_color *color);
void					color_destroy(t_color *color);

t_vertex				*vertex_create(float x, float y, float z, float w,
	t_color *color, char verbose);
int						vertex_init(t_vertex *this, float x, float y, float z, float w, t_color *color, char verbose);
void					vertex_tostring(t_vertex *this);
void					vertex_destroy(t_vertex *this);

t_vector				*vector_create(t_vertex *orig, t_vertex *dest, char verbose);
int						vector_init(t_vector *this, t_vertex *dest, t_vertex *orig, char verbose);
t_vector				*vector_add(t_vector *this, t_vector *rhs);
t_vector				*vector_sub(t_vector *this, t_vector *rhs);
t_vector				*vector_crossproduct(t_vector *this, t_vector *rhs);
t_vector				*vector_scalarproduct(t_vector *this, float k);
t_vector				*vector_normalize(t_vector *this);
t_vector				*vector_opposite(t_vector *this);
float					vector_dotproduct(t_vector *this, t_vector *rhs);
float					vector_magnitude(t_vector *this);
float					vector_cos(t_vector *this, t_vector *rhs);
void					vector_tostring(t_vector *this);
void					vector_destroy(t_vector *this);
#endif
