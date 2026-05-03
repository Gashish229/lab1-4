#include "bitrgbled.h"
#include <stdlib.h>

// Выделяем память под один пиксель и заполняем его данными
rgbled* create_pixel(unsigned int r, unsigned int g, unsigned int b, unsigned int mode) {
    rgbled* pixel = (rgbled*)malloc(sizeof(rgbled));
    pixel->red = r;
    pixel->green = g;
    pixel->blue = b;
    pixel->brightness = 100; // Яркость на максимум по умолчанию
    pixel->temp = 6500;      // Стандартный белый свет
    pixel->module_type = 1;  
    pixel->mode = mode;      
    return pixel;
}

// Освобождаем память
void free_pixel(rgbled* p) {
    if (p != NULL) {
        free(p);
    }
}
