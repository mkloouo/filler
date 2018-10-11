/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 01:14:13 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/11 02:35:30 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#include <ft/char.h>

void		filler_algo(t_filler *filler)
{
	for (int i = 0; i < filler->map.size.y; ++i)
	{
		for (int j = 0; j < filler->map.size.x; ++j)
		{
			if (ft_tolower(filler->map.data[i][j]) == (char) filler->me)
			{
				filler->step.x = j;
				filler->step.y = i;
			}
		}
	}
}
