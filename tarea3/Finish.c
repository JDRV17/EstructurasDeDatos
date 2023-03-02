//Juan Diego Rojas 8983626
#include <stdio.h>

int main() 
{
    int t, n, i, j, start, gas, faltagas;
    scanf("%d", &t);

    for (i = 1; i <= t; i++) 
    {
        scanf("%d", &n);
        int p[n], q[n];
        start=0;
        gas=0;
        faltagas=0;

        for (j=0;j<n;j++) 
        {
            scanf("%d",&p[j]);
        }
        for (j=0;j<n;j++) 
        {
            scanf("%d",&q[j]);
        } 
        for (j=0;j<n;j++) 
        {
            gas=gas+(p[j]-q[j]);
            if (gas<0) 
            {
                faltagas=faltagas+gas;
                start=j+1;
                gas=0;
            }
        }

        if ((gas+faltagas)>=0) 
        {
            printf("Case %d: Possible from station %d\n", i, start + 1);
        } 
        else 
        {
            printf("Case %d: Not possible\n", i);
        }
    }

    return 0;
}

