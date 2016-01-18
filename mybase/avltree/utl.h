#ifndef UTL_H_
#define UTL_H_
/*
 *整理了一些常用的功能，如内存管理
 */
#include <stdio.h>
#include <stdlib.h>

/*申请内存*/
inline void *xalloc(int size)
{
    void *p;
    p = (void *)malloc(size);
    /*申请失败*/
    if(p == NULL)
    {
        printf("alloc error\n");
        exit(1);
    }
    return p;
}
/*内存释放*/
#define xfree(p) free(p)

#endif