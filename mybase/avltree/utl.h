#ifndef UTL_H_
#define UTL_H_
/*
 *������һЩ���õĹ��ܣ����ڴ����
 */
#include <stdio.h>
#include <stdlib.h>

/*�����ڴ�*/
inline void *xalloc(int size)
{
    void *p;
    p = (void *)malloc(size);
    /*����ʧ��*/
    if(p == NULL)
    {
        printf("alloc error\n");
        exit(1);
    }
    return p;
}
/*�ڴ��ͷ�*/
#define xfree(p) free(p)

#endif