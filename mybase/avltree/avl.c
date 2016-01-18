#include "avl.h"

#include "utl.h"

static int Max(int a, int b);
static int Height(struct AVLTree* pNode);

/*��ת����*/
static struct AVLTree* SingleRotateWithLeft(struct AVLTree* pNode);
static struct AVLTree* SingleRotateWithRight(struct AVLTree* pNode);
static struct AVLTree* DoubleRotateWithLeft(struct AVLTree* pNode);
static struct AVLTree* DoubleRotateWithRight(struct AVLTree* pNode);

struct AVLTree* insert_tree(unsigned int nData, struct AVLTree* pNode)
{
    if (NULL == pNode)
    {
        pNode = (struct AVLTree*)xalloc(sizeof(struct AVLTree));
        pNode->nData = nData;
        pNode->nHeight = 0;
        pNode->pLeft = pNode->pRight = NULL;
    }
    else if (nData < pNode->nData)    /*���뵽��������*/
    {
        pNode->pLeft = insert_tree(nData, pNode->pLeft);
        if (Height(pNode->pLeft) - Height(pNode->pRight) == 2)    /*AVL����ƽ��*/
        {
            if (nData < pNode->pLeft->nData)
            {
                /*���뵽�����������, ������ת*/
                pNode = SingleRotateWithLeft(pNode);
            }
            else
            {
                /*���뵽���������ұ�, ��˫��ת*/
                pNode = DoubleRotateWithLeft(pNode);
            }
        }
    }
    else if (nData > pNode->nData)    /*���뵽��������*/
    {
        pNode->pRight = insert_tree(nData, pNode->pRight);
        if (Height(pNode->pRight) - Height(pNode->pLeft) == 2)    /*AVL����ƽ��*/
        {
            if (nData > pNode->pRight->nData)
            {
                /*���뵽���������ұ�, ������ת*/
                pNode = SingleRotateWithRight(pNode);
            }
            else
            {
                /*���뵽�����������, ��˫��ת*/
                pNode = DoubleRotateWithRight(pNode);
            }
        }
    }

    pNode->nHeight = Max(Height(pNode->pLeft), Height(pNode->pRight)) + 1;

    return pNode;
}


/*ɾ����*/
void delete_tree(struct AVLTree** ppRoot)
{
    if (NULL == ppRoot || NULL == *ppRoot)
        return;

    delete_tree(&((*ppRoot)->pLeft));
    delete_tree(&((*ppRoot)->pRight));
    xfree(*ppRoot);
    *ppRoot = NULL;
}

/*���������ӡ�������н��, ��Ϊ���� < ����� < �ҽ��, ��˴�ӡ�������ݵĴ�С�ǵ�����*/
void print_tree(struct AVLTree* pRoot)
{
    if (NULL == pRoot)
        return;

    static int n = 0;


    print_tree(pRoot->pLeft);
    printf("[%d]nData = %u\n", ++n, pRoot->nData);
    print_tree(pRoot->pRight);
}

/*
 *���Ҳ������ҵ�����1�����򣬷���0
 *data�Ǵ����ҵ�����
 *pRoot:avl����ָ��
 */
int find_tree(unsigned int data, struct AVLTree* pRoot)
{
    static int k=1;    /*���Ҵ���*/
    if (NULL == pRoot)
    {
        printf("not find %d times\n", k);
        return 0;
    }

    if(data == pRoot->nData)
    {
        printf("find:%d times\n", k);
        return 1;
    }
    else if(data < pRoot->nData)
    {
        ++k;
        return find_tree(data, pRoot->pLeft);
    }
    else if(data > pRoot->nData)
    {
        ++k;
        return find_tree(data, pRoot->pRight);
    }
}

static int Max(int a, int b)
{
    return (a > b ? a : b);
}

/*���ؽڵ��ƽ���*/
static int Height(struct AVLTree* pNode)
{
    if (NULL == pNode)
        return -1;

    return pNode->nHeight;
}

/********************************************************************
      pNode pNode->pLeft
      / \
  pNode->pLeft ==> pNode
      \     /
  pNode->pLeft->pRight pNode->pLeft->pRight
 *********************************************************************/
static struct AVLTree* SingleRotateWithLeft(struct AVLTree* pNode)
{
    struct AVLTree* pNode1;

    pNode1 = pNode->pLeft;
    pNode->pLeft = pNode1->pRight;
    pNode1->pRight = pNode;

    /*����λ�ñ���, Ҫ���½��ĸ߶�ֵ*/
    pNode->nHeight = Max(Height(pNode->pLeft), Height(pNode->pRight)) + 1;
    pNode1->nHeight = Max(Height(pNode1->pLeft), pNode->nHeight) + 1;

    return pNode1;
}

/********************************************************************
  pNode pNode->pRight
  \ /
  pNode->pRight ==> pNode
  / \
  pNode->pRight->pLeft pNode->pRight->pLeft
 *********************************************************************/
static struct AVLTree* SingleRotateWithRight(struct AVLTree* pNode)
{
    struct AVLTree* pNode1;

    pNode1 = pNode->pRight;
    pNode->pRight = pNode1->pLeft;
    pNode1->pLeft = pNode;

    /*����λ�ñ���, Ҫ���½��ĸ߶�ֵ*/
    pNode->nHeight = Max(Height(pNode->pLeft), Height(pNode->pRight)) + 1;
    pNode1->nHeight = Max(Height(pNode1->pRight), pNode->nHeight) + 1;

    return pNode1;
}

static struct AVLTree* DoubleRotateWithLeft(struct AVLTree* pNode)
{
    pNode->pLeft = SingleRotateWithRight(pNode->pLeft);

    return SingleRotateWithLeft(pNode);
}

static struct AVLTree* DoubleRotateWithRight(struct AVLTree* pNode)
{
    pNode->pRight = SingleRotateWithLeft(pNode->pRight);

    return SingleRotateWithRight(pNode);
}