/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_message.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:26:45 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/18 15:34:47 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_error_and_exit(char *error_message)
{
	ft_putstr(ANSI_F_BRED);
	ft_putstr("ERROR: ");
	ft_putstr(ANSI_RESET);
	ft_putstr(error_message);
	ft_putstr("\n");
	exit(EXIT_FAILURE);
}

void	print_message(char *header, char *message)
{
	ft_putstr(header);
	ft_putstr(ANSI_F_BGREEN);
	ft_putstr(message);
	ft_putstr(ANSI_RESET);
	ft_putstr("\n");
}
