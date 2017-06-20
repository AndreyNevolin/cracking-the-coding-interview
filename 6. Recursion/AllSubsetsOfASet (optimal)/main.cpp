/* Write a method that returns all subsets of a set */
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/* — интервьюером необходимо обсудить следующие вещи:
   1.  аким образом представлено исходное множество?
   2. ¬ каком виде нужно вернуть подмножества?
   3. ¬озможно, что способ представлени€ множества допускает
      существование дубликатов. ≈сли это так, то спросить, нужно ли
      как-то учесть этот момент или можно считать, что дубликатов нет.
      ≈сли дубликаты могут быть, то что делать: проверить вход и упасть
      или сформировать подмножества уже с учетом дубликатов (т.е. не
      включать дубликаты в каждое результирующее подмножество более, чем один раз)?
   4. ¬ реальности сгенерировать все подмножества можно только дл€ коротких множеств.
      ѕоэтому надо спросить интервьюера, чего он хочет:
      a) простое рекурсивное решение (отличаетс€ тормознутостью + не подходит дл€
         очень больших множеств, т.к. может свалитьс€ из-за переполнени€ стека)
      б) решение на битовых векторах. ѕричем может быть два вида решени€:
            - битовый вектор умещаетс€ в стандартный целочисленный формат (это решение
              не годитс€ дл€ больших множеств)
            - большой битовый вектор на массиве из стандартных форматов (тут уже возникают
              проблемы с генерацией самих векторов)
      в) оптимальное решение (без рекурсии и битовых векторов)

      ƒумаетс€, что в любом случае надо выбирать оптимальное решение и реализовывать именно его

      ƒалее приводитс€ оптимальное решение
*/
vector< vector<int> > getSubsets( vector<int> &num_set)
{
    bool push = true;
    vector< vector<int> > result( 1 << num_set.size());
    vector<int> subset;
    int res_ind = 0, ind = 0;
    vector<int> num_to_ind( num_set.size());

    for ( int i = 0; i < num_set.size(); i++ )
        num_to_ind[num_set[i]] = i;

    while ( 1)
    {
        if ( ind == num_set.size() )
        {
            result[res_ind++] = subset;

            if ( subset.empty() )
                break;
            else
            {
                ind = num_to_ind[subset.back()] + 1;
                subset.pop_back();
            }
        } else
            subset.push_back( num_set[ind++]);
    }

    return result;
}

int main()
{
    const int n = 4;
    vector<int> num_set( n);

    cout << "Set: ";
    for ( int i = 0; i < n; i++ )
    {
        num_set[i] = i;
        cout << setw( 3) << num_set[i];
    }

    cout << "\nSubsets: \n";

    vector< vector<int> > subsets = getSubsets( num_set);

    for ( int i = 0; i < subsets.size(); i++ )
    {
        for ( int j = 0; j < subsets[i].size(); j++ )
            cout << setw( 3) << subsets[i][j];

        cout << "\n";
    }

    return 0;
}
