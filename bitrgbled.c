#include "bitrgbled.h"
#include <stdlib.h>
#include <stdio.h> // Добавили для printf и scanf

// Выделяем память под один пиксель и заполняем его данными
rgbled* create_pixel(unsigned int r, unsigned int g, unsigned int b, unsigned int mode) {
    rgbled* pixel = (rgbled*)malloc(sizeof(rgbled));
    pixel->red = r;
    pixel->green = g;
    pixel->blue = b;
    pixel->brightness = 100; 
    pixel->temp = 6500;      
    pixel->module_type = 1;  
    pixel->mode = mode;      
    return pixel;
}

// Метод для ручного заполнения структуры (Требование Лабы №2)
void fill_pixel_manual(rgbled* p) {
    if (p == NULL) return;
    
    int r, g, b, mode;
    printf("Введите через пробел R, G, B (0-255) и Режим (0-2): ");
    scanf("%d %d %d %d", &r, &g, &b, &mode);
    
    // Безопасно присваиваем считанные int значения нашим битовым полям
    p->red = r;
    p->green = g;
    p->blue = b;
    p->mode = mode;
}

// Освобождаем память
void free_pixel(rgbled* p) {
    if (p != NULL) {
        free(p);
    }
}
