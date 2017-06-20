/* Write code to reverse a C-Style String (C-String means that “abcd” is represented as
five characters, including the null character ) */

#include <iostream>
#include <stdio.h>

using namespace std;

void reverseString( char *str)
{
    if ( !str )
        return;

    int num = 0;

    while ( str[num] )
        num++;

    for ( int i = 0; i < num / 2; i++ )
    {
        char tmp = str[i];

        str[i] = str[num - i - 1];
        str[num - i - 1] = tmp;
    }
}

int main()
{
    char str[256];

    gets( str);
    reverseString( str);
    cout << str;

    return 0;
}
