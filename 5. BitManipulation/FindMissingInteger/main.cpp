/* An array A[1... n] contains all the integers from 0 to n except
   for one number which is missing. In this problem, we cannot access
   an entire integer in A with a single operation. The elements of A are
   represented in binary, and the only operation we can use to access them
   is “fetch the jth bit of A[i]”, which takes constant time. Write code
   to find the missing integer. Can you do it in O(n) time? */
#include <iostream>
#include <vector>

using namespace std;

unsigned findMissing( vector<unsigned> arr)
{
    vector<unsigned> zero_arr, one_arr;

    if ( !arr.size() )
        return 0;

    for ( int i = 0; i < arr.size(); i++ )
        if ( arr[i] & 1 )
            one_arr.push_back( arr[i] >> 1);
        else
            zero_arr.push_back( arr[i] >> 1);

    if ( one_arr.size() < zero_arr.size() )
        return (findMissing( one_arr) << 1) + 1;
    else
        return findMissing( zero_arr) << 1;
}

int main()
{
    const int n = 10;
    unsigned arr[n] = {0, 5, 2, 3, 6, 1, 8, 7, 9, 10};
    vector<unsigned> vect_arr( arr, arr + n);

    cout << "Missing number: " << findMissing( vect_arr);

    return 0;
}
