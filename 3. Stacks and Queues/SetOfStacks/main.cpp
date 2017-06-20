#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class StackElem
{
public:
    int value;
    StackElem *above, *below;

    StackElem( int elem)
    {
        value = elem;
        above = 0;
        below = 0;
    }
};

class Stack
{
private:
    StackElem *top, *bottom;
    int size;

public:
    Stack()
    {
        size = 0;
        top = 0;
        bottom = 0;
    }

    int getSize()
    {
        return size;
    }

    void push( int val)
    {
        StackElem *new_elem = new StackElem( val);

        new_elem->below = top;

        if ( top )
        {
            top->above = new_elem;
        }

        top = new_elem;

        if ( !bottom )
        {
            bottom = new_elem;
        }

        size++;
    }

    int pop()
    {
        if ( !top )
        {
            cout << "Can't pop from empty stack";

            exit( 1);
        }

        StackElem *to_delete = top;
        int val = to_delete->value;

        top = to_delete->below;

        if ( top )
        {
            top->above = 0;
        }

        delete to_delete;
        size--;

        return val;
    }

    int removeBottom()
    {
        int val = bottom->value;
        StackElem *to_delete = bottom;

        bottom = bottom->above;

        if ( bottom )
        {
            bottom->below = 0;
        } else
        {
            top = 0;
        }

        size--;
        delete to_delete;

        return val;
    }

    void print()
    {
        StackElem *current = top;

        while ( current )
        {
            cout << current->value << " ";
            current = current->below;
        }

        cout << "\n";
    }
};

class SetOfStacks
{
private:
    vector<Stack *> stack_set;
    int stack_capacity;

public:
    SetOfStacks( int stack_capacity)
    {
        if ( stack_capacity <= 0 )
        {
            cout << "Stack capacity should be positive";

            exit( 1);
        }

        this->stack_capacity = stack_capacity;
    }

    Stack *getLast()
    {
        if ( stack_set.size() == 0 )
        {
            return 0;
        }

        return stack_set[stack_set.size() - 1];
    }

    void push( int val)
    {
        Stack *current_stack = getLast();

        if ( !current_stack || current_stack->getSize() == stack_capacity )
        {
            current_stack = new Stack();
            stack_set.push_back( current_stack);
        }

        current_stack->push( val);
    }

    int pop()
    {
        Stack *current_stack = getLast();

        if ( !current_stack )
        {
            cout << "Can't pop from empty stack set";

            exit( 1);
        }

        int val = current_stack.pop();

        if ( current_stack.size() == 0 )
        {
            stack_set.pop_back();
            delete current_stack;
        }

        return val;
    }

    int popAt( int index)
    {
        if ( index > stack_set.size() - 1 || index < 0 )
        {
            cout << "Stack at index " << index << " doesn't exist";

            exit( 1);
        }

        if ( index == stack_set.size() - 1 )
        {
            return pop();
        }

        int val = stack_set[index].pop();
        int next_index = index++;

        while ( next_index < stack_set.size() )
        {
            int val = stack_set[next_index].removeBottom();

            stack_set[next_index - 1].push( val);
            next_index++;
        }

        Stack *last_stack = stack_set[stack_set.size() - 1];

        if ( last_stack.size() == 0 )
        {
            stack_set.pop_back();
            delete last_stack;
        }

        return val;
    }

    void print()
    {
        for ( int i = 0; i < stack_set.size(); i++ )
        {
            cout << "Stack " << i << ": ";
            stack_set[i].print();
            cout << "\n";
        }
    }
};

int main()
{
    SetOfStacks ss = new SetOfStacks( 0);

    return 0;
}
