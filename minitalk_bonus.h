/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:38:22 by mmaquine          #+#    #+#             */
/*   Updated: 2025/09/15 19:41:02 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "./libft/libft.h"
# include <signal.h>
# ifndef SIGUSER1
#  define SIGUSER1 10
# endif
# ifndef SIGUSER2
#  define SIGUSER2 12
# endif

typedef struct s_data
{
	char	c;
	int		pos;
	char	*str;
}	t_data;

char	*join(char *s1, char c);
#endif
