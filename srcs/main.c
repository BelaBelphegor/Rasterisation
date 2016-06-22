/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 20:25:33 by tiboitel          #+#    #+#             */
/*   Updated: 2016/06/22 05:37:37 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterisation.h"

int		main(void)
{
	{
		printf("\n----- Color ------\n");
		t_color		*color;
		t_color		*subcolor;
		t_color		*subbed;

		color = color_create(0x0066CC, TRUE);
		subcolor = color_create(0x003366, TRUE);

		subbed = color->sub(color, subcolor);
		subbed->tostring(subbed);
		subbed->destroy(subbed);
		
		subbed = color->add(color, subcolor);
		subbed->tostring(subbed);
		subbed->destroy(subbed);
		
		subbed = color->mult(color, subcolor);
		subbed->tostring(subbed);
		subbed->destroy(subbed);

		subcolor->destroy(subcolor);
		color->destroy(color);
	}
	{
		printf("\n----- Vertex------\n");
		t_vertex	*vertex;

		vertex = vertex_create(0.0, 0.0, 0.0, 1.0, NULL, TRUE);
		vertex->destroy(vertex);
		
		t_vertex	*unitX;
		t_vertex	*unitY;
		t_vertex	*unitZ;
		unitX = vertex_create(1.0, 0.0, 0.0, 1.0, NULL, TRUE);
		unitY = vertex_create(0.0, 1.0, 0.0, 1.0, NULL, TRUE);
		unitZ = vertex_create(0.0, 0.0, 1.0, 1.0, NULL, TRUE);
		unitX->tostring(unitX);
		unitY->tostring(unitY);
		unitZ->tostring(unitZ);
		unitX->destroy(unitX);
		unitY->destroy(unitY);
		unitZ->destroy(unitZ);
	}
	{
		printf("\n----- Vector ------\n");
		t_vertex	*vtx0;
		t_vertex	*vtxX;
		t_vertex	*vtxY;
		t_vertex	*vtxZ;
		t_vector	*vtcXunit;
		t_vector	*vtcYunit;
		t_vector	*vtcZunit;
		
		vtx0 = vertex_create(0.0, 0.0, 0.0, 1.0, NULL, FALSE);
		vtxX = vertex_create(1.0, 0.0, 0.0, 1.0, NULL, FALSE);
		vtxY = vertex_create(0.0, 1.0, 0.0, 1.0, NULL, FALSE);
		vtxZ = vertex_create(0.0, 0.0, 1.0, 1.0, NULL, FALSE);
		vtcXunit = vector_create(vtx0, vtxX, TRUE);
		vtcYunit = vector_create(vtx0, vtxY, TRUE);
		vtcZunit = vector_create(vtx0, vtxZ, TRUE);
		vtcXunit->tostring(vtcXunit);
		vtcYunit->tostring(vtcYunit);
		vtcZunit->tostring(vtcZunit);

		t_vertex	*dest1;
		dest1 = vertex_create(-12.34, 23.45, -34.56, 1.0, NULL, TRUE);
		t_vector	*vtc1;
		vtc1 = vector_create(NULL, dest1, TRUE);
		dest1->verbose = FALSE;

		t_vertex	*orig2;
		t_vertex	*dest2;
		t_vector	*vtc2;
		orig2 = vertex_create(23.87, -37.95, 78.34, 1.0, NULL, FALSE);
		dest2 = vertex_create(-12.34, 23.45, -34.56, 1.0, NULL, FALSE);
		vtc2 = vector_create(orig2, dest2, TRUE);
		printf("Magnitude is %f.\n", vtc2->magnitude(vtc2)); 
		t_vector	*nvtc2;

		nvtc2 = vtc2->normalize(vtc2);	
		printf("Normalized $vtc2 is");
		nvtc2->tostring(nvtc2);
		printf("Normalized $vtc2 magnitude is %f.\n", nvtc2->magnitude(nvtc2));
		
		t_vector	*tmp;
		printf("$vtc1 + $vtc2 is ");
		tmp = vtc1->add(vtc1, vtc2);
		tmp->verbose = TRUE;
		tmp->tostring(tmp);
		tmp->destroy(tmp);
		
		tmp = vtc1->sub(vtc1, vtc2);
		tmp->verbose = TRUE;
		printf("$vtc1 - $vtc2 is ");
		tmp->tostring(tmp);
		tmp->destroy(tmp);

		tmp = vtc1->opposite(vtc1);
		tmp->verbose = TRUE;
		printf("$vtc1 opposite is ");
		tmp->tostring(tmp);
		tmp->destroy(tmp);

		tmp = vtc1->scalarproduct(vtc1, 42);
		tmp->verbose = TRUE;
		printf("scalar product of $vtc1 is ");
		tmp->tostring(tmp);
		tmp->destroy(tmp);

		printf("dot product of $vtc1 and $vtc2 is %f.\n", vtc1->dotproduct(vtc1, vtc2));

		tmp = vtc1->crossproduct(vtc1, vtc2);
		tmp->verbose = TRUE;
		printf("cross product of $vtc1 is ");
		tmp->tostring(tmp);
		tmp->destroy(tmp);
		
		tmp = vtcXunit->crossproduct(vtcXunit, vtcYunit);
		tmp->verbose = TRUE;
		printf("cross product of $vtc1 is ");
		tmp->tostring(tmp);
		tmp->destroy(tmp);
		printf("cos  of $vtc1 and $vtc2 is %f.\n", vtc1->cos(vtc1, vtc2));
		vtc1->destroy(vtc1);
		vtc2->destroy(vtc2);
	}
	return (0);
}
