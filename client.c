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

#include "./libft/libft.h"

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		loops;

	pid  = 0;
	loops = 95;
	if (argc > 1)
	{
		pid = ft_atoi(argv[1]);
		while (loops > 0)
		{
			kill(pid, SIGUSER1);
			usleep(400);
			loops--;
		}
	}
	return (EXIT_SUCCESS);
}