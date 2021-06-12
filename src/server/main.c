/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:41:16 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/12 22:48:20 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *ucontext)
{
	ft_putstr("teste:");
	ft_putnbr(signum);
	ft_putstr("\n");
	(void)info;
	(void)ucontext;
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	struct sigaction sa;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;

	ft_putstr("pid:");
	ft_putnbr(getpid());

	sigaction(SIGUSR1, &sa, NULL);
	while (1)
	{

	}
}