# 感谢参考 `初见` 的 C语言项目——学生管理系统2022

它是GitHub上2022年第一个由C语言编写的学生管理系统开源项目，可参考性适用于C语言初学者和C语言考生，稍加修改，可供各教育机构以及学校实际使用。
注：初次运行，请务必拷贝`config.bin`于同exe文件目录的SMSdir文件夹中。

---

## 一、概要

**听我说**：该项目由C语言编写。[C语言](https://zh.wikipedia.org/wiki/C%E8%AF%AD%E8%A8%80) 的一大优点在于：它是最容易上手且运行速度极快的一门编程语言。该项目是作为我考研之前对数据结构熟悉入门的作品，可能功能不如您所想像的那么齐全，也可能存在少部分的bug，请对我予以谅解，再次感谢您能在茫茫项目中选择参考本项目，我对此感到非常荣幸，如果您需要持续开发🚧新的功能，请务必提防内存方面的各种问题，毕竟C语言也是一门非常危险的编程语言。

## 二、设计思想

- 预编译：`preconf.h`
  
  - 引入标准库头文件
  - 宏定义各变量
  - 定义各类型
  - 定义结构体
- 核心：`kernel_list.h`
  
  - Status InitList(SqList* L);
  - Status DestroyList(SqList* L)
  - Status ClearList(SqList* L)
  - Boolean ListEmpty(SqList* L)
  - int ListLength(SqList* L)
  - Status GetElem(SqList* L, int i, ElemType* e)
  - int LocateElem(SqList* L, ElemType* e, Status(*compare)(ElemType, ElemType))
  - Status SearchElem(SqList* L, int cur_e, ElemType* e, int mode_manner)
  - Status ListInsert(SqList* L, int i, ElemType e)
  - Status ListDelete(SqList* L, int i, ElemType* e)
  - Status ListTraverse(SqList* L, void(*visit)(ElemType*))
  - Status SwapElem(ElemType* x, ElemType* y)
  - Status ListSort(SqList* L, int sort_manner, char key)
- 文件读写操作：`sysdoc.h`
  
  - 基于核心文件对数据流操作
  - 供main文件完成部分功能
- main文件：`SMS_2022.cpp`
  
  - 基于核心文件的信息浏览系统
  - 基于核心文件的信息修改系统
  - 基于核心文件的数据流读写系统
  - 基于C语言与Windows系统特性的系统设置

## 三、开发环境

- 开发系统：`Windows 11`
- 测试系统：`VM Windows 10`、`Windows 11`
- IDE：`Visual Studio 2022 社区版`
- 全程编码：`UTF-8`

## 四、开发规范

- 核心文件的函数名：大驼峰命名法
- 非核心文件的函数名：小驼峰命名法
- 非宏定义的变量名：下划线命名法(全小写)
- 宏定义的变量名：下划线命名法(全大写)
- 通用注释：

```
/*********************************************************************
* @chujian(cn) 通过枚举，定义布尔型、函数返回状态值
* @chujian(en) Through enumeration, define boolean type, function return status value
*/
```

- 文件头注释

```
/*********************************************************************
 * 转载请注明来源/Reprint please indicate the source
 * @FileName preconf.h
 * @Description 预配置文件/pre-configured header files
 * @History
 * version      author      data       introduction and operations
 *  1.0         初见     2022-01-23             Create
 *  ***         ***      ****-**-**             *******
 */
```

- 极少部分注释使用的是单行注释符

## 五、更多精彩

| 渠道  | 昵称 |
| :--------  | :-----  |
| GitHub | [FirstMet初见](https://github.com/ITchujian)|
| CDSN | [初见小菜G](https://blog.csdn.net/weixin_46231858) |


