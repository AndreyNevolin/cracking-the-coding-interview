/* Given a sorted array of strings which is interspersed with empty strings,
   write a method to find the location of a given string.
   Example: find УballФ in [УatФ, УФ, УФ, УФ, УballФ, УФ, УФ, УcarФ, УФ, УФ, УdadФ, УФ, УФ] will return 4
   Example: find УballcarФ in [УatФ, УФ, УФ, УФ, УФ, УballФ, УcarФ, УФ, УФ, УdadФ, УФ, УФ] will return -1 */
#include <iostream>
#include <vector>

using namespace std;

/* ¬опросы интервьюеру:
   1. что возвращать, если пользователь запросил
      поиск пустой строки? ¬ решении ниже возвращаетс€ индекс первого
      вхождени€ пустой строки в массиве (если такое вхождение имеетс€)
   2. —тандартный вопрос дл€ любого поиска: какой индекс возвращать, если
      в массиве есть несколько элементов, равных искомому? */
int searchArr( const vector<string> &arr, string str)
{
    int left = 0, right = arr.size() - 1;

    if ( str == "" )
    {
        for ( int i = 0; i < arr.size(); i++ )
            if ( arr[i] == "" )
                return i;

        return -1;
    }

    while ( left < arr.size() && arr[left] == "" )
        left++;

    /* –анний выход, чтобы не делать лишний проход по массиву */
    if ( left == arr.size() )
        return -1;

    while ( right >= 0 && arr[right] == "" )
        right--;

    /* Ќестандартное условие выхода из бинарного поиска. —тандартным
       €вл€етс€ left < right. Ќеобходимо также обратить внимание на
       пачку условий после цикла.
       ¬се это сделано потому, что в данном решении сужение границ происходит
       не так, как в стандатной версии бинарного поиска. ¬ стандартной версии
       диапазон гарантированно сужаетс€ на каждом шагу, т.к. к "середине" может
       прибавл€тьс€ единица. ¬ коде ниже к "середине" ничего не
       добавл€етс€ из-за того, что границы поддерживаютс€ в таком состо€нии, что
       всегда указывают на непустые строки */
    while ( right - left > 1 )
    {
        /* Ќадо сказать интервьюеру о том, что нельза делать
           mid = (left + right) / 2, т.к. это может вызвать overflow */
        int mid = left + (right - left) / 2;
        int temp = mid;

        if ( arr[mid] == str )
            return mid;

        while ( temp > left && arr[temp] == "" )
            temp--;

        if ( str <= arr[temp] )
        {
            right = temp;
        } else
        {
            temp = mid;

            while ( temp < right && arr[temp] == "" )
                temp++;

            left = temp;
        }
    }

    if ( arr[left] == str )
        return left;
    else if ( arr[right] == str )
        return right;
    else
        return -1;
}

int main()
{
    const char *arr[] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    /* ћассив здесь не может быть пустым. ѕоэтому и вектор пустым не будет.
       ≈сли нужно протестировать поиск на пустом векторе, нужно стереть инициализирующее
       выражение */
    const vector<string> vect( arr, arr + sizeof( arr) / sizeof( arr[0]));

    cout << "Array to search in:\n";

    for ( int i = 0; i < vect.size(); i++ )
        cout << "\"" << vect[i] << "\"" << " ";

    cout << "\nIndex of ball: " << searchArr( vect, "ball");
    cout << "\nIndex of ballcar: " << searchArr( vect, "ballcar");

    return 0;
}
