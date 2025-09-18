/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:07:44 by mmaquine          #+#    #+#             */
/*   Updated: 2025/09/05 16:18:18 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static void	send_data(pid_t pid, char *s)
{
	int	shift_bits;

	shift_bits = 7;
	while (*s)
	{
		while (shift_bits >= 0)
		{
			if ((*s >> shift_bits) & 0x1)
				kill(pid, SIGUSER2);
			else
				kill(pid, SIGUSER1);
			shift_bits--;
			usleep(100);
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
		kill(pid, SIGUSER1);
		shift_bits--;
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	pid = 0;
	if (argc > 2)
	{
		pid = ft_atoi(argv[1]);
		send_data(pid, argv[2]);
		send_zero(pid);
	}
	return (EXIT_SUCCESS);
}
