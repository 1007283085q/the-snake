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

array_t	*arr_new();							/* ����һ������		*/

int		            arr_len(array_t *arr);				/* ���鳤��			*/

Snake		   *arr_beg(array_t *arr);				/* ��һ��Ԫ��		*/

Snake		 *arr_end(array_t *arr);				/* ���һ��Ԫ�غ��� */

Snake		   *arr_at(array_t *arr, int ind);		/* ��ind��Ԫ��		*/

void	            arr_add(array_t *arr, Snake *e);		/* ���һ��Ԫ��		*/

void	            arr_del(array_t *arr, int ind);		/* ɾ����ind��Ԫ��	*/

void	            arr_free(array_t *arr);				/* ɾ������			*/
#endif