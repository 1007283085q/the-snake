#pragma once
#ifndef FS_H
#define FS_H


#include <stdio.h>
#include "array.h"

static FILE *db = NULL;

void save_data(array_t *p);
void load_data_to_screen();

void load_data_to_container(array_t *p);
void show_data_from_container(array_t *p);

#endif