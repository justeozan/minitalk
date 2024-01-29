/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:06:51 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/29 11:21:59 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <stdlib.h> //est ce que j'ai le droit ?
#include <stdio.h>


// int	main(int ac, char **av)
// {
// 	int	pid;

// 	(void)av;
// 	if (ac != 1)
// 	{
// 		ft_printf("Error");
// 		return (0);
// 	}
// 	pid = getpid();
// 	ft_printf("%d", pid);
// 	while (ac == 1)
// 	{
// 		signal(SIGUSR1, ft_handler);
// 		signal(SIGUSR2, ft_handler);
// 		pause ();
// 	}
// 	return (0);
// } //passé par signal c'est pas ouf

void	handler_signal(int signal, int *info, void *context)
{

}

int	main(void)
{
	int					pid;
	sigset_t			signal;
	struct sigaction	action;

	pid = getpid();
	sigemtyset(&signal);
	sigaddset(&signal, SIGUSR1);
	sigaddset(&signal, SIGUSR2);
	action.sa_flags = signal;
	action.sa_mask = signal;
	action.sa_handler = NULL;
	action.sa_sigaction = handler_signal;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("PID server -> %d\n", pid);
	while (1)
		pause();
	return (0);
}