#include"stdafx.h"
/*#include"array.h"
#include"fs.h"
*/
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
static FILE *db = NULL;

void save_data(array_t *p);
void load_data_to_screen();

void load_data_to_container(array_t *p);
void show_data_from_container(array_t *p);
void save_data(array_t *p)
{
	Snake *first;

	fopen_s(&db,"Snaketest.dat", "w+");

	first = arr_beg(p);
	for (; first < arr_end(p); first++)
	{
		fwrite(first, sizeof(Snake), 1, db);// д��������Ϣ

	}
	fclose(db);

}


void load_data_to_screen()
{

	Snake temp;

	fopen_s(&db,"test.dat", "r+");

	fread(&temp, sizeof(Snake), 1, db);
	while (!feof(db))
	{
		Pos(temp.x, temp.y);
		printf("��");
		fread(&temp, sizeof(Snake), 1, db);
	}
	fclose(db);
}

void load_data_to_container(array_t *p)
{
	Snake temp;
	fopen_s(&db,"Snaketest.dat", "r+");
	fread(&temp, sizeof(Snake), 1, db);
	while (!feof(db))
	{
		arr_add(p, &temp);
		fread(&temp, sizeof(Snake), 1, db);
	}
	fclose(db);
}

void show_data_from_container(array_t *p)
{
		Snake *first;
		first = arr_beg(p);
		head = (Snake*)malloc(sizeof(Snake));
		head->x = first->x;
		head->y = first->y;
		q = head;
	for (first = arr_beg(p); first < arr_end(p); first++)
	{
		
		q->x = (*first).x;
		q->y = (*first).y;
		Pos((*first).x, (*first).y);
		printf("��");
		score = score + add;
		q->next = (Snake*)malloc(sizeof(Snake));
		if (first == arr_end(p) - 1)
		{
			q->next = 0x00000000;
			break;
		}
		q = q->next;
		
	}
	score = score - 40;
}

