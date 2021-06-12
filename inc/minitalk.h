/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:55:16 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/12 22:51:49 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
// # include <sys/types.h>
# include <unistd.h>
# include <signal.h>
// # include <asm-generic/siginfo.h>
// # include <asm-generic/signal.h>

int		ft_putchar(int c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
int		ft_atoi(const char *nptr);

#endif