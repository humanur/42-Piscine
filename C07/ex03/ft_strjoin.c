/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsagman <amsagman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:57:48 by amsagman          #+#    #+#             */
/*   Updated: 2024/09/02 15:27:22 by amsagman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	calculate_total_length(int size, char **strs, int sep_len)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	return (total + (size - 1) * sep_len);
}

void	join_strings(char *result, int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	k;
	int	sep_len;

	i = 0;
	j = 0;
	k = 0;
	sep_len = ft_strlen(sep);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			result[k++] = strs[i][j++];
		if (i < size - 1)
		{
			j = 0;
			while (j < sep_len)
				result[k++] = sep[j++];
		}
		i++;
	}
	result[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_length;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	total_length = calculate_total_length(size, strs, ft_strlen(sep));
	result = (char *)malloc((total_length + 1) * sizeof(char));
	if (!result)
		return (0);
	join_strings(result, size, strs, sep);
	return (result);
}
