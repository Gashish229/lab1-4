#ifndef BITRGBLED_H
#define BITRGBLED_H

// Структура пикселя. Указываем точное количество бит для экономии памяти.
typedef struct {
    unsigned int red : 8;        // Красный цвет (от 0 до 255)
    unsigned int blue : 8;       // Синий цвет
    unsigned int green : 8;      // Зеленый цвет
    unsigned int brightness : 7; // Яркость (от 0 до 100)
    unsigned int temp : 14;      // Температура цвета
    unsigned int module_type: 4; // Тип модуля управления
    unsigned int mode : 2;       // Режим: 0-свечение, 1-мерцание, 2-затухание
} rgbled;

// Функции для работы с пикселем (конструктор и деструктор)
rgbled* create_pixel(unsigned int r, unsigned int g, unsigned int b, unsigned int mode);
void free_pixel(rgbled* p);

#endif
