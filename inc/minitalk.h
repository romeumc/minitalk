/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:55:16 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/19 18:51:19 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "ft_ansi.h"

# define _GNU_SOURCE

# define EOT (4)

void	print_error_and_exit(char *error_message);
void	print_message(char *header, char *message);

int		ft_putchar(int c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
int		ft_atoi(const char *nptr);
void	*ft_memset(void *s, int c, size_t n);

#endif