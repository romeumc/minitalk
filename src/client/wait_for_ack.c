/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_ack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 08:19:15 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/17 11:28:02 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	wait_for_ack(int acknowledge)
{
	if (acknowledge == 0)
	{
		//ft_putstr("Wainting for ack!");
		pause();
	}
}
