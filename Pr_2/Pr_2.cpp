#include <iostream>
#include <windows.h> // Для SetConsoleCP та SetConsoleOutputCP
#include <cstring>

class Tovar {
private:
    char* nazva;
    int kilkist;
    float vartist;

public:
    // Конструктор без параметрів
    Tovar() {
        nazva = new char[1];
        nazva[0] = '\0';
        kilkist = 0;
        vartist = 0.0;
    }

    // Конструктор з параметрами
    Tovar(const char* n, int k, float v) {
        nazva = new char[strlen(n) + 1];
        strcpy_s(nazva, strlen(n) + 1, n);
        kilkist = k;
        vartist = v;
    }

    // Конструктор копіювання
    Tovar(const Tovar& other) {
        nazva = new char[strlen(other.nazva) + 1];
        strcpy_s(nazva, strlen(other.nazva) + 1, other.nazva);
        kilkist = other.kilkist;
        vartist = other.vartist;
    }

    // Деструктор
    ~Tovar() {
        delete[] nazva;
    }

    // Введення назви товару
    void setNazva(const char* n) {
        delete[] nazva;
        nazva = new char[strlen(n) + 1];
        strcpy_s(nazva, strlen(n) + 1, n);
    }

    // Зміна кількості товару
    void setKilkist(int k) {
        kilkist = k;
    }

    // Зміна вартості товару
    void setVartist(float v) {
        vartist = v;
    }

    // Виведення інформації про об’єкт
    void printInfo() const {
        std::cout << "Назва: " << nazva << ", Кількість: " << kilkist << ", Вартість: " << vartist << " грн" << std::endl;
    }
};

int main() {
    // Встановлення кодування для коректного виводу українських символів у Windows
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Створення об'єктів
    Tovar t1;
    Tovar t2("Молоко", 10, 32.5);
    Tovar t3 ("Кава", 5, 50.0);
    ;

    // Демонстрація роботи методів
    t1.setNazva("Хліб");
    t1.setKilkist(5);
    t1.setVartist(15.0);

    std::cout << "Об'єкти товарів:\n";
    t1.printInfo();
    t2.printInfo();
    t3.printInfo();

    return 0;
}

