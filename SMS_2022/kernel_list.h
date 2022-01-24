#pragma once  // 解决宏名引发的各种奇怪问题/Solve various strange problems caused by macro names
/*********************************************************************
 * 转载请注明来源/Reprint please indicate the source
 * @FileName kernellist.h
 * @Description 核心线性表/core linear table
 * @History
 * version      author      data       introduction and operations
 *  1.0         初见     2022-01-23             Create
 *  ***         ***      ****-**-**             *******
 */

#include "preconf.h"
 /*********************************************************************
  * @chujian(cn) 引入自定义头文件
  * @chujian(en) Import custom header files
  */

Status InitList(SqList* L)
{
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!(L->elem))
		exit(OVERFLOWED);
	L->length = 0;
	L->list_size = LIST_INIT_SIZE;
	return OK;
}
/*********************************************************************
 * @chujian(cn) 初始化
 * @chujian(en) Initialize
 */

Status DestroyList(SqList* L)
{
	free(L->elem);
	L->elem = NULL;
	L->length = 0;
	L->list_size = 0;
	return OK;
}
/*********************************************************************
 * @chujian(cn) 销毁
 * @chujian(en) Destroy
 */

Status ClearList(SqList* L)
{
	L->length = 0;
	return OK;
}
/*********************************************************************
 * @chujian(cn) 清空
 * @chujian(en) Reset
 */

Boolean ListEmpty(SqList* L)
{
	if (L->length == 0)
		return TRUE;
	else
		return FALSE;
}
/*********************************************************************
 * @chujian(cn) 判断空表
 * @chujian(en) Judge the empty table
 */

int ListLength(SqList* L)
{
	return L->length;
}
/*********************************************************************
 * @chujian(cn) 返回长度
 * @chujian(en) Retrun length of the table
 */

Status GetElem(SqList* L, int i, ElemType* e)
{
	if (i < 1 || i > ListLength(L))
		exit(ERROR);
	*e = *((L->elem) + i - 1);
	return OK;
}
/*********************************************************************
 * @chujian(cn) 获取第i个数据元素
 * @chujian(en) Get the i-th data element
 */

int LocateElem(SqList* L, ElemType* e, Status(*compare)(ElemType, ElemType))
{
	ElemType* p;
	int i = 1;
	p = L->elem;
	while (i <= (L->length) && !(*compare)(*e, *(p++)))
		++i;
	if (i <= (L->length))
		return i;
	else
		return 0;
}
/*********************************************************************
 * @chujian(cn) 返回满足特定关系的数据元素位序
 * @chujian(en) Returns the bit order of data elements that satisfy a specified relationship
 */

Status SearchElem(SqList* L, int cur_e, ElemType* e, int mode_manner)
{
	ElemType* r = L->elem;
	int i = 1;
	while (i <= L->length && r->num != cur_e)
	{
		i++;
		r++;
	}
	if (i > L->length)
		return INFEASIBLE;
	switch (mode_manner)
	{
	case -1:
		*e = *(--r);
		return OK;
	case 0:
		*e = *r;
		return OK;
	case 1:
		*e = *(++r);
		return OK;
	default:
		return ERROR;
	}
	return OK;
}
/*********************************************************************
 * @chujian(cn) 学号搜索引擎
 * @chujian(en) Student ID Search Engine
 */

Status ListInsert(SqList* L, int i, ElemType e)
{
	if (i < 1 || i >(L->length) + 1)
		return ERROR;
	if (L->length >= L->list_size)
	{
		ElemType* new_base = (ElemType*)realloc(L->elem, (L->length + LIST_INCREMENT) * sizeof(ElemType));
		if (!new_base)
			exit(OVERFLOWED);
		L->elem = new_base;
		L->list_size += LIST_INCREMENT;
	}
	ElemType* q = &(L->elem[i - 1]);
	ElemType* p = &(L->elem[(L->length) - 1]);
	for (p = &(L->elem[(L->length) - 1]); p >= q; --p) /* 插入位置及之后的元素右移 */
		*(p + 1) = *p;
	*q = e;
	++(L->length);
	return OK;
}
/*********************************************************************
 * @chujian(cn) 插入
 * @chujian(en) insert
 */

Status ListDelete(SqList* L, int i, ElemType* e)
{
	if (i < 1 || i > L->length)
		return ERROR;
	ElemType* p = L->elem + i - 1;
	*e = *p;
	ElemType* q = L->elem + L->length - 1;
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	--(L->length);
	return OK;
}
/*********************************************************************
 * @chujian(cn) 删除
 * @chujian(en) delete
 */

