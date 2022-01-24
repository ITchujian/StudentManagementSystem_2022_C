#pragma once
/*********************************************************************
 * 转载请注明来源/Reprint please indicate the source
 * @FileName preconf.h
 * @Description 预配置文件/pre-configured header files
 * @History
 * version      author      data       introduction and operations
 *  1.0         初见     2022-01-23             Create
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
  * @chujian(cn) 引入标准库头文件
  * @chujian(en) Import standard library headers
  */

#define LIST_INIT_SIZE 128
#define LIST_INCREMENT 16
  /*********************************************************************
   * @chujian(cn) 配置存储空间的初始分配量100，增量10，单位是sizeof(ElemType)
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
 * @chujian(cn) 通过枚举，定义布尔型、函数返回状态值
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
 * @chujian(cn) 定义学生信息结构体，包含姓名、学号等
 * @chujian(en) Define the student information structure, including name, student ID, etc.
 */

typedef struct
{
	ElemType* elem;
	int length;
	int list_size;
} SqList;
/*********************************************************************
 * @chujian(cn) 顺序存储结构
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
 * @chujian(cn) 编译外的设置值
 * @chujian(en) Dynamic allocation sequential storage structure of linear table
 */