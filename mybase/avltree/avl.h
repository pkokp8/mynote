#ifndef AVL_H__
#define AVL_H__
/*
 *avl�����ݽṹ����ز���
 */
#include <stdio.h>
#include <stdlib.h>

struct AVLTree
{
    unsigned int nData;    /*�洢����*/
    struct AVLTree* pLeft;    /*ָ��������*/
    struct AVLTree* pRight;    /*ָ��������*/
    int nHeight;    /*����ƽ���*/
};

/*�������*/
struct AVLTree* insert_tree(unsigned int nData, struct AVLTree* pNode);

/*���Ҳ������ҵ�����1�����򣬷���0*/
int find_tree(unsigned int data, struct AVLTree* pRoot);

/*ɾ������,ɾ�����нڵ�*/
void delete_tree(struct AVLTree** ppRoot);

/*��ӡ����*/
void print_tree(struct AVLTree* pRoot);

#endif