// gcc -o extended_test extended_test.c stribog.c
// ./extended_test
#include <stdio.h>
#include <string.h>
#include "stribog.h"

void print_hex(const char* label, const unsigned char* data, size_t len) {
    printf("%s: ", label);
    for(size_t i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

void test_string(const char* test_name, const char* message, unsigned long long length_bits) {
    unsigned char hash[64];
    
    printf("\n=== %s ===\n", test_name);
    printf("Сообщение: '%s'\n", message);
    printf("Длина: %lld бит\n", length_bits);
    
    hash_512((unsigned char*)message, length_bits, hash);
    print_hex("Хеш (512 бит)", hash, 64);
}

int main() {
    // Тест с пустой строкой
    test_string("Пустая строка", "", 0);
    
    // Тест с короткой строкой
    test_string("Короткая строка", "abc", 24);
    
    // Тест с длинной строкой
    test_string("Длинная строка", "Hello, Stribog! This is a kafedra 304!", 312);
    
    return 0;
}