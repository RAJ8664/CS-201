#include <stdio.h>

char *ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
char *tens[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char *doubleTen[] = {"Ten", "Eleven", "Tweleve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

void twoDigit(int n)
{
    if (n < 10)
    {
        printf(ones[n]);
    }
    else if (n < 20)
    {
        printf(doubleTen[n - 10]);
    }
    else if (n < 100)
    {
        printf("%s %s", tens[n / 10 - 2], ones[n % 10]);
    }
}

void indian(int n)
{
    if (n == 0)
    {
        printf("Zero");
        return;
    }
    if (n < 0)
        printf("Negative ");
    if (n < 100)
    {
        twoDigit(n);
    }
    else if (n < 1000)
    {
        printf("%s Hundred ", ones[n / 100]);
        n %= 100;
        if (n != 0)
            indian(n);
    }
    else if (n < 100000)
    {
        indian(n / 1000);
        printf(" Thousand ");
        n %= 1000;
        if (n != 0)
            indian(n);
    }
    else if (n < 10000000)
    {
        indian(n / 100000);
        printf(" Lakhs ");
        n %= 100000;
        if (n != 0)
            indian(n);
    }
    else if (n < 1000000000)
    {
        indian(n / 10000000);
        printf(" Crores ");
        n %= 10000000;
        if (n != 0)
            indian(n);
    }
}

void international(int n)
{
    if (n == 0)
    {
        printf("Zero");
        return;
    }
    if (n < 0)
        printf("Negative ");
    if (n < 100)
    {
        twoDigit(n);
    }
    else if (n < 1000)
    {
        printf("%s Hundred ", ones[n / 100]);
        n %= 100;
        if (n != 0)
            international(n);
    }
    else if (n < 1000000)
    {
        international(n / 1000);
        printf(" Thousand ");
        n %= 1000;
        if (n != 0)
            international(n);
    }
    else if (n < 1000000000)
    {
        international(n / 1000000);
        printf(" Millions ");
        n %= 1000000;
        if (n != 0)
            international(n);
    }
}

void main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("\nIndian rerpresentation: ");
    indian(n);
    printf("\nInternational representation: ");
    international(n);
}