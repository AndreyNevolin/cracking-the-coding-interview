/* Write code to remove duplicates from an unsorted linked list
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed? */
#include <iostream>

using namespace std;

class listNode
{
public:
    int val;
    listNode *next;

    listNode( int value) { val = value; next = 0; }
};

void printList( listNode *list)
{
    while ( list )
    {
        cout << list->val << " -> ";
        list = list->next;
    }

    cout << "null\n";
}

void removeDups( listNode *list)
{
    if ( !list )
        return;

    listNode *current = list->next;
    listNode *last = list;

    while ( current )
    {
        listNode *fixed = list;

        while ( fixed != current )
        {
            if ( fixed->val == current-> val )
                break;

            fixed = fixed->next;
        }

        if ( fixed == current )
        {
            last = current;
        } else
        {
            last->next = current->next;
            delete current;
        }

        current = last->next;
    }
}

int main()
{
    const int n = 10;
    const int arr[n] = { 1, 1, 2, 5, 7, 5, 1, 10, 10, 3};
    listNode *head = new listNode( arr[0]);
    listNode *current = head;

    for ( int i = 1; i < n; i++ )
    {
        current->next = new listNode( arr[i]);
        current = current->next;
    }

    cout << "Initial list: \n";
    printList( head);
    removeDups( head);
    cout << "Without dups: \n";
    printList( head);

    return 0;
}
