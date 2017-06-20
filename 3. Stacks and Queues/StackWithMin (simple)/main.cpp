/* How would you design a stack which, in addition to push and pop, also has a function
min which returns the minimum element? Push, pop and min should all operate in
O(1) time */
#include <iostream>
#include <climits>
#include <stdlib.h>

using namespace std;

class stackElem
{
public:
    int val;
    stackElem *next;
    int min;

    stackElem( int value, int current_min)
    {
        val = value;
        next = 0;
        min = current_min;
    }
};

class stackImpl
{
    stackElem *top;

public:
    stackImpl() { top = 0; }

    int min()
    {
        if ( !top )
            return INT_MAX;
        else
            return top->min;
    }

    void push( int val)
    {
        stackElem *new_elem = new stackElem( val, std::min( min(), val));

        new_elem->next = top;
        top = new_elem;
    }

    int pop()
    {
        stackElem *to_delete = top;

        if ( !top )
        {
            cout << "Cannot pop from empty stack";

            exit( 1);
        }

        top = to_delete->next;
        delete to_delete;
    }

    void print()
    {
        stackElem *current = top;

        cout << "Stack (from top to bottom): ";

        while ( current )
        {
            cout << current->val << " ";
            current = current->next;
        }

        cout << "\n";
    }
};

void printMin( stackImpl stack)
{
    cout << "Current min: " << stack.min() << "\n";
}

int main()
{
    stackImpl stack;

    printMin( stack);
    stack.push( 100);
    stack.print();
    printMin( stack);
    stack.push( 1); stack.push( 50);
    stack.print();
    printMin( stack);
    stack.push( -5);
    stack.print();
    printMin( stack);
    stack.pop();
    stack.print();
    printMin( stack);
    stack.push( 20); stack.push( 70);
    stack.print();
    printMin( stack);
    stack.pop(); stack.pop(); stack.pop(); stack.pop();
    stack.push( 30); stack.push( 15); stack.push( 90);
    stack.print();
    printMin( stack);

    return 0;
}
