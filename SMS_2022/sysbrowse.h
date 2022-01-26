#pragma once
/*********************************************************************
 * 转载请注明来源/Reprint please indicate the source
 * @FileName sysbrowse.h
 * @Description 学生信息浏览系统/Student Information Browsing System
 * @History
 * version      author      data       introduction and operations
 *  1.0         初见     2022-01-22             Create
 *  ***         ***      ****-**-**             *******
 */

#include "kernel_list.h"
 /*********************************************************************
  * @chujian(cn) 引入自定义头文件
  * @chujian(en) Import custom header files
  */

Status browseMenu(void)
{
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                            【副】信 息 浏 览 系 统                            ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃请选择操作:                                                                    ┃\n");
	printf("┃                             1 > 查看所有学生信息                              ┃\n");
	printf("┃                             2 > 根据学号搜索学生                              ┃\n");
	printf("┃                             3 > 排序学生信息                                  ┃\n");
	printf("┃                             4 > 名次查询学生                                  ┃\n");
	printf("┃                             5 > 一键统计所有信息                              ┃\n");
	printf("┃                             0 > 返回主系统                                    ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\nINPUT:");
	return OK;
}
/*********************************************************************
 * @chujian(cn) 信息浏览系统
 * @chujian(en) Information browsing system
 */

Status putAllList(SqList* L)
{
	int i = 0;
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃  姓名        学号        性别        年龄        语文        数学        英语        平均分        总分   ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	while (i < L->length)
	{
		printf("┃  %-9s%-16d%-12s%-11d%-12.2f%-12.2f%-12.2f%-13.2f%-8.2f┃\n", (L->elem[i]).name, (L->elem[i]).num, (L->elem[i]).sex, (L->elem[i]).age, (L->elem[i]).score_literature, (L->elem[i]).score_math, (L->elem[i]).score_english, (L->elem[i]).average_score, (L->elem[i]).sum_score);
		++i;
	}
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	return OK;
}
/*********************************************************************
 * @chujian(cn) 打印表内全部信息
 * @chujian(en) Print all the information in the form
 */

Status putSingleList(ElemType* e)
{
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃  姓名        学号        性别        年龄        语文        数学        英语        平均分        总分   ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃  %-9s%-16d%-12s%-11d%-12.2f%-12.2f%-12.2f%-13.2f%-8.2f┃\n", e->name, e->num, e->sex, e->age, e->score_literature, e->score_math, e->score_english, e->average_score, e->sum_score);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	return OK;
}
/*********************************************************************
 * @chujian(cn) 打印表内单行信息
 * @chujian(en) Print a single row of information in the table
 */

Status rankSearch(SqList* L, int sort_manner, char key, int i, ElemType* e)
{
	if (key != 'l' && key != 'm' && key != 'e' && key != 'a' && key != 's')
		return ERROR;
	ListSort(L, sort_manner, key);
	GetElem(L, i, e);
	putSingleList(e);
	return OK;
}
/*********************************************************************
 * @chujian(cn) 名次查询引擎
 * @chujian(en) Ranking query engine
 */

Status passLiterature(ElemType a, ElemType b)
{
	if (a.score_literature <= b.score_literature)
		return OK;
	else
		return 0;
}

Status passMath(ElemType a, ElemType b)
{
	if (a.score_math <= b.score_math)
		return OK;
	else
		return 0;
}

Status passEnglish(ElemType a, ElemType b)
{
	if (a.score_english <= b.score_english)
		return OK;
	else
		return 0;
}

Status compAveScore(ElemType a, ElemType b)
{
	if (a.average_score <= b.average_score)
		return OK;
	else
		return 0;
}

Status compSumScore(ElemType a, ElemType b)
{
	if (a.sum_score <= b.sum_score)
		return OK;
	else
		return 0;
}

Status countSex(SqList* L)
{
	char boy[4] = "男";
	int boy_count = 0, girl_count = 0;
	for (int i = 0; i < L->length; ++i)
		if (strcmp(boy, (L->elem)[i].sex))
			++girl_count;
		else
			++boy_count;
	printf("男同学：%d\n女同学：%d\n", boy_count, girl_count);
	return OK;
}

Status statistic(SqList* L, float* compScore)
{
	printf("当前学生总人数：%d\n", L->length);
	char key[5] = { 'l', 'm', 'e', 'a', 's' };
	ElemType* r = (ElemType*)malloc(sizeof(ElemType));
	if (r == NULL)
		exit(INFEASIBLE);
	r->sum_score = *(compScore + 4);
	r->average_score = *(compScore + 3);
	r->score_english = *(compScore + 2);
	r->score_math = *(compScore + 1);
	r->score_literature = *(compScore + 0);
	for (int i = 0, sort_manner = 1; i < 5; ++i)
	{
		ListSort(L, sort_manner, key[i]);
		switch (i)
		{
		case 0:
			printf("语文及格的人数有：%d\n", L->length - LocateElem(L, r, passLiterature) + 1);
			break;
		case 1:
			printf("数学及格的人数有：%d\n", L->length - LocateElem(L, r, passMath) + 1);
			break;
		case 2:
			printf("英语及格的人数有：%d\n", L->length - LocateElem(L, r, passEnglish) + 1);
			break;
		case 3:
			printf("平均分达到及格线的有：%d人\n", L->length - LocateElem(L, r, compAveScore) + 1);
			break;
		case 4:
			printf("总分达到%.2f的有：%d人\n", *(compScore + 4), L->length - LocateElem(L, r, compSumScore) + 1);
			break;
		}
	}
	countSex(L);
	free(r);
	return OK;
}
/*********************************************************************
 * @chujian(cn) 学生信息统计
 * @chujian(en) Student Information Statistics
 */
