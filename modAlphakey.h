/// @file modAlphakey.h
/// @brief Описание класса modAlphakey.

#pragma once
#include <vector>
#include <string>
#include <stdexcept>

/// @class modAlphakey
/// @brief Класс для шифрования и расшифровки текста методом табличной маршрутной перестановки.
class modAlphakey {
private:
    int key1; ///< Ключ для шифрования.

public:
    /// @brief Удалённый конструктор по умолчанию.
    modAlphakey() = delete;

    /// @brief Конструктор класса.
    /// @param key Целочисленный ключ для шифрования и расшифровки.
    modAlphakey(const int& key) {
        if (key <= 0) {
            throw std::invalid_argument("Key must be greater than 0.");
        }
        key1 = key;
    }

    /// @brief Шифрует текст.
    /// @param open_text Исходный текст.
    /// @return Зашифрованный текст.
    std::string encrypt(const std::string& open_text);

    /// @brief Расшифровывает текст.
    /// @param cipher_text Зашифрованный текст.
    /// @return Расшифрованный текст.
    std::string decrypt(const std::string& cipher_text);
};

