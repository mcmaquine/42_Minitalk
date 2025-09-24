/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:04:26 by mmaquine          #+#    #+#             */
/*   Updated: 2025/09/24 14:23:22 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

static void	insert_bit_1(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	g_data.c = g_data.c << 1;
	g_data.c++;
	g_data.pos++;
	if (g_data.pos == 8)
	{
		g_data.str = join(g_data.str, g_data.c);
		g_data.pos = 0;
		g_data.c = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

static void	insert_bit_0(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	g_data.c = g_data.c << 1;
	g_data.pos++;
	if (g_data.pos == 8)
	{
		g_data.str = join(g_data.str, g_data.c);
		if (g_data.c == 0)
		{
			ft_printf("%s", g_data.str);
			free(g_data.str);
			g_data.str = NULL;
		}
		g_data.c = 0;
		g_data.pos = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	g_data.c = 0;
	g_data.pos = 0;
	if (new_action_w_info(insert_bit_0, SIGUSR1)
		|| new_action_w_info(insert_bit_1, SIGUSR2))
	{
		ft_printf("Failed to install signal handler(s)");
		return (1);
	}
	g_data.str = NULL;
	ft_printf("%d\n", getpid());
	while (1)
	{
	}
	return (EXIT_SUCCESS);
}
