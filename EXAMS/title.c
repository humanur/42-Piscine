#include <stdio.h>

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        printf("\n");
        return 0;
    }

    int j = 0;
    int isNewWord = 1;
    
    while (argv[1][j]) 
    {
        char c = argv[1][j];
        
        if (c >= 32 && c <= 126)
        {
            if (c == ' ') 
            {
                printf("%c", c);
                isNewWord = 1;
            } 
            else 
            {
                if (isNewWord) 
                {
                    if (c >= 'a' && c <= 'z') 
                    {
                        c = c - 32;
					}
                    isNewWord = 0;
                }
                printf("%c", c);
            }
        }
        j++;
    }
    
    printf("\n");
    return 0;
}
