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

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 3)
		ft_printf("I'm the server with process %d\n", getpid());
	return EXIT_SUCCESS;
}