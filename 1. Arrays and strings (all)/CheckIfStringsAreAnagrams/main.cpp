/* Write a method to decide if two strings are anagrams or not */
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

bool areAnagrams( string s1, string s2)
{
    int symCount[256];

    memset( symCount, 0, sizeof( int) * 256);

    if ( s1.size() != s2.size() )
        return false;

    for ( int i = 0; i < s1.size(); i++ )
        symCount[s1[i]]++;

    for ( int i = 0; i < s2.size(); i++ )
        if ( !symCount[s2[i]] )
            return false;
        else
            symCount[s2[i]]--;

    return true;
}

int main()
{
    string s1, s2;

    cout << "String 1: ";
    getline( cin, s1);
    cout << "String 2: ";
    getline( cin, s2);

    if ( areAnagrams( s1, s2) )
        cout << "Strings are anagrams";
    else
        cout << "Strings are not anagrams";

    return 0;
}
