/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:44:09 by mmaquine          #+#    #+#             */
/*   Updated: 2025/09/18 14:44:32 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*join(char *s1, char c)
{
	char	s[1];
	char	*joined;

	s[0] = c;
	if (!s1)
		s1 = ft_calloc(1, 1);
	joined = ft_strjoin(s1, s);
	free(s1);
	return (joined);
}

int	new_action(void (*fact)(int, siginfo_t *, void *), int sig)
{
	struct sigaction	act;

	act.sa_sigaction = fact;
	act.sa_flags = SA_SIGINFO;
	if ((sigemptyset(&act.sa_mask) == -1)
		|| (sigaction(sig, &act, NULL) == -1))
		return (1);
	return (0);
}
