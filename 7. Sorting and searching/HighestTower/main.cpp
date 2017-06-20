/* A circus is designing a tower routine consisting of people standing atop
   one another’s shoulders. For practical and aesthetic reasons, each person
   must be both shorter and lighter than the person below him or her. Given
   the heights and weights of each person in the circus, write a method to
   compute the largest possible number of people in such a tower.
   EXAMPLE:
   Input (ht, wt): (65, 100) (70, 150) (56, 90) (75, 190) (60, 95) (68, 110)
   Output: The longest tower is length 6 and includes from top to bottom:
   (56, 90) (60,95) (65,100) (68,110) (70,150) (75,190) */
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class person
{
public:
    int weight;
    int height;

    person( ) { height = 0; weight = 0;}
    person( int h, int w) { height = h; weight = w;}
};

/* Сортируем по убыванию роста/веса */
bool cmp( person a, person b)
{
    if ( a.height > b.height )
        return true;
    else if ( a.height == b.height && a.weight > b.weight )
        return true;
    else
        return false;
}

/*
    Вопрос интервьюеру:
    1) Люди должны быть строго ниже и легче тех, кто под ними, или допускается
       равенство веса или роста (или того и другого)?

    Решение:
    1) отсортировать людей сначала по росту, а затем людей с одинаковым ростом
       переставить в соответствии с их весом
    2) посчитать вектор maxTower[i], i-ый элемент которого равен максимальной высоте
       башни, на вершине которой стоит i-ый человек.
       Считаем по индукции: maxTower[i+1] = max( 1 + maxTower[j]), где
       максимум берется по всем j таким, что j < i+1 и i+1-ый человек может стоять на
       плечах человека j
    3) Максимальная высота башни будет равна max( maxTower[i]) по всем i. Обозначим
       соответствующий индекс maxInd
    4) Остается теперь построить эту башню по вектору maxTower. Для этого идем по вектору
       maxTower вниз, начиная с индекса maxInd. Если для какого-то индекса i видим, что
       maxTower[i] == maxTower[maxInd] - 1 и человек maxInd может стоять на плечах человека
       i, то добавляем человека i в башню, устанавливаем maxInd = i и продолжаем спуск вниз.

    Описанное решение имеет квадратичную сложность.

    Решение описано подробно, т.к. в книге какая-то ерунда написана относительно этой задачи */
vector<person> getHighestTower( vector<person> people)
{
    if ( !people.size() )
        return vector<person> ( 0);

    sort( people.begin(), people.end(), cmp);

    vector<int> maxTower( people.size());

    for ( int i = 0; i < people.size(); i++ )
    {
        maxTower[i] = 1;

        for ( int j = 0; j < i; j++ )
            if ( maxTower[j] + 1 > maxTower[i]
                 && people[j].height > people[i].height
                 && people[j].weight > people[i]. weight )
                    maxTower[i] = maxTower[j] + 1;
    }

    int maxHeight = 0, maxInd = -1;

    for ( int i = 0; i < maxTower.size(); i++ )
        if ( maxTower[i] > maxHeight )
        {
            maxHeight = maxTower[i];
            maxInd = i;
        }

    vector<person> result( maxHeight);
    int ind = maxInd - 1;

    result[maxHeight - 1] = people[maxInd];

    while ( maxTower[maxInd] > 1 )
    {
        if ( maxTower[ind] == maxTower[maxInd] - 1
             && people[ind].height > people[maxInd].height
             && people[ind].weight > people[maxInd].weight )
        {
            maxInd = ind;
            result[maxTower[ind] - 1] = people[ind];
        }

        ind--;
    }

    return result;
}

int main()
{
    int height[] = { 65,  70,  56,  75,  60,  68};
    int weight[] = {100, 150,  90,  190, 95, 110};

    assert( sizeof( height) == sizeof( weight));

    vector<person> people( sizeof( height) / sizeof( int));

    for ( int i = 0; i < people.size(); i++ )
        people[i] = person( height[i], weight[i]);

    vector<person> tower = getHighestTower( people);

    cout << "Highest tower: ";

    for ( int i = 0; i < tower.size(); i++ )
        cout << "(" << tower[i].height << ", " << tower[i].weight << ") ";

    return 0;
}
