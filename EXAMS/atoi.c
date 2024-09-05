
int	atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * sign);
}

#include <stdio.h>
int main(int ac, char **av)
{
	if (ac == 2)
		printf("%d\n", atoi(av[1]));

	/*char	*str = "   ---+--+01234ab567"; //argüman almadan çıktı alabilmek için maindeki ac ve **av silinmeli.
	printf("%d", atoi(str));*/ 
}
