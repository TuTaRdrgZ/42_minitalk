/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:57:41 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/14 10:26:53 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int sig)
{
	static int				bit = 0;
	static unsigned char	ch = '\0';

	if (sig == SIGUSR1)
		ch |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (ch != '\0')
			ft_putchar_fd(ch, 1);
		bit = 0;
		ch = '\0';
	}
}

static void	ft_printserver_pid(char *str, int server_pid)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	ft_putnbr_fd(server_pid, 1);
	write(1, "\n", 1);
}

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	sa;

	server_pid = getpid();
	if (!server_pid)
		ft_putendl_fd("No Server PID", 2);
	else
		ft_printserver_pid("Server PID--> ", server_pid);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	while (1)
		pause();
	return (0);
}
