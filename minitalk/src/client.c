/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:40:55 by yazan             #+#    #+#             */
/*   Updated: 2023/07/24 16:37:01 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	arg_config(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc != 3)
	{
		ft_printf("Invalid number of parameters\n");
		exit(EXIT_FAILURE);
	}
	while (argv[1][++i])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
		{
			ft_printf("Incorrect PID!: %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}
	if (*argv[2] == 0)
	{
		ft_printf("Empty message\n");
		exit(EXIT_FAILURE);
	}
}

void	send_func(int ser_id, char *msg)
{
	unsigned char	c;
	int				bitnmr;

	while (*msg)
	{
		c = *msg;
		bitnmr = 8;
		while (bitnmr--)
		{
			if (c & 0b10000000)
			{
				kill(ser_id, SIGUSR1);
			}
			else
			{
				kill(ser_id, SIGUSR2);
			}
			usleep(500);
			c <<= 1;
		}
		msg++;
	}
}

void	sig_func(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("->msg :one byte recived\n");
	}
}

void	sig_config(void)
{
	struct sigaction	sig;

	sig.sa_handler = &sig_func;
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, 0) == -1)
		ft_printf("client failed to change sig behavior");
}

int	main(int argc, char **argv)
{
	ft_printf("client PİD:%d\n", getpid());
	ft_printf("-------------------------------------\n\n");
	arg_config(argc, argv);
	sig_config();
	send_func(ft_atoi(argv[1]), argv[2]);
	return (EXIT_SUCCESS);
}
