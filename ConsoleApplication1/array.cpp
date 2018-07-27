#include"stdafx.h"
#include "array.h"
#include <stdlib.h>
#include <assert.h>

/*
* ����һ������
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
* ���ص�һ��Ԫ�ص�ַ
*/
Snake *arr_beg(array_t *arr)
{
	return arr->data;
}

/*
* ���س������һ��Ԫ��һ�����Ǹ�λ��
*/
Snake *arr_end(array_t *arr)
{
	return &arr->data[arr->len];
}

/*
* ����ĵ�ind��Ԫ��
*/
Snake *arr_at(array_t *arr, int ind)
{
	return &arr->data[ind];
}

/*
* ���һ��Ԫ��
*/
void arr_add(array_t *arr, Snake *e)
{
	*arr_end(arr) = *e;
	arr->len++;
}

/*
* ɾ����ind��Ԫ�أ�
*		�ӵ�ind��Ԫ�غ�һ��Ԫ�ؿ�ʼ��
*		��ÿ��Ԫ����ǰ��һ��λ��
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
* ��������
*/
void arr_free(array_t *arr)
{
	free(arr);
}