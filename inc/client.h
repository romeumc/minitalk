/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:12:20 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/18 15:29:27 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "minitalk.h"

extern int	g_acknowledge;

void	wait_for_ack(int server_pid, int signal);
void	validate_args(int argc, char **argv);
int		validate_server(char *pid);

#endif