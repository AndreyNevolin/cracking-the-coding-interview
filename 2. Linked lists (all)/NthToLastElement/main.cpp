/* Implement an algorithm to find the nth to last element of a singly linked list */
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

/* Необходимо уточнить у интервьюера терминологию:
   последний элемент - это нулевой элемент по отношению к самому себе
   или же первый? */
listNode *findNthToLast( listNode *list, int n)
{
    if ( !list || n < 1 )
        return 0;

    listNode *current = list;
    listNode *nth_to_current = list;

    for ( int i = 1; i < n; i++ )
        if ( current->next )
            current = current->next;
        else
            return 0;

    while ( current->next )
    {
        current = current->next;
        nth_to_current = nth_to_current->next;
    }

    return nth_to_current;
}

int main()
{
    const int n = 10;
    const int arr[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    listNode *head = new listNode( arr[0]);
    listNode *current = head;

    for ( int i = 1; i < n; i++ )
    {
        current->next = new listNode( arr[i]);
        current = current->next;
    }

    int num;

    printList( head);
    cout << "Enter n: ";
    cin >> num;
    listNode *nth_to_last = findNthToLast( head, num);

    if ( nth_to_last )
        cout << "Element value: " << nth_to_last->val;
    else
        cout << "Not possible";

    return 0;
}
