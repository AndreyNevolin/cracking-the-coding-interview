/* Describe how you could use a single array to implement three stacks */
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int arr_size = 100;
int *arr = 0;
int num_elems[3] = {0, 0, 0};

void printStacks( )
{
    for ( int i = 0; i < 3; i++ )
    {
        cout << "Stack " << i << ": ";

        for ( int j = 0; j < num_elems[i]; j++ )
            cout << arr[i + j * 3] << " ";

        cout << "\n";
    }
}

void push( int stack_num, int val)
{
    if ( num_elems[stack_num] == arr_size / 3 )
    {
        cout << "Stack " << stack_num << " overflow";

        exit( 1);
    }

    arr[stack_num + num_elems[stack_num] * 3] = val;
    num_elems[stack_num]++;
}

int pop( int stack_num)
{
    if ( !num_elems[stack_num] )
    {
        cout << "Popping from empty stack " << stack_num;

        exit( 1);
    }

    int ind = stack_num + (num_elems[stack_num] - 1) * 3;
    int val = arr[ind];

    arr[ind] = 0;
    num_elems[stack_num]--;

    return val;
}

int peek( int stack_num)
{
    if ( !num_elems[stack_num] )
    {
        cout << "Peeking from empty stack " << stack_num;

        exit( 1);
    }

    return arr[stack_num + (num_elems[stack_num] - 1) * 3];
}

bool isEmpty( int stack_num)
{
    return num_elems[stack_num] == 0;
}

int main()
{
    arr = new int[arr_size];
    memset( arr, 0, sizeof(int) * arr_size);

    push( 0, 3);
    push( 1, 1);
    push( 0, 6);
    push( 0, 9);
    pop( 1);
    push( 2, 2);
    push( 2, 5);
    push( 0, 12);
    push( 1, 4);

    printStacks( );

    return 0;
}
