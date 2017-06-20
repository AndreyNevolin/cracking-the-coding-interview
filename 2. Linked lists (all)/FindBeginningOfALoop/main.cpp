/* Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
DEFINITION
Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node,
so as to make a loop in the linked list.
EXAMPLE
input: A -> B -> C -> D -> E -> C [the same C as earlier]
output: C */
#include <iostream>
#include <string.h>

using namespace std;

class listNode
{
public:
    char val;
    listNode *next;

    listNode( int value) { val = value; next = 0; }
};

void printList( listNode *list)
{
    bool *symb = new bool[256];

    memset( symb, false, sizeof( bool) * 256);

    while ( list )
    {
        cout << list->val << " -> ";

        if ( !symb[list->val] )
            symb[list->val] = true;
        else
            break;

        list = list->next;
    }

    cout << "\n";
}

listNode *findLoopEnter( listNode *list)
{
    listNode *first = list, *second = list;

    while ( second && second->next )
    {
        first = first->next;
        second = second->next->next;

        if ( first == second )
            break;
    }

    if ( !second || !second->next )
        return 0;

    first = list;

    while ( first != second )
    {
        first = first->next;
        second = second->next;
    }

    return first;
}

int main()
{
    string str = "ABCDEFGHIJKLMNF";
    listNode *list = new listNode( str[0]);
    listNode *current = list;
    listNode *loop_enter = 0;

    for ( int i = 1; i < str.size() - 1; i++ )
    {
        current->next = new listNode( str[i]);
        current = current->next;

        if ( str[i] == str[str.size() - 1] )
            loop_enter = current;
    }

    if ( str[0] == str[str.size() - 1] )
        loop_enter = list;

    if ( loop_enter )
        current->next = loop_enter;

    printList( list);
    loop_enter = findLoopEnter( list);

    if ( !loop_enter )
        cout << "No loop found";
    else
        cout << "Loop enter: " << loop_enter->val;

    return 0;
}
