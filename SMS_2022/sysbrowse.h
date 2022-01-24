#pragma once
/*********************************************************************
 * ת����ע����Դ/Reprint please indicate the source
 * @FileName sysbrowse.h
 * @Description ѧ����Ϣ���ϵͳ/Student Information Browsing System
 * @History
 * version      author      data       introduction and operations
 *  1.0         ����     2022-01-22             Create
 *  ***         ***      ****-**-**             *******
 */

#include "kernel_list.h"
#include "sysdoc.h"
 /*********************************************************************
  * @chujian(cn) �����Զ���ͷ�ļ�
  * @chujian(en) Import custom header files
  */

Status browseMenu(void)
{
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                            �������� Ϣ � �� ϵ ͳ                            ��\n");
	printf("�ǩ���������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("����ѡ�����:                                                                    ��\n");
	printf("��                             1 > �鿴����ѧ����Ϣ                              ��\n");
	printf("��                             2 > ����ѧ������ѧ��                              ��\n");
	printf("��                             3 > ����ѧ����Ϣ                                  ��\n");
	printf("��                             4 > ���β�ѯѧ��                                  ��\n");
	printf("��                             5 > һ��ͳ��������Ϣ                              ��\n");
	printf("��                             0 > ������ϵͳ                                    ��\n");
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\nINPUT:");
	return OK;
}
/*********************************************************************
 * @chujian(cn) ��Ϣ���ϵͳ
 * @chujian(en) Information browsing system
 */

Status putAllList(SqList* L)
{
	int i = 0;
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��  ����        ѧ��        �Ա�        ����        ����        ��ѧ        Ӣ��        ƽ����        �ܷ�   ��\n");
	printf("�ǩ�����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	while (i < L->length)
	{
		printf("��  %-9s%-16d%-12s%-11d%-12.2f%-12.2f%-12.2f%-13.2f%-8.2f��\n", (L->elem[i]).name, (L->elem[i]).num, (L->elem[i]).sex, (L->elem[i]).age, (L->elem[i]).score_literature, (L->elem[i]).score_math, (L->elem[i]).score_english, (L->elem[i]).average_score, (L->elem[i]).sum_score);
		++i;
	}
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	return OK;
}
/*********************************************************************
 * @chujian(cn) ��ӡ����ȫ����Ϣ
 * @chujian(en) Print all the information in the form
 */

Status putSingleList(ElemType* e)
{
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��  ����        ѧ��        �Ա�        ����        ����        ��ѧ        Ӣ��        ƽ����        �ܷ�   ��\n");
	printf("�ǩ�����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��  %-9s%-16d%-12s%-11d%-12.2f%-12.2f%-12.2f%-13.2f%-8.2f��\n", e->name, e->num, e->sex, e->age, e->score_literature, e->score_math, e->score_english, e->average_score, e->sum_score);
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	return OK;
}
/*********************************************************************
 * @chujian(cn) ��ӡ���ڵ�����Ϣ
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
 * @chujian(cn) ���β�ѯ����
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
	char boy[4] = "��";
	int boy_count = 0, girl_count = 0;
	for (int i = 0; i < L->length; ++i)
		if (strcmp(boy, (L->elem)[i].sex))
			++girl_count;
		else
			++boy_count;
	printf("��ͬѧ��%d\nŮͬѧ��%d\n", boy_count, girl_count);
	return OK;
}

Status statistic(SqList* L, float* compScore)
{
	printf("��ǰѧ����������%d\n", L->length);
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
			printf("���ļ���������У�%d\n", L->length - LocateElem(L, r, passLiterature) + 1);
			break;
		case 1:
			printf("��ѧ����������У�%d\n", L->length - LocateElem(L, r, passMath) + 1);
			break;
		case 2:
			printf("Ӣ�Ｐ��������У�%d\n", L->length - LocateElem(L, r, passEnglish) + 1);
			break;
		case 3:
			printf("ƽ���ִﵽ�����ߵ��У�%d��\n", L->length - LocateElem(L, r, compAveScore) + 1);
			break;
		case 4:
			printf("�ִܷﵽ%.2f���У�%d��\n", *(compScore + 4), L->length - LocateElem(L, r, compSumScore) + 1);
			break;
		}
	}
	countSex(L);
	free(r);
	return OK;
}
/*********************************************************************
 * @chujian(cn) ѧ����Ϣͳ��
 * @chujian(en) Student Information Statistics
 */
