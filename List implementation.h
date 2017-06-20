#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>

using namespace std;

template<typename T> class linkedList;

template<typename T> class listNode
{
    T val;
    listNode *next;

public:
    listNode( T value) { val = value; next = 0; }

    listNode *insert( T value)
    {
        listNode *node = new listNode( value);

        node->next = next;
        next = node;

        return node;
    }

    void remove( listNode *prev)
    {
        if ( prev )
            prev->next = next;

        delete this;
    }

    listNode *getNext( )
    {
        return next;
    }

    T getVal( )
    {
        return val;
    }

    void print()
    {
        listNode<T> *node = this;

        while ( node )
        {
            cout << node->getVal() << " -> ";
            node = node->next;
        }

        cout << "null\n";
    }

    friend linkedList<T>;
};

template<typename T> class linkedList
{
    listNode<T> *head = 0;

public:
    linkedList() { head = new listNode<T>( 0); }

    listNode<T> *insertBeg( T val)
    {
        listNode<T> *new_node = new listNode<T>( val);

        new_node->next = head->next;
        head->next = new_node;

        return new_node;
    }

    listNode<T> *insertEnd( T val)
    {
        listNode<T> *node = head;
        listNode<T> *new_node = new listNode<T>( val);

        while ( node->next )
            node = node->next;

        node->next = new_node;
    }

    void removeBeg( )
    {
        if ( head->next )
        {
            listNode<T> *next_node = head->next->next;

            delete head->next;
            head->next = next_node;
        }
    }

    void removeEnd( )
    {
        listNode<T> *prev = head;
        listNode<T> *current = head->next;

        while ( current->next )
        {
            prev = current;
            current = current->next;
        }

        if ( current )
        {
            prev->next = 0;
            delete current;
        }
    }

    ~linkedList()
    {
        listNode<T> *node = head;

        while ( node )
        {
            listNode<T> *next_node = node->next;

            delete node;
            node = next_node;
        }
    }

    void print()
    {
        if ( !head->next )
        {
            cout << "Empty\n";

            return;
        }

        listNode<T> *node = head->next;

        while ( node )
        {
            cout << node->getVal() << " -> ";
            node = node->next;
        }

        cout << "null\n";
    }

    listNode<T> getFirst()
    {
        return head->next;
    }

    listNode<T> getHead()
    {
        return head;
    }
};

#endif // LIST_H_INCLUDED
