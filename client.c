/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:07:44 by mmaquine          #+#    #+#             */
/*   Updated: 2025/09/24 16:12:00 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_ready;

static void	ready_to_send(int pid)
{
	(void)pid;
	g_ready = 1;
}

static void	send_data(pid_t pid, char *s)
{
	int	shift_bits;

	shift_bits = 7;
	while (*s)
	{
		while (shift_bits >= 0)
		{
			g_ready = 0;
			if ((*s >> shift_bits) & 0x1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			while (!g_ready)
				usleep(1);
			shift_bits--;
		}
		shift_bits = 7;
		s++;
	}
}

static void	send_zero(pid_t pid)
{
	int	shift_bits;

	shift_bits = 7;
	while (shift_bits >= 0)
	{
		if (g_ready)
		{
			kill(pid, SIGUSR1);
			shift_bits--;
			g_ready = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	pid = 0;
	g_ready = 1;
	if (argc > 2)
	{
		if (new_action(ready_to_send, SIGUSR2))
		{
			ft_printf("Failed to install signal handler");
			return (EXIT_FAILURE);
		}
		ft_printf("Size of string: %d", ft_strlen(argv[2]));
		pid = ft_atoi(argv[1]);
		send_data(pid, argv[2]);
		send_zero(pid);
	}
	return (EXIT_SUCCESS);
}
