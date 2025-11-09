// lib.h

#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <cstdio> // Используем C-функции для работы с файлами

// --- Наборы русских букв ---
// Объявление внешних констант, определенных в lib.cpp
extern const char RUS_VOWELS[];
extern const char RUS_CONSONANTS[];

// --- Объявления функций ---

// 1. Вспомогательная функция для проверки наличия символа в наборе
int is_char_in_set(char c, const char* set);

// 2. Основная функция для подсчета букв
void count_russian_letters(const char* text);

// 3. Функция для чтения файла в буфер
const int MAX_TEXT_SIZE = 1000; // Максимальный размер буфера
int read_file_to_buffer(const char* filename, char* buffer, int max_size);


#endif // LIB_H
