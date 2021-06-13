/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faherrau <faherrau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:44:17 by faherrau          #+#    #+#             */
/*   Updated: 2021/06/13 23:15:06 by faherrau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
void	error(char *str)
{
	ft_putstr(str);
	exit(0);
}

void	ft_putnbr(int n)
{
	if (n < 10)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

int	main(int argc)
{
	struct sigaction	catch;
	
	if (argc != 1)
		error("Wrong arguments input\n");
	write(1, "Starting Server...\nServer Online\nPID : ", 38);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	/* Probably some functions */
	catch.sa_flags = SA_SIGINFO;
	//catch.sa_sigaction = sig_handler(); /* function to define later */
	if ((sigaction(SIGUSR1, &catch, 0)) == -1)
		error("Error sigaction\n");
	if ((sigaction(SIGUSR2, &catch, 0)) == -1)
		error("Error sigaction\n");
	while (1)
		pause();
	return (0);
}