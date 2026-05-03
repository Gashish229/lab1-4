#include "fiostruct.h"

// Генерируем массив из n случайных матриц
matrix2d** rand_gen_struct(size_t n) {
    matrix2d** arr = (matrix2d**)malloc(n * sizeof(matrix2d*));
    for(size_t i = 0; i < n; i++) {
        arr[i] = create_matrix(2, 2); // Делаем размер 2x2
        fill_random(arr[i]);
    }
    return arr;
}

// Сохранение в текстовый файл
void save_text(const char* filename, matrix2d** arr, size_t n) {
    FILE* f = fopen(filename, "w"); // Открываем для записи
    if (!f) return;
    
    fprintf(f, "%zu\n", n); // Первой строкой пишем количество объектов
    
    for (size_t i = 0; i < n; i++) {
        fprintf(f, "%d %d\n", arr[i]->rows, arr[i]->cols); // Размеры матрицы
        for(int r = 0; r < arr[i]->rows; r++) {
            for(int c = 0; c < arr[i]->cols; c++) {
                // Пишем цвета RGB
                fprintf(f, "%d %d %d ", 
                        arr[i]->data[r][c].red, 
                        arr[i]->data[r][c].green, 
                        arr[i]->data[r][c].blue);
            }
        }
        fprintf(f, "\n"); // Разделяем матрицы пустой строкой
    }
    fclose(f);
}

// Извлечение i-того объекта без полной загрузки файла в память
matrix2d* get_element_from_text_file(const char* filename, int index) {
    FILE* f = fopen(filename, "r"); // Открываем для чтения
    if (!f) return NULL;
    
    size_t total;
    if (fscanf(f, "%zu", &total) != 1 || index < 0 || index >= total) { 
        fclose(f); 
        return NULL; // Индекс за границами
    }
    
    int rows, cols;
    for (int i = 0; i <= index; i++) {
        fscanf(f, "%d %d", &rows, &cols);
        
        // Если дошли до нужного номера
        if (i == index) {
            matrix2d* m = create_matrix(rows, cols);
            int red, green, blue;
            for(int r = 0; r < rows; r++) {
                for(int c = 0; c < cols; c++) {
                    fscanf(f, "%d %d %d", &red, &green, &blue);
                    m->data[r][c].red = red;
                    m->data[r][c].green = green;
                    m->data[r][c].blue = blue;
                }
            }
            fclose(f);
            return m; // Возвращаем найденную матрицу
        } else {
            // Если индекс не тот, просто проматываем значения (skip)
            int temp;
            for(int k = 0; k < rows * cols * 3; k++) fscanf(f, "%d", &temp);
        }
    }
    fclose(f);
    return NULL;
}

// Вывод количества сохраненных элементов
void list_file(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("Файл не найден.\n");
        return;
    }
    size_t total;
    fscanf(f, "%zu", &total);
    printf("Файл '%s' содержит структур: %zu\n", filename, total);
    // Для экономии времени выводим только количество
    fclose(f);
}
