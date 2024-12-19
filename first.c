#include<stdio.h>
#include<conio.h>

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    int i = 0;

    while(str[i]=='a')
    {
        i++;
    }

    if(str[i]=='b' && str[i+1]=='b' && str[i+2] == '\0')
    {
        printf("Valid String");
    }
    else
    {
        printf("Invalid String");
    }

    return 0;
}
