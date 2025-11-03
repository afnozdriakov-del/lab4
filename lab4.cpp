#include <iostream>
#include <cmath>
using namespace std;

// ========================================================
// ПРОТОТИПИ ФУНКЦІЙ / ПРОЦЕДУР (оголошення перед main)
// ========================================================

// Proc2: обчислення другої, третьої та четвертої степені числа
// A - вхідне число, B,C,D - вихідні параметри (степені числа)
void PowerA234(double A, double &B, double &C, double &D);
void Task_Proc2(); // Процедура для виконання завдання Proc2

// Proc28: обчислення площі кола
double CircleS(double R); // R - радіус кола
void Task_Proc28();       // Процедура для виконання завдання Proc28

// Integer3: кількість повних Гбайт та Мбайт до наступного
int inputFileSize();                       // Введення розміру файлу в МБ
void calcFileSize(int sizeMB, int &fullGB, int &restMB); // Обчислення
void outputResult(int fullGB, int restMB);                // Виведення результату
void Task_Integer3();                      // Процедура для виконання завдання Integer3

// Допоміжна функція для перевірки діапазону [-100,100]
double inputNumberInRange(const string &prompt); // Вводимо число та перевіряємо діапазон

// ========================================================
// Головна функція з меню
// ========================================================
int main() {
    int choice; // Змінна для вибору пункту меню

    do {
        // Виводимо меню на екран
        cout << "\n=============================\n";
        cout << "             М Е Н Ю\n";
        cout << "=============================\n";
        cout << "1 – Proc2 (PowerA234)\n";
        cout << "2 – Proc28 (CircleS)\n";
        cout << "3 – Integer3 (ГБ і МБ)\n";
        cout << "4 – Вихід\n";
        cout << "=============================\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        // Обробка вибору користувача
        switch (choice) {
            case 1:
                Task_Proc2(); // Виконуємо Proc2
                break;
            case 2:
                Task_Proc28(); // Виконуємо Proc28
                break;
            case 3:
                Task_Integer3(); // Виконуємо Integer3
                break;
            case 4:
                cout << "\nПрограму завершено. До побачення!\n";
                break;
            default:
                cout << "Помилка! Введіть число від 1 до 4.\n";
        }
    } while (choice != 4); // Повертаємося до меню, поки не вибрали "Вихід"

    return 0; // Завершення програми
}

// ========================================================
// ВИЗНАЧЕННЯ ФУНКЦІЙ / ПРОЦЕДУР (після main)
// ========================================================

// ==================== Допоміжна функція =================
// Введення числа та перевірка, щоб воно було в діапазоні [-100,100]
double inputNumberInRange(const string &prompt) {
    double num;
    do {
        cout << prompt;
        while (!(cin >> num)) { // Перевірка на коректність введення
            cout << "Помилка! Введіть число ще раз: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        if (num < -100 || num > 100) {
            cout << "Число повинно бути в діапазоні [-100, 100].\n";
        }
    } while (num < -100 || num > 100);
    return num;
}

// ==================== Proc2 ===========================
// Обчислення другої, третьої та четвертої степені числа
void PowerA234(double A, double &B, double &C, double &D) {
    B = pow(A, 2); // Квадрат числа
    C = pow(A, 3); // Куб числа
    D = pow(A, 4); // Четверта степінь числа
}

// Виконання завдання Proc2
void Task_Proc2() {
    cout << "\n=== Proc2: PowerA234 ===" << endl;
    double a, b, c, d;

    // Вводимо 5 чисел та обчислюємо їх степені
    for (int i = 1; i <= 5; ++i) {
        a = inputNumberInRange("Введіть число " + to_string(i) + " ([-100,100]): ");
        PowerA234(a, b, c, d); // Виклик процедури PowerA234
        cout << "A^2=" << b << ", A^3=" << c << ", A^4=" << d << endl;
    }
}

// ==================== Proc28 ==========================
// Обчислення площі кола
double CircleS(double R) {
    const double PI = 3.14; // Значення числа π
    return PI * R * R;       // Формула площі кола S = π*R^2
}

// Виконання завдання Proc28
void Task_Proc28() {
    cout << "\n=== Proc28: CircleS ===" << endl;

    // Вводимо три радіуси з перевіркою діапазону
    double r1 = inputNumberInRange("Введіть радіус 1 ([-100,100]): ");
    double r2 = inputNumberInRange("Введіть радіус 2 ([-100,100]): ");
    double r3 = inputNumberInRange("Введіть радіус 3 ([-100,100]): ");

    // Обчислюємо та виводимо площі
    cout << "Площа кола з радіусом " << r1 << " = " << CircleS(r1) << endl;
    cout << "Площа кола з радіусом " << r2 << " = " << CircleS(r2) << endl;
    cout << "Площа кола з радіусом " << r3 << " = " << CircleS(r3) << endl;
}

// ==================== Integer3 ========================
// Введення розміру файлу у Мбайтах
int inputFileSize() {
    int sizeMB;
    cout << "Введіть розмір файлу (у Мбайтах): ";
    while (!(cin >> sizeMB) || sizeMB < 0) {
        cout << "Помилка! Введіть додатне ціле число: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return sizeMB;
}

// Обчислення кількості повних Гбайт та залишку Мбайт
void calcFileSize(int sizeMB, int &fullGB, int &restMB) {
    fullGB = sizeMB / 1024;    // Цілочисельне ділення на 1024
    restMB = sizeMB % 1024;    // Залишок Мбайт до наступного ГБ
}

// Виведення результату для Integer3
void outputResult(int fullGB, int restMB) {
    cout << "\nРезультат:" << endl;
    cout << "Повних Гбайт: " << fullGB << endl;
    cout << "Мбайт до наступного Гбайта: " << (1024 - restMB) % 1024 << endl;
}

// Виконання завдання Integer3
void Task_Integer3() {
    cout << "\n=== Integer3: ГБ і МБ ===" << endl;
    int sizeMB, fullGB, restMB;

    sizeMB = inputFileSize();          // Введення розміру файлу
    calcFileSize(sizeMB, fullGB, restMB); // Обчислення
    outputResult(fullGB, restMB);         // Виведення
}
