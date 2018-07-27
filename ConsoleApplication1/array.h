#pragma once
#include"stdafx.h"
#ifndef s3
#define s3
#define MAX 100
typedef struct array
{
	Snake data[MAX];
	int len;
} array_t;

array_t	*arr_new();							/* 创建一个数组		*/

int		            arr_len(array_t *arr);				/* 数组长度			*/

Snake		   *arr_beg(array_t *arr);				/* 第一个元素		*/

Snake		 *arr_end(array_t *arr);				/* 最后一个元素后面 */

Snake		   *arr_at(array_t *arr, int ind);		/* 第ind个元素		*/

void	            arr_add(array_t *arr, Snake *e);		/* 添加一个元素		*/

void	            arr_del(array_t *arr, int ind);		/* 删除第ind个元素	*/

void	            arr_free(array_t *arr);				/* 删除数组			*/
#endif