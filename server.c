/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:04:26 by mmaquine          #+#    #+#             */
/*   Updated: 2025/09/05 17:30:40 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	cprint(void);

void	insert_bit_1(int sig)
{
	(void)sig;
	g_data.c = g_data.c << 1;
	g_data.c++;
	g_data.pos++;
}

void	insert_bit_0(int sig)
{
	(void)sig;
	g_data.c = g_data.c << 1;
	g_data.pos++;
}

void	cprint(void)
{
	ft_printf("%c", g_data.c);
	g_data.c = 0;
	g_data.pos = 0;
}

int	main(void)
{
	struct sigaction	act_0;
	struct sigaction	act_1;

	act_0.sa_handler = insert_bit_0;
	act_0.sa_flags = 0;
	act_1.sa_handler = insert_bit_1;
	act_1.sa_flags = 0;
	g_data.c = 0;
	g_data.pos = 0;
	if ((sigemptyset(&act_0.sa_mask) == -1)
		|| (sigaction(SIGUSER1, &act_0, NULL) == -1)
		|| (sigemptyset(&act_1.sa_mask) == -1)
		|| (sigaction(SIGUSER2, &act_1, NULL) == -1))
	{
		ft_printf("Failed to install signal handler(s)");
		return (1);
	}
	ft_printf("%d\n", getpid());
	while (1)
	{
		if (g_data.pos == 8)
			cprint();
	}
	return (EXIT_SUCCESS);
}
