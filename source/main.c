/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 01:35:09 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/23 19:16:25 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int				main(void)
{
	t_filler	filler;

	filler_init(&filler);
	filler_run(&filler);
	filler_end(&filler);
	return (0);
}
