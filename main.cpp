/**
 * @mainpage Шифрование методом табличной маршрутной перестановки
 *
 * @section intro Введение
 * Программа реализует шифрование и расшифровку сообщений на английском языке при помощи метода табличной маршрутной перестановки.
 * Алгоритм разбивает текст на строки с длиной, равной ключу, и шифрует текст по столбцам.
 *
 * @section usage Использование
 * 1. Пользователь вводит целочисленный ключ.
 * 2. Выбирает операцию: зашифровка или расшифровка.
 * 3. Вводит текст для обработки.
 * Программа проверяет корректность введенных данных и выполняет выбранную операцию.
 *
 * @section files Состав проекта
 * - main.cpp: Главный файл программы.
 * - modAlphakey.cpp: Реализация методов шифрования и расшифровки.
 * - modAlphakey.h: Заголовочный файл с описанием класса modAlphakey.
 */

/// @file main.cpp
/// @brief Главный файл программы, реализующей шифрование и расшифровку текста методом табличной маршрутной перестановки.

#include "modAlphakey.h"
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

/// @brief Проверяет корректность строки.
/// @param s Входная строка.
/// @return true, если строка состоит только из заглавных букв английского алфавита.
bool isValid(const string& s) {
    for (auto c : s)
        if (!isalpha(c) || !isupper(c))
            return false;
    return true;
}

/// @brief Главная функция программы.
int main() {
    int key;
    string text;
    int op;

    cout << "Cipher ready. Input key: ";
    cin >> key;
    if (!cin.good()) {
        cerr << "key not valid\n";
        return 0;
    }

    modAlphakey cipher(key);
    do {
        cout << "Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        cin >> op;
        if (op > 2) {
            cout << "Illegal operation\n";
        } else if (op > 0) {
            cout << "Cipher ready. Input text: ";
            cin >> text;
            if (isValid(text)) {
                if (op == 1) {
                    cout << "Encrypted text: " << cipher.encrypt(text) << endl;
                } else {
                    cout << "Decrypted text: " << cipher.decrypt(text) << endl;
                }
            } else {
                cout << "Operation aborted: invalid text\n";
            }
        }
    } while (op != 0);

    return 0;
}
