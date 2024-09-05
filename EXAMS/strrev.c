#include <unistd.h>
char ft_strrev(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	while(i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	return (i);
}
int main(int ac, char **av)
{
	if(ac)
		ft_strrev(av[1]);
	write(1, "\n", 1);
}
