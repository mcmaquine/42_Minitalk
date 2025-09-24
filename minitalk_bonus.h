/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:38:22 by mmaquine          #+#    #+#             */
/*   Updated: 2025/09/24 15:36:46 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include "./libft/libft.h"
# include <signal.h>
# ifndef SIGUSR1
#  define SIGUSR1 10
# endif
# ifndef SIGUSR2
#  define SIGUSR2 12
# endif

typedef struct s_data
{
	char	c;
	int		pos;
	char	*str;
}	t_data;

char	*join(char *s1, char c);
int		new_action(void (*fact)(int), int sig);
int		new_action_w_info(void (*fact)(int, siginfo_t *, void *), int sig);
#endif
