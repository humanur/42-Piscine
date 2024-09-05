/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsagman <amsagman@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:08:23 by amsagman          #+#    #+#             */
/*   Updated: 2024/09/03 11:08:45 by amsagman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] == str2[i])
			i++;
		else
			break ;
	}
	return (str1[i] - str2[i]);
}

void	ft_sort_param(int ac, char **av)
{
	char	*tmp;
	int		j;

	j = 1;
	while (j < ac - 1)
	{
		if (ft_strcmp(av[j], av[j + 1]) > 0)
		{
			tmp = av[j];
			av[j] = av[j + 1];
			av[j + 1] = tmp;
			j = 0;
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	int	j;

	j = 1;
	ft_sort_param(ac, av);
	while (j < ac)
		ft_putstr(av[j++]);
	return (0);
}
