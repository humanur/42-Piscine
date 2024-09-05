#include <unistd.h>
void putchar(char c)
{
	write(1, &c, 1);
}
void putnbr(int nb)
{
	if (nb == -2147483648)
	{
		putchar('-');
		putchar('2');
		putnbr(147483648);
	}
	else if (nb < 0)
	{
		putchar('-');
		putnbr(-nb);
	}
	else if (nb > 9)
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
	else
		putchar(nb + 48);
}
int main()
{
	int nb;

	nb = 1;
	while(nb <= 100)
	{
		if (nb % 3 == 0 && nb % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (nb % 3 == 0)
			write(1, "fizz", 4);
		else if (nb % 5 == 0)
			write(1, "buzz", 4);
		else
			putnbr(nb);
		write(1, "\n", 1);
		nb++;
	}
}
