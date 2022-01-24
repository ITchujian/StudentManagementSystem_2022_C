/*********************************************************************
 * 转载请注明来源/Reprint please indicate the source
 * @FileName SMS_2022.cpp
 * @Description 运行的主文件/main file to run
 * @History
 * version      author      data       introduction and operations
 *  1.0         初见     2022-01-23             Create
 *  1.1         初见     2022-01-24          Fix some bugs
 *  ***         ***      ****-**-**            *******
 */

#include "sysbrowse.h"
#include "sysmodify.h"
#include "sysdoc.h"
 /*********************************************************************
  * @chujian(cn) 引入自定义头文件
  * @chujian(en) Import custom header files
  */

Status homeMenu(void);
Status browseStuSystem(SqList*);
Status changeStuSystem(SqList*);
Status ioFileStuSystem(SqList*);
Status setSystem(SqList*);
/*********************************************************************
 * @chujian(cn) 函数声明
 * @chujian(en) Function declaration
 */

int main(void)
{
	loadConfig();

	SqList student_list;
	InitList(&student_list);
	loadList(&student_list);
	loadStu(&student_list);

	do
	{
		system("cls");
		homeMenu();
		int home_select;
		scanf("%d", &home_select);
		switch (home_select)
		{
		case 1:
		{
			browseStuSystem(&student_list);
			break;
		}
		case 2:
		{
			changeStuSystem(&student_list);
			break;
		}
		case 3:
		{
			ioFileStuSystem(&student_list);
			break;
		}
		case 4:
		{
			setSystem(&student_list);
			break;
		}
		case 0:
			DestroyList(&student_list);
			return 0;
		default:
			printf("该按键未开发任何功能，请重新输入\n");
			system("pause");
			break;
		}
	} while (TRUE);

	return 0;
}
/*********************************************************************
 * @chujian main
 */

Status homeMenu(void)
{
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                            学 生 信 息 管 理 系 统                          ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃请选择操作:                                                                  ┃\n");
	printf("┃                             1 > 学生信息浏览系统                            ┃\n");
	printf("┃                             2 > 学生信息修改系统                            ┃\n");
	printf("┃                             3 > [重要]保存信息                              ┃\n");
	printf("┃                             4 > 系 统 设 置                                 ┃\n");
	printf("┃                             0 > 退 出 系 统                                 ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\nINPUT:");
	return OK;
}
/*********************************************************************
 * @chujian(cn) 主页功能菜单
 * @chujian(en) Home function menu
 */

Status browseStuSystem(SqList* L)
{
	do
	{
		system("cls");
		browseMenu();
		int browse_select;
		scanf("%d", &browse_select);
		switch (browse_select)
		{
		case 1:
		{
			putAllList(L);
			system("pause");
			break;
		}
		case 2:
		{
			int student_id;
			printf("若学号不存在，则返回null，表示未找到\n");
			printf("INPUT：");
			scanf("%d", &student_id);
			ElemType* e = (ElemType*)malloc(sizeof(ElemType));
			if (e == NULL)
				exit(INFEASIBLE);
			Status re = SearchElem(L, student_id, e, 0);
			if (re == INFEASIBLE)
			{
				printf("null\n");
				system("pause");
				break;
			}
			putSingleList(e);
			free(e);
			system("pause");
			break;
		}
		case 3:
		{
			int sort_manner;
			char sort_key;
			printf("排序方式(0或任意负数为降序、1或任意正数为升序)\n");
			printf("INPUT：");
			scanf("%d", &sort_manner);
			getchar();
			printf("\n排序项(n-学号、l-语文、m-数学、e-英语、a-平均分、s-总分)\n");
			printf("INPUT：");
			scanf("%c", &sort_key);
			ListSort(L, sort_manner, sort_key);
			putAllList(L);
			system("pause");
			break;
		}
		case 4:
		{
			int sort_manner, i;
			char sort_key;
			ElemType* e = (ElemType*)malloc(sizeof(ElemType));
			getchar();
			printf("查询科目(l-语文、m-数学、e-英语、a-平均分、s-总分)\n");
			printf("INPUT：");
			scanf("%c", &sort_key);
			printf("正排名还是倒排名(0或任意负数为正排名、1或任意正数为倒排名)\n");
			printf("INPUT：");
			scanf("%d", &sort_manner);
			printf("第几名？\n");
			printf("INPUT：");
			scanf("%d", &i);
			rankSearch(L, sort_manner, sort_key, i, e);
			free(e);
			system("pause");
			break;
		}
		case 5:
		{
			printf("输入0则以默认方式统计[科目分数60及格、总分180分及格]，非0则为自定义统计\n");
			printf("INPUT：");
			int select;
			char comp_item[5][10] = { "语文", "数学", "英语", "平均分", "总分" };
			float comp_score[5] = { 60, 60, 60, 60, 180 };
			scanf("%d", &select);
			if (select == 0)
				statistic(L, comp_score);
			else
			{
				for (int i = 0; i < 5; i++)
				{
					printf("%s：", comp_item[i]);
					scanf("%f", &comp_score[i]);
				}
				statistic(L, comp_score);
			}
			system("pause");
			break;
		}
		case 0:
			return OK;
		default:
			printf("该按键未开发任何功能，请重新输入\n");
			break;
		}
	} while (TRUE);
}
/*********************************************************************
 * @chujian(cn) 学生信息浏览系统的整体实现
 * @chujian(en) The whole realization of Student Information Browsing System
 */

