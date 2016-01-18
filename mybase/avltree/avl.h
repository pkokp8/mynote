#ifndef AVL_H__
#define AVL_H__
/*
 *avl树数据结构及相关操作
 */
#include <stdio.h>
#include <stdlib.h>

struct AVLTree
{
    unsigned int nData;    /*存储数据*/
    struct AVLTree* pLeft;    /*指向左子树*/
    struct AVLTree* pRight;    /*指向右子树*/
    int nHeight;    /*树的平衡度*/
};

/*插入操作*/
struct AVLTree* insert_tree(unsigned int nData, struct AVLTree* pNode);

/*查找操作，找到返回1，否则，返回0*/
int find_tree(unsigned int data, struct AVLTree* pRoot);

/*删除操作,删除所有节点*/
void delete_tree(struct AVLTree** ppRoot);

/*打印操作*/
void print_tree(struct AVLTree* pRoot);

#endif