/* Assume you have a method isSubstring which checks if one word is a substring of
another Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using
only one call to isSubstring (i e , “waterbottle” is a rotation of “erbottlewat” */
#include <iostream>
#include <string>

using namespace std;

bool isSubstring( string candidate, string s)
{
    return s.find( candidate) != string::npos;
}

bool isRotation( string s1, string s2)
{
    if ( s1.size() != s2.size() )
        return false;

    string temp = s1 + s1;

    return isSubstring( s2, temp);
}

int main()
{
    string s1, s2;

    cout << "First string: ";
    getline( cin, s1);
    cout << "Second string: ";
    getline( cin, s2);

    if ( isRotation( s1, s2) )
        cout << "Strings are rotations of each other";
    else
        cout << "Strings are not rotations of each other";

    return 0;
}
