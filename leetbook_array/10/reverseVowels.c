#include <stdio.h>
#include <string.h>

int isVowels(char c)
{
    if((c == 'A')||(c == 'E')||(c == 'I')||(c == 'O')||(c == 'U'))
    {
        return 1;
    }
    if((c == 'a')||(c == 'e')||(c == 'i')||(c == 'o')||(c == 'u'))
    {
        return 1;
    }
    return 0;
}

void swap(char *c, char *d)
{
    char e = *c;
    *c = *d;
    *d = e;
    return;
}

char *reverseVowels(char *s){
    int len = strlen(s);
    int i = 0, j = len-1;
    while(i < j)
    {
        if(!isVowels(s[i]))
        {
            i++;
            continue;
        }
        if(!isVowels(s[j]))
        {
            j--;
            continue;
        }
        swap(&s[i], &s[j]);
        i++;
        j--;
    }
    return s;
}

void main()
{
    char s[] = "leetcode";
    printf("%s\n", reverseVowels(s));
}