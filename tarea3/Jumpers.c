//Juan Diego Rojas 8983626
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j, jolly;
    int *sequence, *restas, *numeros;
    jolly=1;
    while (scanf("%d",&n)==1)
    {
        sequence = (int *) malloc(n* sizeof(int));
        restas = (int *) malloc((n-1)* sizeof(int));
        numeros= (int *) malloc((n-1)* sizeof(int));
        if (n>1)
        {
            for (i=0;i<n;i++)
            {
                scanf("%d",&sequence[i]);
                if (i>0)
                {
                    numeros[i-1]=i;
                }
            }
            for (i=0;i<n-1;i++)
            {
                if(sequence[i]-sequence[i+1]>0)
                {
                    restas[i]=(sequence[i]-sequence[i+1]);
                }
                else
                {
                    restas[i]=((-1)*(sequence[i]-sequence[i+1]));
                }
            }
            for (i=0; i<n;i++)
            {
                for (j=0; j<n-1;j++)
                {
                    if(restas[j]==numeros[i])
                    {
                        numeros[i]=0;
                    }
                }
                
            }
            for (i=0; i<n-1 ;i++)
            {
                if (numeros[i]!=0)
                {
                    jolly=0;
                    i=n;
                }
                else{
                    jolly=1;
                }   
            }
            if (jolly==0)
            {
                printf("Not jolly\n");
            }
            else
            {
                printf("Jolly\n");
            }
        }
        else
        {
            printf("Jolly\n");
        }
    }    
    return 0;
}

