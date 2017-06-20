/* Describe how you could use a single array to implement three stacks */
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class stackElem
{
    public:
        int val;
        int prev;
};

int arr_size = 100;
stackElem *arr;
int next_free = 0;
int tops[3] = {-1, -1, -1};

void printStacks()
{
    cout << "Printed from top to bottom\n";

    for ( int i = 0; i < 3; i++ )
    {
        cout << "Stack " << i << ": ";

        int top = tops[i];

        while ( top != -1 )
        {
            cout << arr[top].val << " ";
            top = arr[top].prev;
        }

        cout << "\n";
    }
}

void push( int stack_num, int val)
{
    if ( next_free == arr_size )
    {
        cout << "Stack overflow";

        exit( 1);
    }

    arr[next_free].val = val;
    arr[next_free].prev = tops[stack_num];
    tops[stack_num] = next_free;
    next_free++;
}

int pop( int stack_num)
{
    if ( tops[stack_num] == -1 )
    {
        cout << "Popping from empty stack " << stack_num;

        exit( 1);
    }

    int ind = tops[stack_num];
    int val = arr[ind].val;

    tops[stack_num] = arr[ind].prev;
    arr[ind].val = 0;
    arr[ind].prev = 0;

    /* Если элемент находится в самом конце аллоцированной части массива,
       мы можем переиспользовать память */
    if ( ind == next_free - 1 )
        next_free--;

    return val;
}

int peek( int stack_num)
{
    if ( tops[stack_num] == -1 )
    {
        cout << "Peeking from empty stack " << stack_num;

        exit( 1);
    }

    return arr[tops[stack_num]].val;
}

bool isEmpty( int stack_num)
{
    return tops[stack_num] == -1;
}

int main()
{
    arr = new stackElem[arr_size];
    memset( arr, 0, sizeof( stackElem) * arr_size);

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
