#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include<string.h>
 
unsigned long long int howManyBoxesRequired(unsigned long long int a,unsigned long long int b);
int main()
{
    int a;
    scanf("%d",&a);
    int flag = 0;
    while(flag ==0)
    {
        if(a%2==0&&a>2)
            flag = 1;
        else if(a<=0)
                break;
        else
            {
                a -=2;
            }
    }
    if(flag ==1)
        printf("YES");
    else
        printf("NO");
          return 0;
}
 
