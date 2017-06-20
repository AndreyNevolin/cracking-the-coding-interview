/* You have two numbers represented by a linked list, where each node contains a single digit.
   The digits are stored in reverse order, such that the 1’s digit is at the head of the list.
   Write a function that adds the two numbers and returns the sum as a linked list.
EXAMPLE
Input: (3 -> 1 -> 5) + (5 -> 9 -> 2)
Output: 8 -> 0 -> 8 */
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
        cout << char_traits<char>::to_int_type( list->val) << " -> ";
        list = list->next;
    }

    cout << "null\n";
}

listNode *strToList( string str)
{
    listNode *list = new listNode( str[str.size() - 1] - '0');
    listNode *current = list;

    for ( int i = str.size() - 2; i >= 0; i-- )
    {
        current->next = new listNode( str[i] - '0');
        current = current->next;
    }

    return list;
}

listNode *summ( listNode *first, listNode *second)
{
    if ( !first || !second )
        return 0;

    listNode *firstDigit = first, *secondDigit = second;
    int digitSumm = firstDigit->val + secondDigit->val;
    listNode *result = new listNode( digitSumm % 10);
    int div = digitSumm / 10;
    listNode *current = result;

    firstDigit = firstDigit->next;
    secondDigit = secondDigit->next;

    while ( firstDigit || secondDigit )
    {
        digitSumm = 0;

        if ( firstDigit )
        {
            digitSumm += firstDigit->val;
            firstDigit = firstDigit->next;
        }

        if ( secondDigit )
        {
            digitSumm += secondDigit->val;
            secondDigit = secondDigit->next;
        }

        digitSumm += div;
        current->next = new listNode( digitSumm % 10);
        current = current->next;
        div = digitSumm / 10;
    }

    if ( div )
        current->next = new listNode( 1);

    return result;
}

int main()
{
    const string first = "513", second = "295";
    listNode *first_num = strToList( first);
    listNode *second_num = strToList( second);

    printList( first_num);
    printList( second_num);

    listNode *result = summ( first_num, second_num);
    cout << "Summ: ";
    printList( result);

    return 0;
}
