/*Authour : RAJ ROY */

#include <stdio.h>
#include <stdlib.h>

int hasDuplicate(int a[9])
{
    int b[9],i;
    for(i=0;i<9;i++)
        b[i]=0;
    for(i=0;i<9;i++)
    {
        b[a[i]]++;
    }
    for(i=0;i<9;i++)
	if(b[i]>1)
            return 1;
    return 0;
}
void check(int array[9][9])
{
    int buff[9],flag=0,i,j,k=0;
    
    //checking the rows for uniqueness
    for(i=0;i<9;i++)
    {
        k=0;
        for(j=0;j<9;j++)
        {
            buff[k++]=array[i][j];
        }
        if(hasDuplicate(buff))
        {
            flag=1;
            printf("\nIncorrect solution\n");
            break;
        }
    }
    k=0;
    //checking the columns for uniqueness
    if(flag==0)
    {
        printf("Valid rows\n");
        for(i=0;i<9;i++)
        {
            k=0;
            for(j=0;j<9;j++)
            {
                buff[k++]=array[j][i];
            }
            if(hasDuplicate(buff))
            {
                flag=1;
                printf("\nIncorrect solution\n");
                break;
            }
        }
    }
    //checking the submatrix for uniqueness
    int r=0,c=0,rc=3,cc=3;
    if(flag==0)
    {
        printf("Valid columns\n");
        for(r=0;r<3;r++)
        {
            for(c=0;c<3;c++)
            {
                k=0;
                for(i=r*3;i<(r+1)*3;i++)
                {
                    for(j=c*3;j<(c+1)*3;j++)
                    {
                        buff[k++]=array[i][j];
                    }
                }
                if(hasDuplicate(buff))
                {
                    flag=1;
                    printf("\nIncorrect solution\n");
                    break;
                }
            }
        }
    }
    if(flag==0)
        printf("Valid solution\n");
}

int main()
{
    int a[9][9]={{1,2,3,4,5,6,7,8,9},
		{7,8,9,1,2,3,4,5,6},
		{4,5,6,7,8,9,1,2,3},
		{3,1,2,8,4,5,9,6,7},
		{6,9,7,3,1,2,8,4,5},
		{8,4,5,6,9,7,3,1,2},
		{2,3,1,5,7,4,6,9,8},
		{9,6,8,2,3,1,5,7,4},
		{5,7,4,9,6,8,2,3,1}};
	check(a);
	return 0;
}

