/* Implement a function to check if a tree is balanced For the purposes of this question,
a balanced tree is defined to be a tree such that no two leaf nodes differ in distance
from the root by more than one */
#include <iostream>

using namespace std;

class treeNode
{
public:
    int val;
    treeNode *left;
    treeNode *right;

    treeNode( int value, treeNode *l, treeNode *r)
    { val = value; left = l; right = r; }

};

treeNode *buildTree( int arr[], int n, int size)
{
    if ( !arr[n - 1] || n - 1 >= size - 1 )
        return 0;

    return new treeNode( n, buildTree( arr, n * 2, size),
                         buildTree( arr, n * 2 + 1, size));
}

int maxDepth( treeNode *tree)
{
    if ( !tree )
        return 0;

    return 1 + max( maxDepth( tree->left), maxDepth( tree->right));
}

int minDepth( treeNode *tree)
{
    if ( !tree )
        return 0;

    return 1 + min( minDepth( tree->left), minDepth( tree->right));
}

bool isBalanced( treeNode *tree)
{
    return maxDepth( tree) - minDepth( tree) <= 1;
}

int main()
{
    /* 1 - если вершина с соответствующим номером присутствует в дереве, 0 - если нет.
       Вершины пронумерованы по уровням слева направо */
    int descA[15] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0};
    treeNode *treeA = buildTree( descA, 1, 15);
    int descB[15] = {1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0};
    treeNode *treeB = buildTree( descB, 1, 15);

    cout << "Tree A is ";

    if ( isBalanced( treeA) )
        cout << "balanced\n";
    else
        cout << "not balanced\n";

    cout << "Tree B is ";

    if ( isBalanced( treeB) )
        cout << "balanced\n";
    else
        cout << "not balanced\n";

    return 0;
}
