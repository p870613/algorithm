#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char ch;
    char word[100];
    char s[100];
    
    scanf("%c\n%s\n%[^\n]s",&ch,word,s);
   
    printf("%c\n", ch);
    printf("%s\n", word);
    printf("%s\n", s);
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
