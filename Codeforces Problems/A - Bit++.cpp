#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int value = 0;
    int n ;
    scanf("%d",&n);
    for(int i =0;i<n;i++)
    {
        char temp[4];
        scanf("%s",&temp);
        if(temp[1] == '+')
            value+=1;
        else if(temp[1] == '-')
            value-=1;
 
    }
    printf("%d",value);
 
 
 
 
 
 
    return 0;
}
 
