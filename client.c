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

/*
Must correct the shift logic to start send from MSB to LSB
*/
int	main(int argc, char **argv)
{
	pid_t	pid;
	int		shift_bits;
	int		i;

	pid = 0;
	shift_bits = 7;
	i = 0;
	if (argc > 2)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			while (shift_bits >= 0)
			{
				if ((argv[2][i] >> shift_bits) & 0x1)
					kill(pid, SIGUSER2);
				else
					kill(pid, SIGUSER1);
				shift_bits--;
				usleep(1000);
			}
			shift_bits = 7;
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
