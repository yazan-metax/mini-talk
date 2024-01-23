/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:40:59 by yazan             #+#    #+#             */
/*   Updated: 2023/07/24 17:31:43 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler_func(int signum, siginfo_t *info, void *context)
{
	static int				bit_itr = -1;
	static unsigned char	c;

	(void)context;
	if (bit_itr < 0)
		bit_itr = 7;
	if (signum == SIGUSR1)
		c |= (1 << bit_itr);
	bit_itr--;
	if (bit_itr < 0)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			ft_printf("Server failed to send SIGUSR1");
	}
}

void	sig_config(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = &handler_func;
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, 0) == -1)
	{
		ft_printf("failed to change SİGUSR1 BEHAVİOR");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sig, 0) == -1)
	{
		ft_printf("failed to change sigusr2 behavior");
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	ft_printf("server PİD:%d\n", getpid());
	ft_printf("---------------------------------\n\n");
	while (1)
		sig_config();
	return (EXIT_SUCCESS);
}
