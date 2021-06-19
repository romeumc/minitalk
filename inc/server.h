/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:16:50 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/19 18:47:33 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

#include "minitalk.h"

extern int	g_signal;

typedef struct	s_server
	{
	int		client_pid;
	char	bin[7];
	int		index;
	int		i;
	}	t_server;

void	display_server_pid(void);
void	set_client_pid(t_server *data);
void	init_data(t_server *data, struct sigaction *act);

#endif