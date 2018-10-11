/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 01:35:09 by modnosum          #+#    #+#             */
/*   Updated: 2018/10/11 19:43:52 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

#ifdef DEBUG
int _log_fd;
#endif

int				main(void)
{
#ifdef DEBUG
	_log_fd = ft_open_file("modnosum.filler.log", FILE_RW);
#endif
	t_filler	filler;

	filler_init(&filler);
	filler_run(&filler);
	filler_end(&filler);
#ifdef DEBUG
	ft_close_file(_log_fd);
#endif
	return (0);
}
