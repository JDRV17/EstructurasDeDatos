//Juan Diego Rojas 8983626
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t, i, n, j, k, max, min, distancia;
    int *positions;
    scanf("%d",&t);
    for (i=0;i<t;i++)
    {
        scanf("%d",&n);
        positions = (int *) malloc(n* sizeof(int));
        for (j=0;j<n;j++)
        {
            scanf("%d",&positions[j]);
        }
        max=positions[0];
        min=positions[0];
        for (k=0;k<n;k++)
        {
            if (max<positions[k])
            {
                max=positions[k];
            }
            if (min>positions[k])
            {
                min=positions[k];
            }
        }
        distancia=((max-min)*2);
        printf("%d\n",distancia);
    }
    return 0;
}