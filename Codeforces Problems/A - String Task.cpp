#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int removeVowel(char word[]);
int isVowel(char alphapet);
int main()
{
    char word[100];
    scanf("%s",word);
    removeVowel(word);
 
 
 
   return 0;
 
}
int removeVowel(char word[])
{
 
    for(int i=0;i<strlen(word);i++)
    {
        char temp = tolower(word[i]);
        if(isVowel(temp)==0)
            {
                printf(".%c",tolower(word[i]));
                temp = tolower(word[i+1]);             
            }
    }
 
 
}
int isVowel(char alphapet)
{
    if(alphapet =='a'||alphapet=='e'||alphapet=='i'||alphapet=='o'||alphapet=='u'||alphapet=='y')
        return 1;
    else
        return 0;
}
 
 
 
 
