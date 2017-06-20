/* Implement an algorithm to delete a node in the middle of a single linked list, given
only access to that node
EXAMPLE
Input: the node �c� from the linked list a->b->c->d->e
Result: nothing is returned, but the new linked list looks like a->b->d->e */
#include <iostream>

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
    while ( list )
    {
        cout << list->val << " -> ";
        list = list->next;
    }

    cout << "null\n";
}

/* ������ ������, ������ �� ����� ����������. ������� ������� ������������ ������,
   ���� ������ ������ �� ����, ����������. �� ��� ����� ����������� ������� �����������.
   ������ ����� ������� �� ������ ��������, ���������� � ��������� ��������. ������ ���
   ������� � ��������� ����.
   ������� �� �������� � ���� �������:
   1. ��� ���������� �������� ������
   2. ���� ���-�� ���� ��������� ��������� �� ���������� �������� ������ (��� ��� ���
      ��� ������, ����� ��������� ������� ������ ������� ������, � �� ��� ��������) */
bool removeNode( listNode *node)
{
    if ( !node || !node->next )
        return false;

    listNode *next_node = node->next;

    node->val = next_node->val;
    node->next = next_node->next;
    delete next_node;

    return true;
}

int main()
{
    const int n = 10;
    const char arr[n] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    listNode *head = new listNode( arr[0]);
    listNode *current = head;

    for ( int i = 1; i < n; i++ )
    {
        current->next = new listNode( arr[i]);
        current = current->next;
    }

    int num = 0;
    char c = 0;

    printList( head);
    cout << "Which to delete (enter a letter)?\n";
    cin >> c;

    listNode *node = head;

    while ( node )
        if ( node->val == c )
            break;
        else
            node = node->next;

    if ( removeNode( node) )
    {
        cout << "After deletion: \n";
        printList( head);
    } else
        cout << "Incorrect input or cannot delete";

    return 0;
}
