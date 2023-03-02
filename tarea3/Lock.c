//Juan Diego Rojas 8983626
#include <stdio.h>
int main()
{
    int position, lock1, lock2, lock3, degrees;
    position=1;
    while (position>0 || lock1>0 || lock2>0 || lock3>0)
    {
        scanf("%d %d %d %d",&position,&lock1,&lock2,&lock3);
        degrees=720+360;
        if(position<lock1)
        {
            degrees=degrees+(9*((40+position)-lock1));
        }
        else
        {
            degrees=degrees+(9*(position-lock1));
        }
        if(lock1>lock2)
        {
            degrees=degrees+(9*((40+lock2)-lock1));
        }
        else
        {
            degrees=degrees+(9*(lock2-lock1));
        }
        if(lock2<lock3)
        {
            degrees=degrees+(9*((40+lock2)-lock3));
        }
        else
        {
            degrees=degrees+(9*(lock2-lock3));
        }
        if (position>0 || lock1>0 || lock2>0 || lock3>0)
        {
            printf("%d\n",degrees);
        }
    }
    return 0;
}