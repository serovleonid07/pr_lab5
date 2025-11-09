// lib.cpp

#include "Lib.h"
#include <iostream>

// --- Определение внешних констант ---
const char RUS_VOWELS[] = "АаЕеЁёИиОоУуЫыЭэЮюЯя";
const char RUS_CONSONANTS[] = "БбВвГгДдЖжЗзКкЛлМмНнПпРрСсТтФфХхЦцЧчШшЩщ";

// 1. Вспомогательная функция для проверки наличия символа в наборе
int is_char_in_set(char c, const char* set) {
    // Проходим по массиву, пока не встретим нулевой символ ('\0')
    for (int i = 0; set[i] != '\0'; ++i) {
        if (c == set[i]) {
            return 1;
        }
    }
    return 0;
}

// 2. Основная функция для подсчета букв
void count_russian_letters(const char* text) {
    int vowel_count = 0;
    int consonant_count = 0;

    // Проход по входной строке
    for (int i = 0; text[i] != '\0'; ++i) {
        char current_char = text[i];

        if (is_char_in_set(current_char, RUS_VOWELS)) {
            vowel_count++;
        }
        else if (is_char_in_set(current_char, RUS_CONSONANTS)) {
            consonant_count++;
        }
    }

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Результат анализа текста:" << std::endl;
    std::cout << "Гласных букв: " << vowel_count << std::endl;
    std::cout << "Согласных букв: " << consonant_count << std::endl;
    std::cout << "Общее количество учтенных букв: " << (vowel_count + consonant_count) << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
}

// 3. Функция для чтения файла в буфер
int read_file_to_buffer(const char* filename, char* buffer, int max_size) {
    FILE* file;

    // Возвращает 0 в случае успеха.
    errno_t err = fopen_s(&file, filename, "rb");

    if (err != 0 || file == NULL) {
        return 0; // Ошибка открытия файла
    }

    // Читаем данные: размер элемента 1 байт, max_size-1 элементов
    size_t bytes_read = fread(buffer, 1, max_size - 1, file);

    fclose(file);

    // Обеспечиваем нулевой терминатор для создания корректной C-строки
    buffer[bytes_read] = '\0';

    return 1; // Успешно
}
