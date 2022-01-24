#pragma once
/*********************************************************************
 * 转载请注明来源/Reprint please indicate the source
 * @FileName sysdoc.h
 * @Description 文件读写操作相关文件/File read and write operations related files
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

Status setMenu(void)
{
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                            【副】系 统 设 置                                  ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃                 警告 通常情况下，我并不建议您更改除3以外的设置                ┃\n");
	printf("┃请选择操作:                                                                    ┃\n");
	printf("┃                             1 > 更改存储路径                                  ┃\n");
	printf("┃                             2 > 更改备份路径                                  ┃\n");
	printf("┃                             3 > 设置前背景颜色                                ┃\n");
	printf("┃                             4 > [危]内核列表路径                              ┃\n");
	printf("┃                             0 > 返回主系统                                    ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\nINPUT:");
	return OK;
}
/*********************************************************************
 * @chujian(cn) 系统设置界面
 * @chujian(en) System setting interface
 */

Status colorMenu(void)
{
	printf("颜色参考表：\n");
	printf("0 = 黑色       8 = 灰色\n");
	printf("1 = 蓝色       9 = 淡蓝色\n");
	printf("2 = 绿色       A = 淡绿色\n");
	printf("3 = 浅绿色     B = 淡浅绿色\n");
	printf("4 = 红色       C = 淡红色\n");
	printf("5 = 紫色       D = 淡紫色\n");
	printf("6 = 黄色       E = 淡黄色\n");
	printf("7 = 白色       F = 亮白色\n");
	return OK;
}
/*********************************************************************
 * @chujian(cn) 对应系统设置中的第三项
 * @chujian(en) Corresponds to the third item in the system settings
 */

Status createFolder(char* path)
{
	char folder_path[128];
	sprintf(folder_path, "mkdir %s", path);
	if (_access(path, 0) == -1)
	{
		system(folder_path);
	}
	return OK;
}
/*********************************************************************
 * @chujian(cn) 创建目录
 * @chujian(en) Create a directory
 */

Status writeFile(char* path, void* struct_s, int s_size, int length)
{
	FILE* fp;
	fopen_s(&fp, path, "wb+");
	if (fp != 0)
	{
		fwrite(struct_s, s_size, length, fp);
		fclose(fp);
		return OK;
	}
	else
		return INFEASIBLE;
}
/*********************************************************************
 * @chujian(cn) 将数据流写入.bin文件
 * @chujian(en) Write data stream to .bin file
 */

Status readFile(char* path, void* struct_s, int s_size, int length)
{
	FILE* fp;
	fopen_s(&fp, path, "rb+");
	if (fp != 0)
	{
		fread(struct_s, s_size, length, fp);
		fclose(fp);
		return OK;
	}
	else
		return INFEASIBLE;
}
/*********************************************************************
 * @chujian(cn) 从.bin文件中读取数据流
 * @chujian(en) Read data stream from .bin file
 */

Status loadConfig(void)
{
	char dir_path[] = ".\\SMSdir";
	createFolder(dir_path);
	char config_path[128];
	sprintf(config_path, "%s\\config.bin", dir_path);
	readFile(config_path, &config_bin, sizeof(SysConfig), 4);
	system(config_bin.sys_color);
	return OK;
}
/*********************************************************************
 * @chujian(cn) 初始化配置config.bin文件
 * @chujian(en) Initialize the configuration config.bin file
 */

Status loadList(SqList* L)
{
	//readFile(config_bin.list_path, L, sizeof(SqList), 3);
	FILE* fp;
	fopen_s(&fp, config_bin.list_path, "r+");
	if (fp != 0)
	{
		fscanf_s(fp, "%d %d\n", &(L->length), &(L->list_size));
		fclose(fp);
		return OK;
	}
	else
		return INFEASIBLE;
	return OK;
}
/*********************************************************************
 * @chujian(cn) 加载内核线性表中除对应elem的数据
 * @chujian(en) Load the data in the kernel linear table except the student structure
 */

Status loadStu(SqList* L)
{
	readFile(config_bin.file_path, L->elem, sizeof(ElemType), L->length);
	return OK;
}
/*********************************************************************
 * @chujian(cn) 加载上一次保存的学生信息表
 * @chujian(en) Load the last saved student information sheet
 */
