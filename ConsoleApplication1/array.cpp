#include"stdafx.h"
#include "array.h"
#include <stdlib.h>
#include <assert.h>

/*
* 创建一个数组
*/



array_t	*arr_new()
{
	array_t *rst;
	rst = (array_t *)malloc(sizeof(array_t));
	assert(rst);
	rst->len = 0;
	return rst;
}

int arr_len(array_t *arr)
{
	return arr->len;
}

/*
* 返回第一个元素地址
*/
Snake *arr_beg(array_t *arr)
{
	return arr->data;
}

/*
* 返回超出最后一个元素一个的那个位置
*/
Snake *arr_end(array_t *arr)
{
	return &arr->data[arr->len];
}

/*
* 数组的第ind个元素
*/
Snake *arr_at(array_t *arr, int ind)
{
	return &arr->data[ind];
}

/*
* 添加一个元素
*/
void arr_add(array_t *arr, Snake *e)
{
	*arr_end(arr) = *e;
	arr->len++;
}

/*
* 删除第ind个元素：
*		从第ind个元素后一个元素开始，
*		把每个元素向前搬一个位置
*/
void arr_del(array_t *arr, int ind)
{
	Snake *first = arr_at(arr, ind + 1);

	while (first < arr_end(arr)) {
		*(first - 1) = *first;
		first++;
	}

	arr->len--;
}

/*
* 销毁数组
*/
void arr_free(array_t *arr)
{
	free(arr);
}