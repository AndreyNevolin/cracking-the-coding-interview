/* Design an algorithm and write code to remove the duplicate characters in a string
without using any additional buffer NOTE: One or two additional variables are fine
An extra copy of the array is not
FOLLOW UP
Write the test cases for this method */

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

void removeDupChars( char *str)
{
    bool chars[256];

    if ( !str )
        return;

    memset( chars, false, sizeof( chars));

    char *current = str, *str_end = str;

    while( *current )
    {
        if ( !chars[*current] )
        {
            chars[*current] = true;
            *str_end++ = *current;
        }

        current++;
    }

    *str_end = 0;
}

int main()
{
    char str[256];

    gets( str);
    removeDupChars( str);
    cout << str;

    return 0;
}