Status changeStuSystem(SqList* L)
{
	do
	{
		system("cls");
		changeMenu();
		int change_select;
		scanf("%d", &change_select);
		switch (change_select)
		{
		case 1:
		{
			if (addStudent(L))
				printf("添加成功！\n");
			else
				printf("添加失败！\n");
			system("pause");
			break;
		}
		case 2:
		{
			int student_id;
			printf("若学号不存在，则修改失败\n");
			printf("INPUT：");
			scanf("%d", &student_id);
			if (changeElem(L, student_id) != INFEASIBLE)
				printf("修改成功！\n");
			else
				printf("修改失败！\n");
			system("pause");
			break;
		}
		case 3:
		{
			int student_id;
			printf("若学号不存在，则删除失败\n");
			printf("INPUT：");
			scanf("%d", &student_id);
			deleteElem(L, student_id);
			system("pause");
			break;
		}
		case 4:
		{
			resetAll(L);
			system("pause");
			break;
		}
		case 0:
			return OK;
		default:
			printf("该按键未开发任何功能，请重新输入\n");
			break;
		}
	} while (TRUE);
}
/*********************************************************************
 * @chujian(cn) 学生信息修改系统的整体实现
 * @chujian(en) The overall realization of Student Information Modification System
 */

Status ioFileStuSystem(SqList* L)
{
	getchar();
	char is_yes;
	printf("请输入y或Y确认：");
	scanf("%c", &is_yes);
	if (is_yes == 'y' || is_yes == 'Y')
	{
		FILE* fp;
		fopen_s(&fp, config_bin.list_path, "w");
		if (fp != NULL)
		{
			fprintf(fp, "%d %d\n", L->length, L->list_size);
			fclose(fp);
			printf("保存成功\n");
		}
		writeFile(config_bin.file_path, L->elem, sizeof(ElemType), L->length);

	}
	else
		return INFEASIBLE;
	system("pause");
	return OK;
}
/*********************************************************************
 * @chujian(cn) 实现保存信息表功能
 * @chujian(en) Implement the function of saving the information table
 */

Status setSystem(SqList* L)
{
	do
	{
		system("cls");
		setMenu();
		int set_select;
		scanf("%d", &set_select);
		switch (set_select)
		{
		case 1:
		{
			char dir_path[] = ".\\SMSdir";
			createFolder(dir_path);
			char config_path[128];
			sprintf(config_path, "%s\\config.bin", dir_path);
			printf("\n学生信息表存储路径(默认是.\\SMSdir\\students.bin)：");
			scanf("%s", config_bin.file_path);
			writeFile(config_path, &config_bin, sizeof(SysConfig), 4);
			break;
		}
		case 2:
		{
			char dir_path[] = ".\\SMSdir";
			createFolder(dir_path);
			char config_path[128];
			sprintf(config_path, "%s\\config.bin", dir_path);
			printf("\n学生信息表备份路径(默认是.\\SMSdir\\students.bin.bak)：");
			scanf("%s", config_bin.backup_path);
			writeFile(config_path, &config_bin, sizeof(SysConfig), 4);
			break;
		}
		case 3:
		{
			char dir_path[] = ".\\SMSdir";
			createFolder(dir_path);
			char config_path[128];
			sprintf(config_path, "%s\\config.bin", dir_path);
			colorMenu();
			char color[4];
			printf("\n第一个表示背景色 第二个表示字体颜色 如06或者1A\n");
			printf("INPUT：");
			scanf("%s", color);
			sprintf(config_bin.sys_color, "color %s", color);
			writeFile(config_path, &config_bin, sizeof(SysConfig), 4);
			break;
		}
		case 4:
		{
			char dir_path[] = ".\\SMSdir";
			createFolder(dir_path);
			char config_path[128];
			sprintf(config_path, "%s\\config.bin", dir_path);
			printf("\n表格内核路径(默认是.\\SMSdir\\list_path.bin)：");
			scanf("%s", config_bin.list_path);
			writeFile(config_path, &config_bin, sizeof(SysConfig), 4);
			break;
		}
		case 0:
			return OK;
		default:
			printf("该按键未开发任何功能，请重新输入\n");
			break;
		}
	} while (TRUE);
}
/*********************************************************************
 * @chujian(cn) 实现系统设置功能
 * @chujian(en) Implement system settings
 */