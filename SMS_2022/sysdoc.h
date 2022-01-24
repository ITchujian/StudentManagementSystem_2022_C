#pragma once
/*********************************************************************
 * ת����ע����Դ/Reprint please indicate the source
 * @FileName sysdoc.h
 * @Description �ļ���д��������ļ�/File read and write operations related files
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

Status setMenu(void)
{
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                            ������ϵ ͳ �� ��                                  ��\n");
	printf("�ǩ���������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                 ���� ͨ������£��Ҳ������������ĳ�3���������                ��\n");
	printf("����ѡ�����:                                                                    ��\n");
	printf("��                             1 > ���Ĵ洢·��                                  ��\n");
	printf("��                             2 > ���ı���·��                                  ��\n");
	printf("��                             3 > ����ǰ������ɫ                                ��\n");
	printf("��                             4 > [Σ]�ں��б�·��                              ��\n");
	printf("��                             0 > ������ϵͳ                                    ��\n");
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\nINPUT:");
	return OK;
}
/*********************************************************************
 * @chujian(cn) ϵͳ���ý���
 * @chujian(en) System setting interface
 */

Status colorMenu(void)
{
	printf("��ɫ�ο���\n");
	printf("0 = ��ɫ       8 = ��ɫ\n");
	printf("1 = ��ɫ       9 = ����ɫ\n");
	printf("2 = ��ɫ       A = ����ɫ\n");
	printf("3 = ǳ��ɫ     B = ��ǳ��ɫ\n");
	printf("4 = ��ɫ       C = ����ɫ\n");
	printf("5 = ��ɫ       D = ����ɫ\n");
	printf("6 = ��ɫ       E = ����ɫ\n");
	printf("7 = ��ɫ       F = ����ɫ\n");
	return OK;
}
/*********************************************************************
 * @chujian(cn) ��Ӧϵͳ�����еĵ�����
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
 * @chujian(cn) ����Ŀ¼
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
 * @chujian(cn) ��������д��.bin�ļ�
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
 * @chujian(cn) ��.bin�ļ��ж�ȡ������
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
 * @chujian(cn) ��ʼ������config.bin�ļ�
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
 * @chujian(cn) �����ں����Ա��г���Ӧelem������
 * @chujian(en) Load the data in the kernel linear table except the student structure
 */

Status loadStu(SqList* L)
{
	readFile(config_bin.file_path, L->elem, sizeof(ElemType), L->length);
	return OK;
}
/*********************************************************************
 * @chujian(cn) ������һ�α����ѧ����Ϣ��
 * @chujian(en) Load the last saved student information sheet
 */
