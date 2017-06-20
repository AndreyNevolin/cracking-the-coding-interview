/* Write code to remove duplicates from an unsorted linked list
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed? */
#include <iostream>
#include <unordered_map>

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
    unordered_map<int,int> value_map;
    listNode *prev = 0;
    listNode *current = list;

    while ( current )
    {
        int val = current->val;

        if ( value_map.find( val) == value_map.end() )
        {
            value_map.insert( pair<int,int>( val, val));
            prev = current;
        } else
        {
            prev->next = current->next;
            delete current;
        }

        current = prev->next;
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
