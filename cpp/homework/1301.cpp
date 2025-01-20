#include <iostream>

// Функция для сортировки массива по возрастанию (используем метод пузырька)
void sortArray(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Меняем элементы местами
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функция для вычисления среднего арифметического
double calculateAverage(int* arr, int size) {
    if (size == 0) {
        return 0.0; // Защита от деления на ноль
    }

    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum / size;
}

// Пример использования
int main() {
    // Создаем тестовый массив
    int size = 5;
    int* arr = new int[size] {5, 2, 8, 1, 9};

    // Выводим исходный массив
    std::cout << "Initial Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    // Сортируем массив
    sortArray(arr, size);

    // Выводим отсортированный массив
    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    // Вычисляем и выводим среднее арифметическое
    double average = calculateAverage(arr, size);
    std::cout << "Average: " << average << "\n";

    // Освобождаем память
    delete[] arr;

    return 0;
}
