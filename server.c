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

#include "./libft/libft.h"

char byte;

void	my_handler(int sig)
{
	(void)sig;
	if (ft_isprint(byte))
	{
		ft_printf("Char %c\n", byte);
	}
	byte++;
	if (byte == 127)
		raise(SIGKILL);
}

int	main()
{
	struct sigaction act;

	byte = 32;
	ft_printf("%d\n", getpid());
	act.sa_handler = my_handler;
	act.sa_flags = 0;
	if ((sigemptyset(&act.sa_mask) == -1) ||
		(sigaction(SIGUSER1, &act, NULL) == -1))
		ft_printf("Failed to install SIGUSER1 signal handler");
	while(1)
	{}
	return EXIT_SUCCESS;
}