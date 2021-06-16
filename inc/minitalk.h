/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:55:16 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/16 10:43:58 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "ft_ansi.h"

# define _GNU_SOURCE

# define EOT (4)

void	wait_for_ack(int acknowledge);

int		ft_putchar(int c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
int		ft_atoi(const char *nptr);

#endif