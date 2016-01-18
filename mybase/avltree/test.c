
#include "avl.h"

int main()
{
    int i,j;
    struct AVLTree* pRoot = NULL;

    srand((unsigned int)time(NULL));
    
    for (i = 0; i < 10; ++i)
    {
		scanf("%d",&j);
        // printf("%d\n", j);
        pRoot = insert_tree(j, pRoot);
    }

    print_tree(pRoot);

    delete_tree(&pRoot);

    return 0;
}