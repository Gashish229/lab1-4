#ifndef FIOSTRUCT_H
#define FIOSTRUCT_H
#include "matrix2d.h"

// Функции для работы с файлами
matrix2d** rand_gen_struct(size_t n);
void save_text(const char* filename, matrix2d** arr, size_t n);
matrix2d* get_element_from_text_file(const char* filename, int index);
void list_file(const char* filename);

#endif
