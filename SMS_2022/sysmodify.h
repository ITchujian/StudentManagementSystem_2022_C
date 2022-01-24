#pragma once
/*********************************************************************
 * ת����ע����Դ/Reprint please indicate the source
 * @FileName sysmodify.h
 * @Description ѧ����Ϣ�޸�ϵͳ/Student Information Modification System
 * @History
 * version      author      data       introduction and operations
 *  1.0         ����     2022-01-23             Create
 *  ***         ***      ****-**-**             *******
 */

#include "kernel_list.h"
 /*********************************************************************
  * @chujian(cn) �����Զ���ͷ�ļ�
  * @chujian(en) Import custom header files
  */

Status changeMenu(void)
{
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                            �������� Ϣ �� �� ϵ ͳ                            ��\n");
	printf("�ǩ���������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("����ѡ�����:                                                                    ��\n");
	printf("��                             1 > �� �� ѧ ��                                   ��\n");
	printf("��                             2 > �޸�ѧ����Ϣ                                  ��\n");
	printf("��                             3 > [Σ]ɾ��ѧ��                                  ��\n");
	printf("��                             4 > [Σ]���ÿձ�                                  ��\n");
	printf("��                             0 > ������ϵͳ                                    ��\n");
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\nINPUT:");
	return OK;
}
/*********************************************************************
 * @chujian(cn) ��Ϣ�޸�ϵͳ
 * @chujian(en) Information revision system
 */

Status selectChange(void)
{
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                    ��������Ϣ�޸�ϵͳ> �� �� ѧ �� �� Ϣ                      ��\n");
	printf("�ǩ���������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("����ѡ�����:                                                                    ��\n");
	printf("��                             1 > �� �� �� ��                                   ��\n");
	printf("��                             2 > �� �� ѧ ��                                   ��\n");
	printf("��                             3 > �� �� �� ��                                   ��\n");
	printf("��                             4 > �� �� �� ��                                   ��\n");
	printf("��                             5 > �� �� �� ��                                   ��\n");
	printf("��                             6 > �� �� �� ѧ                                   ��\n");
	printf("��                             7 > �� �� Ӣ ��                                   ��\n");
	printf("��                             0 > ���ظ�ϵͳ                                    ��\n");
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\nINPUT:");
	return OK;
}
/*********************************************************************
 * @chujian(cn) ��Ӧ��Ϣ�޸�ϵͳ�еĵڶ���
 * @chujian(en) Corresponds to the second item in the information modification system
 */

Status addStudent(SqList* L)
{
	ElemType* e = (ElemType*)malloc(sizeof(ElemType));
	if (e == NULL)
		exit(INFEASIBLE);
	printf("\n������");
	scanf("%s", e->name);
	printf("\nѧ�ţ�");
	scanf("%d", &(e->num));
	printf("\n�Ա�");
	scanf("%s", e->sex);
	printf("\n���䣺");
	scanf("%d", &(e->age));
	printf("\n���ģ�");
	scanf("%f", &(e->score_literature));
	printf("\n��ѧ��");
	scanf("%f", &(e->score_math));
	printf("\nӢ�");
	scanf("%f", &(e->score_english));
	e->average_score = (e->score_literature + e->score_math + e->score_english) / 3;
	e->sum_score = e->score_literature + e->score_math + e->score_english;
	ListInsert(L, L->length + 1, *e);
	free(e);
	system("cls");
	return OK;
}
/*********************************************************************
 * @chujian(cn) ���ѧ��
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
 * @chujian(cn) �ı�ѧ����Ϣ
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
	printf("���Ѿ�ɾ����ѧ��%s����Ϣ\n", e->name);
	free(e);
	return OK;
}
/*********************************************************************
 * @chujian(cn) ɾ��ѧ����Ϣ
 * @chujian(en) Delete information of student
 */

Status resetAll(SqList* L)
{
	getchar();
	char is_yes;
	printf("������y��Yȷ�ϣ�");
	scanf("%c", &is_yes);
	if (is_yes == 'y' || is_yes == 'Y')
		ClearList(L);
	else
		printf("δ����\n");
	return OK;
}
/*********************************************************************
 * @chujian(cn) ����ѧ����Ϣ��
 * @chujian(en) Reset student information sheet
 */
