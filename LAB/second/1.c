#include <stdio.h>
#include <stdlib.h>
unsigned char *allocate(int n)
{
    int m=(n/8.0+0.99999999999);
    unsigned char *array=(unsigned char *)malloc(m*sizeof(unsigned char));
    printf("%d bits of memory are allocated\n",m*8);
    for(int i=0;i<m;i++)
        array[i]='\0';
    return array;
}


void insert(char *array, int i, int n)
{
    if(i>=n)
    {
        printf("The index cannot be greater than the size of the array\n");
        return;
    }
    int x=(i/8.0+0.99999999999);
    int k= (i%8==0)? x: x-1;
    int p= i%8;
    unsigned char m=1<<p;
    array[k]=array[k]|m;
}


unsigned char getBit(char *array, int i, int n)
{
    if(i>=n)
    {
        printf("The index cannot be greater than the size of the array\n");
        return 0;
    }
    int x=(i/8.0+0.99999999999);
    int k= (i%8==0)? x: x-1;
    int p= i%8;
    unsigned char m=1<<p;
    return (array[k]&m)>>p;
}


void del_bit(char *array, int i, int n)
{
    if(i>=n)
    {
        printf("The index cannot be greater than the size of the array\n");
        return;
    }
    int x=(i/8.0+0.99999999999);
    int k= (i%8==0)? x: x-1;
    int p= i%8;
    unsigned char m=~(1<<p);
    array[k]=array[k]&m;
}


int main()
{
    char *array;
    int i,n=10;
    for(i=0;i<n;i++)
    {
        insert(array,i,n);
    }
    printf("All %d bits are inserted with 1\n",n);
    for(i=0;i<n;i++)
    {
        printf("%d\t",getBit(array,i,n));
    }
    for(i=0;i<n;i++)
    {
        del_bit(array,i,n);
    }
    printf("\nDeleted array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",getBit(array,i,n));
    }
    i=8;
    insert(array,i,n);
    printf("\nInserted at %d index in the array:\n",i);
    for(i=0;i<n;i++)
    {
        printf("%d\t",getBit(array,i,n));
    }
    return 0;
}