Status ListTraverse(SqList* L, void(*visit)(ElemType*))
{
	int i;
	ElemType* p = L->elem;
	for (i = 1; i <= L->length; ++i)
		visit(p);
	return OK;
}
/*********************************************************************
 * @chujian(cn) 遍历所有数据进行同等操作
 * @chujian(en) Iterate over all data for the same operation
 */

Status SwapElem(ElemType* x, ElemType* y)
{
	ElemType temp;
	//ElemType* z = (ElemType*)malloc(sizeof(ElemType*)+1);
	/*if (z == NULL)
		return OVERFLOWED;*/
	temp = *x;
	*x = *y;
	*y = temp;
	return OK;
}
/*********************************************************************
 * @chujian(cn) 交换两个数据元素的位置
 * @chujian(en) Swap the positions of two data elements
 */

Status ListSort(SqList* L, int sort_manner, char key)
{
	int i, j;
	Boolean flag = TRUE;
	for (i = 0; i < (L->length) - 1 && flag == TRUE; i++)
	{
		flag = FALSE;
		for (j = 0; j < (L->length) - i - 1; j++)
		{
			if (sort_manner <= 0)
			{
				switch (key)
				{
				case 'a':
					if ((L->elem)[j].average_score < (L->elem)[j + 1].average_score)
					{
						SwapElem(&((L->elem)[j]), &((L->elem)[j + 1]));
						flag = TRUE;
					}
					break;
				case 's':
					if ((L->elem)[j].sum_score < (L->elem)[j + 1].sum_score)
					{
						SwapElem(&((L->elem)[j]), &((L->elem)[j + 1]));
						flag = TRUE;
					}
					break;
				case 'l':
					if ((L->elem)[j].score_literature < (L->elem)[j + 1].score_literature)
					{
						SwapElem(&((L->elem)[j]), &((L->elem)[j + 1]));
						flag = TRUE;
					}
					break;
				case 'm':
					if ((L->elem)[j].score_math < (L->elem)[j + 1].score_math)
					{
						SwapElem(&((L->elem)[j]), &((L->elem)[j + 1]));
						flag = TRUE;
					}
					break;
				case 'e':
					if ((L->elem)[j].score_english < (L->elem)[j + 1].score_english)
					{
						SwapElem(&((L->elem)[j]), &((L->elem)[j + 1]));
						flag = TRUE;
					}
					break;
				case 'n':
					if ((L->elem)[j].num < (L->elem)[j + 1].num)
					{
						SwapElem(&((L->elem)[j]), &((L->elem)[j + 1]));
						flag = TRUE;
					}
					break;
				default:
					printf("该主键不支持排序\n");
					return ERROR;
				}
			}
			else
			{
				switch (key)
				{
				case 'a':
					if ((L->elem)[j].average_score > (L->elem)[j + 1].average_score)
					{
						SwapElem(&((L->elem)[j]), &((L->elem)[j + 1]));
						flag = TRUE;
					}
					break;
				case 's':
					if ((L->elem)[j].sum_score > (L->elem)[j + 1].sum_score)
					{
						SwapElem(&((L->elem)[j]), &((L->elem)[j + 1]));
						flag = TRUE;
					}
					break;
				case 'l':
					if ((L->elem)[j].score_literature > (L->elem)[j + 1].score_literature)
					{
						SwapElem(&((L->elem)[j]), &((L->elem)[j + 1]));
						flag = TRUE;
					}
					break;
				case 'm':
					if ((L->elem)[j].score_math > (L->elem)[j + 1].score_math)
					{
						SwapElem(&((L->elem)[j]), &((L->elem)[j + 1]));
						flag = TRUE;
					}
					break;
				case 'e':
					if ((L->elem)[j].score_english > (L->elem)[j + 1].score_english)
					{
						SwapElem(&((L->elem)[j]), &((L->elem)[j + 1]));
						flag = TRUE;
					}
					break;
				case 'n':
					if ((L->elem)[j].num > (L->elem)[j + 1].num)
					{
						SwapElem(&((L->elem)[j]), &((L->elem)[j + 1]));
						flag = TRUE;
					}
					break;
				default:
					printf("该主键不支持排序\n");
					return ERROR;
				}
			}
		}
	}
	return OK;
}
/*********************************************************************
 * @chujian(cn) 冒泡排序(看起来比较繁琐，因为多个不同的排序项)
 * @chujian(en) Bubble Sor(Seems cumbersome here because of multiple different sort items)
 */
