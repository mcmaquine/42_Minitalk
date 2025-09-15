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

/*
Must correct the shift logic to start send from MSB to LSB
*/
int	main(int argc, char **argv)
{
	pid_t	pid;
	int		total_bits;
	int		i;

	pid = 0;
	total_bits = 0;
	i = 0;
	if (argc > 2)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			ft_printf("\t%c\n", argv[2][i]);
			while (total_bits < 8)
			{
				ft_printf("%d", argv[2][i] & 0x80);
				if (argv[2][i] & 0x80)
					kill(pid, SIGUSER2);
				else
					kill(pid, SIGUSER1);
				argv[2][i] = argv[2][i] >> 1;
				total_bits++;
				usleep(400);
			}
			total_bits = 0;
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
