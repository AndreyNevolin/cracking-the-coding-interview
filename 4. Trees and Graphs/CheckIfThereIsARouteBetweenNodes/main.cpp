/* Given a directed graph, design an algorithm to find out whether
   there is a route between two nodes */
#include <iostream>
#include <list>
#include <string.h>

using namespace std;

class graphNode
{
public:
    list<graphNode *> neighbours;
    bool visited;

    graphNode() { visited = false; }
};

const int n = 10;

void constructGraph( char arr[][n], int s_num, int f_num,
                     graphNode **start, graphNode **finish)
{
    graphNode *nodes[n];

    memset( nodes, 0, sizeof( graphNode *) * n);

    for ( int i = 0; i < n; i++ )
    {
        graphNode *node = nodes[i];

        if ( !node )
        {
            node = new graphNode;
            nodes[i] = node;
        }

        for ( int j = 0; j < n; j++ )
        {
            if ( !nodes[j] )
                nodes[j] = new graphNode;

            if ( arr[i][j] )
                (node->neighbours).push_front( nodes[j]);
        }

        if ( i == s_num )
            *start = node;

        if ( i == f_num )
            *finish = node;
    }
}

/* Спросить интервьюера о том, каким образом представлен граф.
   В данном решении граф представлен объектами */
bool checkPath( graphNode *start, graphNode *finish)
{
    list<graphNode *> worklist;

    worklist.push_front( start);
    start->visited = true;

    while ( !worklist.empty() )
    {
        graphNode *node = worklist.front();

        worklist.pop_front();

        for ( auto it = (node->neighbours).begin();
              it != (node->neighbours).end();
              it++ )
        {
            if ( *it == finish )
                return true;

            if ( !((*it)->visited) )
            {
                worklist.push_front( *it);
                (*it)->visited = true;
            }
        }
    }

    return false;
}

int main()
{
    char arr_yes[n][n] = { {0,1,1,0,0,0,0,0,0,0},
                           {0,1,0,1,0,0,0,0,0,0},
                           {0,0,0,1,0,1,0,0,0,0},
                           {0,0,0,0,0,0,1,0,0,0},
                           {0,0,1,0,0,0,0,0,0,0},
                           {0,0,0,0,1,0,0,1,0,0},
                           {0,0,0,0,0,0,0,1,1,0},
                           {0,0,0,0,0,0,0,0,1,0},
                           {0,0,0,0,0,0,0,0,0,1},
                           {0,0,0,0,0,0,0,0,0,0} };

    char arr_no[n][n] = { {0,1,1,0,0,0,0,0,0,0},
                          {0,1,0,1,0,0,0,0,0,0},
                          {0,0,0,1,0,1,0,0,0,0},
                          {0,0,0,0,0,0,1,0,0,0},
                          {0,0,1,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,1,0,0},
                          {0,0,0,0,0,0,0,1,1,0},
                          {0,0,0,0,0,0,0,0,1,0},
                          {0,0,0,0,0,0,0,0,0,1},
                          {0,0,0,0,0,0,0,0,0,0} };
    graphNode *start, *finish;

    constructGraph( arr_yes, 0, 9, &start, &finish);

    if ( checkPath( start, finish) )
        cout << "Path exists\n";
    else
        cout << "Path doesn't exist\n";

    constructGraph( arr_no, 0, 4, &start, &finish);

    if ( checkPath( start, finish) )
        cout << "Path exists\n";
    else
        cout << "Path doesn't exist\n";

    return 0;
}
