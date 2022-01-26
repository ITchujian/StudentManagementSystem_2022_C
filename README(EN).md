# Thanks for referring to the C language project of `First Encounter` - Student Management System 2022

It is the first open-source project of a student management system written in C language on GitHub in 2022. It is suitable for C language beginners and C language candidates for reference. It can be used by educational institutions and schools with minor modifications.

Note: Please make sure to copy `config.bin` to the SMSdir folder in the same exe file directory when you run it for the first time.

---

## 1. Summary

**Listen to me**: This project is written in C. One of the great things about [C language](https://zh.wikipedia.org/wiki/C%E8%AF%AD%E8%A8%80) is that it is the easiest to learn and the fastest Programming language. This project is a work that I am familiar with the data structure before the postgraduate entrance examination. The functions may not be as complete as you think, and there may be a small number of bugs. Please forgive me. Thank you again for choosing the reference book in the vast project. Project, I am very honored about it. If you need to continue to develop 🚧 new functions, please be sure to beware of various problems in memory, after all, C language is also a very dangerous programming language.

## 2. Design thinking

- Precompile: `preconf.h`
  
  - Import standard library header files
  - Macros define each variable
  - define each type
  - define the structure
- core: `kernel_list.h`
  
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
- File read and write operations: `sysdoc.h`
  
  - Operations on data streams based on core files
  - For the main file to complete some functions
- main file: `SMS_2022.cpp`
  
  - Information browsing system based on core files
  - Information modification system based on core files
  - Data stream reading and writing system based on core files
  - System settings based on C language and Windows system characteristics

## 3. Development environment

- Development system: `Windows 11`
- Test system: `VM Windows 10`, `Windows 11`
- IDE: `Visual Studio 2022 Community Edition`
- Full encoding: `UTF-8`

## Four, development specifications

- Function names of core files: big camel case
- Function names of non-core files: little camel case
- Non-macro-defined variable names: underscore notation (all lowercase)
- Variable names defined by macros: underscore notation (all uppercase)
- General Notes:

````
/**************************************************** ********************
* @chujian(cn) 通过枚举，定义布尔型、函数返回状态值
* @chujian(en) Through enumeration, define boolean type, function return status value
*/
````

- file header comments

````
/**************************************************** ********************
 * Reprint please indicate the source/Reprint please indicate the source
 * @FileName preconf.h
 * @Description 预配置文件/pre-configured header files
 * @History
 * version author data introduction and operations
 * 1.0 first seen 2022-01-23 Create
 * *** *** ****-**-** *******
 */
````

- Very few comments use single-line comment characters

## 5. More exciting

| Channel | Nickname |
| :-------- | :----- |
| GitHub | [FirstMet初见](https://github.com/ITchujian)|
| CDSN | [初见小菜G](https://blog.csdn.net/weixin_46231858) |
