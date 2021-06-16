/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:12:20 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/16 10:14:31 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "minitalk.h"

int	g_acknowledge_client;

void	validate_args(int argc, char **argv);
int		validate_server(char *pid);

#endif