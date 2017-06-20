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

    stackElem( int value)
    {
        val = value;
        next = 0;
    }
};

class stackImpl
{
protected:
    stackElem *top;

public:
    stackImpl() { top = 0; }

    void push( int val)
    {
        stackElem *new_elem = new stackElem( val);

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

    int peek()
    {
        if ( !top )
        {
            cout << "Cannot peek from empty stack";

            exit( 1);
        }

        return top->val;
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

/* ƒальнейшие улучшени€...
   ≈сли в основной стек может быть положено много одинаковых элементов, то стек,
   содержащий минимумы может разростатьс€ вплоть до размеров основного стека.
   Ётого можно избежать, если стек, сожержащий минимумы, заменить стеком, хран€щим
   пары {минимум, счетчик}, где "счетчик" - количество раз, которое встретилс€
   "минимум". “аким образом, можно не добавл€ть повторные минимумы как отдельные
   элементы стека, а просто инкрементировать "счетчик" */
class stackWithMinImpl : public stackImpl
{
    stackImpl mins;

public:
    int min()
    {
        if ( !top )
            return INT_MAX;

        return mins.peek();
    }

    int pop()
    {
        if ( top->val == min() )
            mins.pop();

        stackImpl::pop();
    }

    void push( int val)
    {
        if ( val <= min() )
            mins.push( val);

        stackImpl::push( val);
    }
};

void printMin( stackWithMinImpl stack)
{
    cout << "Current min: " << stack.min() << "\n";
}

int main()
{
    stackWithMinImpl stack;

    printMin( stack);
    stack.push( 5); stack.push( 1); stack.push( 1); stack.push( 10);
    stack.print(); printMin( stack);
    stack.pop(); stack.pop();
    stack.print(); printMin( stack);
    stack.pop();
    stack.print(); printMin( stack);
    stack.push( 3); stack.push( 7); stack.push( 1); stack.push( -1);
    stack.print(); printMin( stack);

    return 0;
}
