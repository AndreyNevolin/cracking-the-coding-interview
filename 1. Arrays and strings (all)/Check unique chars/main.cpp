/* Implement an algorithm to determine if a string has all unique characters What if you
can not use additional data structures? */

#include <iostream>
#include <string.h>

using namespace std;

bool checkUniqueChars( string s)
{
    bool chars[256];

    memset( chars, false, sizeof( chars));

    for ( int i = 0; i < s.size(); i++ )
        if ( chars[s[i]] )
            return false;
        else
            chars[s[i]] = true;

    return true;
}

int main()
{
    string str;

    getline( cin, str);

    cout << checkUniqueChars( str);

    return 0;
}
