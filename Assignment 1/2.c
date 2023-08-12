#include <stdio.h>

char *ones[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

void roman(int n)
{
    if (n < 10)
        printf(ones[n - 1]);
    else if (n < 40)
    {
        for (int i = 0; i < n / 10; i++)
        {
            printf("X");
        }
        n %= 10;
        printf(ones[n - 1]);
    }
    else if (n < 50)
    {
        printf("XL");
        n %= 10;
        printf(ones[n - 1]);
    }
    else if (n < 90)
    {
        printf("L");
        roman(n - 50);
    }
    else if (n < 100)
    {
        printf("XC");
        roman(n - 90);
    }
    else if (n < 400)
    {
        for (int i = 0; i < n / 100; i++)
        {
            printf("C");
        }
        n %= 100;
        roman(n);
    }
    else if (n < 500)
    {
        printf("CD");
        roman(n - 400);
    }
    else if (n < 900)
    {
        printf("D");
        roman(n - 500);
    }
    else if (n < 1000)
    {
        printf("CM");
        roman(n - 900);
    }
    else
    {
        for (int i = 0; i < n / 1000; i++)
        {
            printf("M");
        }
        n %= 1000;
        roman(n);
    }
}

void main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Roman representation: ");
    if (n == 0)
    {
        printf("0");
        return;
    }
    roman(n);
}