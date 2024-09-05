/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsagman <amsagman@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:06:08 by amsagman          #+#    #+#             */
/*   Updated: 2024/09/03 17:20:14 by amsagman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	total( int size, char **strs, int lensep)
{
	int	i;
	int	total_size;

	total_size = 0;
	i = 0;
	while (i < size)
	{
		total_size = total_size + ft_strlen(strs[i]);
		i++;
		if (i < size - 1)
			total_size = total_size + lensep;
	}
	return (total_size + 1);
}

void	str_copy(char *result, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	r_i;

	i = 0;
	r_i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			result[r_i++] = strs[i][j++];
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
				result[r_i++] = sep[j++];
		}
		i++;
	}
	result[r_i] = '\0';
}

char	*merge_strings(int size, char **strs, char *sep)
{
	int		total_len;
	char	*result;

	total_len = total(size, strs, ft_strlen(sep));
	result = (char *)malloc(total_len);
	if (result == NULL)
		return (NULL);
	str_copy(result, strs, sep, size);
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	return (merge_strings(size, strs, sep));
}
