/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_ack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 08:19:15 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/18 15:37:45 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	wait_for_ack(int server_pid, int signal)
{
	int	max_wait;
	int	time;

	time = 0;
	max_wait = 10;
	while (g_acknowledge == 0)
	{
		if (max_wait > 1000)
			print_error_and_exit("Timeout !");
		else if (time > max_wait)
		{
			max_wait += 10;
			if (kill(server_pid, signal) == -1)
				print_error_and_exit("Server is not respondig");
		}
		else
			usleep(100);
		time++;
	}
	return ;
}
