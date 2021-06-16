/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:16:50 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/16 18:06:10 by rmartins         ###   ########.fr       */
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
	char	*buffer;
	int		idx_buf;
	int		index;
	}	t_server;

#endif