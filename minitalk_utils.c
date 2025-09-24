/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:44:09 by mmaquine          #+#    #+#             */
/*   Updated: 2025/09/24 14:52:41 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*join(char *s1, char c)
{
	char	*s;
	char	*joined;

	if (!c)
	{
		s = ft_calloc(2, 1);
		s[0] = c;
	}
	else
		s = ft_calloc(1, 1);
	if (!s1)
		s1 = ft_calloc(1, 1);
	joined = ft_strjoin(s1, s);
	free(s1);
	free(s);
	return (joined);
}
