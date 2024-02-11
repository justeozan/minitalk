/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:06:51 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/11 14:46:31 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	print_str(char **str, unsigned long long *i, siginfo_t *info)
{
	ft_printf("%s", *str);
	free(*str);
	*str = NULL;
	*i = 0;
	kill(info->si_pid, SIGUSR2);
}

char	*ft_realloc(char *str, int l, char c)
{
	char	*new_str;
	int		i;

	new_str = (char *)malloc(sizeof(char) * (l + 2));
	if (!new_str)
		return (NULL);
	i = 0;
	if (str)
	{
		while (str[i])
		{
			new_str[i] = str[i];
			i++;
		}
	}
	new_str[i] = c;
	i++;
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

void	handler_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char		c = 0;
	static int					bit = -1;
	static unsigned long long	i = 0;
	static char					*dest = NULL;

	(void)context;
	if (kill(info->si_pid, 0) < 0)
	{
		ft_printf("ERROR : cant send signal to pid: %d\n", info->si_pid);
		exit(EXIT_FAILURE);
	}
	if (bit < 0)
		bit = __CHAR_BIT__ * sizeof(c) - 1;
	if (signal == SIGUSR1)
		c |= 1 << bit;
	else if (signal == SIGUSR2)
		c &= ~(1 << bit);
	if (!bit && c)
		dest = ft_realloc(dest, i++, c);
	else if (!bit && !c)
		print_str(&dest, &i, info);
	bit--;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;
	sigset_t			signals;

	pid = getpid();
	sigemptyset(&signals);
	sigaddset(&signals, SIGUSR1);
	sigaddset(&signals, SIGUSR2);
	action.sa_flags = SA_SIGINFO;
	action.sa_mask = signals;
	action.sa_handler = NULL;
	action.sa_sigaction = handler_signal;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("PID server -> %d\n", pid);
	while (1)
		pause();
	return (0);
}
