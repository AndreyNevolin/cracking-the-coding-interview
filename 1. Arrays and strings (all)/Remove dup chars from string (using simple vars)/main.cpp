/* Design an algorithm and write code to remove the duplicate characters in a string
without using any additional buffer NOTE: One or two additional variables are fine
An extra copy of the array is not
FOLLOW UP
Write the test cases for this method */
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void removeDups( char *str)
{
    if ( !str || !str[0] )
        return;

    int current = 1, res_end = 0;

    while ( str[current] )
    {
        int i;

        for ( i = 0; i <= res_end; i++ )
        {
            if ( str[current] == str[i] )
                break;
        }

        if ( i == res_end + 1 )
        {
            str[++res_end] = str[current];
        }

        current++;
    }

    str[++res_end] = 0;
}

int main()
{
    char str[256];

    gets( str);
    removeDups( str);
    cout << str;

    return 0;
}
