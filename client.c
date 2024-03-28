/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:57:49 by bautrodr          #+#    #+#             */
/*   Updated: 2024/02/27 22:10:41 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig_bits(char ch_msg, pid_t server_pid)
{
	int	bits;

	bits = 7;
	while (bits >= 0)
	{
		if ((ch_msg >> bits & 1) == 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		--bits;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc == 3)
	{
		if (ft_atoi(argv[1]) <= 0)
		{
			ft_putendl_fd("Invalid PID!!\n", 2);
			return (1);
		}
		while (argv[2][++i])
			send_sig_bits(argv[2][i], ft_atoi(argv[1]));
	}
	else
	{
		ft_putendl_fd("Incorrect arguments!!\n", 2);
		ft_putendl_fd("Correct use: ./client <PID> <msg>\n", 1);
	}
	return (0);
}
