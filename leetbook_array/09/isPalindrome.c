#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NOT_A_NUMBER_OR_LETTER ((char)0xff)

char standardize(char c)
{
    if((c >= 'a')&&(c <= 'z'))
    {
        return c;
    }
    else if((c >= 'A')&&(c <= 'Z'))
    {
        return c + ('a' - 'A');
    }
    else if((c >= '0')&&(c <= '9'))
    {
        return c;
    }
    else
    {
        return NOT_A_NUMBER_OR_LETTER;
    }
}

bool isPalindrome(char *s){
    int len = strlen(s);
    int i = 0, j = len-1;
    while(i < j)
    {
        char c, d;
        while(NOT_A_NUMBER_OR_LETTER == (c = standardize(s[i])))
        {
            i++;
            if(i > j)
            {
                return true;
            }
        }

        while(NOT_A_NUMBER_OR_LETTER == (d = standardize(s[j])))
        {
            j--;
        }
        
        if(c != d)
        {
            return false;
        }

        i++;
        j--;
    }
    return true;
}

void main()
{
    char s[] = "A man, a plan, a canal: Panama";
    printf("%d\n", isPalindrome(s));
    return;
}