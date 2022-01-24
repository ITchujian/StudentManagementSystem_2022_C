#pragma once
/*********************************************************************
 * 转载请注明来源/Reprint please indicate the source
 * @FileName sysmodify.h
 * @Description 学生信息修改系统/Student Information Modification System
 * @History
 * version      author      data       introduction and operations
 *  1.0         初见     2022-01-23             Create
 *  ***         ***      ****-**-**             *******
 */

#include "kernel_list.h"
 /*********************************************************************
  * @chujian(cn) 引入自定义头文件
  * @chujian(en) Import custom header files
  */

Status changeMenu(void)
{
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                            【副】信 息 修 改 系 统                            ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃请选择操作:                                                                    ┃\n");
	printf("┃                             1 > 添 加 学 生                                   ┃\n");
	printf("┃                             2 > 修改学生信息                                  ┃\n");
	printf("┃                             3 > [危]删除学生                                  ┃\n");
	printf("┃                             4 > [危]重置空表                                  ┃\n");
	printf("┃                             0 > 返回主系统                                    ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\nINPUT:");
	return OK;
}
/*********************************************************************
 * @chujian(cn) 信息修改系统
 * @chujian(en) Information revision system
 */

Status selectChange(void)
{
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                    【副】信息修改系统> 修 改 学 生 信 息                      ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃请选择操作:                                                                    ┃\n");
	printf("┃                             1 > 修 改 姓 名                                   ┃\n");
	printf("┃                             2 > 修 改 学 号                                   ┃\n");
	printf("┃                             3 > 修 改 性 别                                   ┃\n");
	printf("┃                             4 > 修 改 年 龄                                   ┃\n");
	printf("┃                             5 > 修 改 语 文                                   ┃\n");
	printf("┃                             6 > 修 改 数 学                                   ┃\n");
	printf("┃                             7 > 修 改 英 语                                   ┃\n");
	printf("┃                             0 > 返回副系统                                    ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\nINPUT:");
	return OK;
}
/*********************************************************************
 * @chujian(cn) 对应信息修改系统中的第二项
 * @chujian(en) Corresponds to the second item in the information modification system
 */

Status addStudent(SqList* L)
{
	ElemType* e = (ElemType*)malloc(sizeof(ElemType));
	if (e == NULL)
		exit(INFEASIBLE);
	printf("\n姓名：");
	scanf("%s", e->name);
	printf("\n学号：");
	scanf("%d", &(e->num));
	printf("\n性别：");
	scanf("%s", e->sex);
	printf("\n年龄：");
	scanf("%d", &(e->age));
	printf("\n语文：");
	scanf("%f", &(e->score_literature));
	printf("\n数学：");
	scanf("%f", &(e->score_math));
	printf("\n英语：");
	scanf("%f", &(e->score_english));
	e->average_score = (e->score_literature + e->score_math + e->score_english) / 3;
	e->sum_score = e->score_literature + e->score_math + e->score_english;
	ListInsert(L, L->length + 1, *e);
	free(e);
	system("cls");
	return OK;
}
/*********************************************************************
 * @chujian(cn) 添加学生
 * @chujian(en) Add a student
 */

Status changeElem(SqList* L, int num)
{
	ElemType* r = L->elem;
	int i = 1;
	while (i <= L->length && num != r->num)
	{
		i++;
		r++;
	}
	if (i >= 1 && i <= L->length)
	{
		do
		{
			selectChange();
			int change_item;
			scanf("%d", &change_item);
			switch (change_item)
			{
			case 1:
				scanf("%s", r->name);
				break;
			case 2:
				scanf("%d", &(r->num));
				break;
			case 3:
				scanf("%s", r->sex);
				break;
			case 4:
				scanf("%d", &(r->age));
				break;
			case 5:
				scanf("%f", &(r->score_literature));
				break;
			case 6:
				scanf("%f", &(r->score_math));
				break;
			case 7:
				scanf("%f", &(r->score_english));
				break;
			case 0:
				system("cls");
				return OK;
			default:
				return ERROR;
			}
		} while (1);
		return OK;
	}
	else
		return INFEASIBLE;
}
/*********************************************************************
 * @chujian(cn) 改变学生信息
 * @chujian(en) Change information of student
 */

Status deleteElem(SqList* L, int num)
{
	ElemType* r = L->elem;
	ElemType* e = (ElemType*)malloc(sizeof(ElemType));
	if (e == NULL)
		exit(INFEASIBLE);
	int i = 1;
	while (i <= L->length && num != r->num)
	{
		i++;
		r++;
	}
	ListDelete(L, i, e);
	printf("您已经删除了学生%s的信息\n", e->name);
	free(e);
	return OK;
}
/*********************************************************************
 * @chujian(cn) 删除学生信息
 * @chujian(en) Delete information of student
 */

Status resetAll(SqList* L)
{
	getchar();
	char is_yes;
	printf("请输入y或Y确认：");
	scanf("%c", &is_yes);
	if (is_yes == 'y' || is_yes == 'Y')
		ClearList(L);
	else
		printf("未重置\n");
	return OK;
}
/*********************************************************************
 * @chujian(cn) 重置学生信息表
 * @chujian(en) Reset student information sheet
 */
