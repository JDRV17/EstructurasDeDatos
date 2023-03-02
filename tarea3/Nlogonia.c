//Juan Diego Rojas 8983626
#include <stdio.h>
int main()
{
    int k, n, m, x, y, i;
    k=1;
    while (k>0)
    {
        scanf("%d",&k);
        scanf("%d %d",&n, &m);
        for (i=0;i<k;i++)
        {
            scanf("%d %d",&x, &y);
            if(x>n&&y>m)
            {
                printf("NE\n");
            }
            if(x<n&&y>m)
            {
                printf("NO\n");
            }
            if(x>n&&y<m)
            {
                printf("SE\n");
            }
            if(x<n&&y<m)
            {
                printf("SO\n");
            }
            if(x==n||y==m)
            {
                printf("divisa\n");
            }
        }
    }
    return 0;
}