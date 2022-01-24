#pragma once
/*********************************************************************
 * ת����ע����Դ/Reprint please indicate the source
 * @FileName preconf.h
 * @Description Ԥ�����ļ�/pre-configured header files
 * @History
 * version      author      data       introduction and operations
 *  1.0         ����     2022-01-23             Create
 *  ***         ***      ****-**-**             *******
 */

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <process.h>
#include <io.h>
#include <direct.h>
 /*********************************************************************
  * @chujian(cn) �����׼��ͷ�ļ�
  * @chujian(en) Import standard library headers
  */

#define LIST_INIT_SIZE 128
#define LIST_INCREMENT 16
  /*********************************************************************
   * @chujian(cn) ���ô洢�ռ�ĳ�ʼ������100������10����λ��sizeof(ElemType)
   * @chujian(en) The initial allocation of configuration storage space is 100, in increments of 10, and the unit is sizeof(ElemType)
   */

typedef int Boolean;
#define TRUE 1
#define FALSE 0

typedef int Status;
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOWED -2
/*********************************************************************
 * @chujian(cn) ͨ��ö�٣����岼���͡���������״ֵ̬
 * @chujian(en) Through enumeration, define boolean type, function return status value
 */

typedef struct
{
	char name[20];
	int num;
	char sex[4];
	int age;
	float score_literature;
	float score_math;
	float score_english;
	float average_score;
	float sum_score;
} ElemType;
/*********************************************************************
 * @chujian(cn) ����ѧ����Ϣ�ṹ�壬����������ѧ�ŵ�
 * @chujian(en) Define the student information structure, including name, student ID, etc.
 */

typedef struct
{
	ElemType* elem;
	int length;
	int list_size;
} SqList;
/*********************************************************************
 * @chujian(cn) ˳��洢�ṹ
 * @chujian(en) Dynamic allocation sequential storage structure of linear table
 */

typedef struct
{
	char file_path[128];
	char backup_path[128];
	char list_path[128];
	char sys_color[32];
} SysConfig;
SysConfig config_bin = {};
/*********************************************************************
 * @chujian(cn) �����������ֵ
 * @chujian(en) Dynamic allocation sequential storage structure of linear table
 */