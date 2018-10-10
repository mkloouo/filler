/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 02:18:30 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/10 18:25:28 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <filler.h>

void filler_init(t_filler *filler)
{
	filler->piece.data = 0;
	filler->map.data = 0;
}

void filler_run(t_filler *filler)
{
	filler_parse(filler);
}

void filler_parse(t_filler *filler)
{

}

void filler_end(t_filler *filler)
{
	free(filler->piece.data);
	free(filler->map.data);
}

