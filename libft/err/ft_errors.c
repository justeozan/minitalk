/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:31:27 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/08 15:39:23 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_error(char *str, int screen, bool exit_status)
{
	ft_putstr_fd(str, screen);
	exit(exit_status);
}

