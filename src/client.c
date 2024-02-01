/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:06:43 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/29 11:20:43 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_bit_handler;

// void	ft_send_bits(int pid, char c)
// {
// 	int	bit;

// 	bit = 0;
// 	while (bit < 0)
// 	{
// 		if ((c & (1 << bit)))
// 			kill(pid, SIGUSR1);
// 		else
// 			kill(pid, SIGUSR2);
// 		usleep(100);
// 		bit++;
// 	}
// }

// int	main(int ac, char **av)
// {
// 	int	pid;
// 	int	i;

// 	i = 0;
// 	if (ac == 3)
// 	{
// 		pid = ft_atoi(av[1]);
// 		while (av[2][i] != '\0')
// 		{
// 			ft_send_bits(pid, av[2][i]);
// 			i++;
// 		}
// 		ft_send_bits(pid, '\n');
// 	}
// 	else
// 	{
// 		ft_printf("Error");
// 		return (1);
// 	}
// 	return (0);
// }

int	validation_server(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_printf("Message sent and received.\n");
		exit(EXIT_SUCCESS);
	}
	else if (signal == SIGUSR1)
		g_bit_handler = 1;
}

void	send_bit(int pid, char c)
{
	int	bit;

	bit = __CHAR_BIT__ * sizeof(c) - 1;
	while (bit >= 0)
	{
		g_bit_handler = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pid--;
		while (g_bit_handler != 1)
			usleep(100);
	}
}

int	check_av(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3 || !av[2][0])
	{
		ft_putstr_fd("Error arguments, please try again.\n", 2);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	if (pid == 0)
	{
		ft_putstr_fd("Error: PID 0 is reserved for the kernel.\n", 2);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (av[1][++i])
	{
		if (!(ft_isdigit(av[1][i])) || pid < 0)
		{
			ft_putstr_fd("Error: a PID only has positive decimal numbers.", 2);
			exit(EXIT_FAILURE);
		}
	}
	return (pid);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	pid = check_av(ac, av);
	i = -1;
	// signal(SIGUSR1, validation_server); //b
	// signal(SIGUSR2, validation_server); //b
	while (av[2][++i])
		send_bit(pid, av[2][i]);
	send(pid, '\n');
	send(pid, '\0');
	while (1)
		pause ();
}