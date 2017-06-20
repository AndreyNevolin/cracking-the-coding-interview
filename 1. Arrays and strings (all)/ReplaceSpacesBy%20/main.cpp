/* Write a method to replace all spaces in a string with ‘%20’ */
#include <iostream>
#include <assert.h>
#include <stdio.h>

using namespace std;

void replaceSpacesByCode( char *str)
{
    if ( !str )
        return;

    int spaceCount = 0, ind = 0;

    while( str[ind] && (ind < 256) )
        if ( str[ind++] == ' ' )
            spaceCount++;

    assert( !str[ind]);

    int current = ind - 1;

    ind += spaceCount * 2;
    str[ind--] = 0;

    while ( current >= 0 )
    {
        if ( str[current] != ' ' )
            str[ind--] = str[current];
        else
        {
            str[ind--] = '0';
            str[ind--] = '2';
            str[ind--] = '%';
        }

        current--;
    }
}

int main()
{
    char str[256];

    gets( str);
    replaceSpacesByCode( str);
    cout << str;

    return 0;
}
