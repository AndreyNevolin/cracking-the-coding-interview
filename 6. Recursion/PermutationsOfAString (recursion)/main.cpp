/* Write a method to compute all permutations of a string */
#include <iostream>
#include <vector>

using namespace std;

/* Основной момент - работа с повторяющимися символами.
   Перестановки одинаковых символов между собой не дают новых строк.

   Необходимо обсудить с интервьюером канву решения. Самое простое решение -
   рекурсивное. Но оно не является оптимальным из-за тормознутости и возможности
   переполнения стека. Однако нужно учесть, что n! очень быстро растет, поэтому
   на практике глубина рекурсии не должна быть очень большой.
   Тем не менее, для строки вида "аааааа..." (очень много одинаковых символов)
   существует всего одна перестановка, рекурсивная работа с которой может переполнить
   стек (если строка ну ооочень длинная). Это является аргументом против рекурсивного
   решения.

   Ниже приводится рекурсивное решение */
vector<string> getPermutations( string str)
{
    if ( !str.size() )
        return vector<string>( 1);

    vector<string> temp = getPermutations( str.substr( 1));
    vector<string> result;

    result.reserve( temp.size() * temp[0].size());
}

int main()
{
    string str;

    cout << "Enter a string: ";
    getline( cin, str);

    vector<string> permutations = getPermutations( str);

    for ( int i = 0; i < permutations.size(); i++ )
        cout << permutations[i] << "\n";

    return 0;
}
