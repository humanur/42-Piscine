#include <stdio.h>

void ft_print_even(char *str) 
{
    int i = 0;
    while (str[i] != '\0') 
	{
		if (i % 2 == 0) 
		{
            	   printf("%c", str[i]);
        	}
        	i++;
    	}
}

int main(int argc, char *argv[]) 
{
    int j = 1;
    while (j < argc) 
	{
		ft_print_even(argv[j]);
		if (j < argc - 1) 
		{
			printf(" ");
		}
        j++;
    }
	printf("\n");

    return 0;
}
