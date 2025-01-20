#include <iostream>

// Функция для слияния двух массивов
int* mergeTwoArrays(int* arr1, int size1, int* arr2, int size2) {
    int* result = new int[size1 + size2]; // Создаем новый массив нужного размера

    // Копируем элементы из первого массива
    for (int i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }

    // Копируем элементы из второго массива
    for (int i = 0; i < size2; i++) {
        result[size1 + i] = arr2[i];
    }

    return result;
}

// Функция для поиска массива с наибольшей суммой
int* arrayWithMaxSum(int* arr1, int size1, int* arr2, int size2) {
    int sum1 = 0, sum2 = 0;

    // Считаем сумму первого массива
    for (int i = 0; i < size1; i++) {
        sum1 += arr1[i];
    }

    // Считаем сумму второго массива
    for (int i = 0; i < size2; i++) {
        sum2 += arr2[i];
    }

    // Возвращаем указатель на массив с большей суммой
    return (sum1 >= sum2) ? arr1 : arr2;
}

// Пример использования

int main() {
    // Создаем тестовые массивы
    int size1 = 3, size2 = 4;
    int* arr1 = new int[size1] {1, 2, 3};
    int* arr2 = new int[size2] {4, 5, 6, 7};

    // Тестируем первую функцию
    int* merged = mergeTwoArrays(arr1, size1, arr2, size2);
    std::cout << "Merged Array: ";
    for (int i = 0; i < size1 + size2; i++) {
        std::cout << merged[i] << " ";
    }
    std::cout << "\n";

    // Тестируем вторую функцию
    int* maxSumArray = arrayWithMaxSum(arr1, size1, arr2, size2);
    std::cout << "Array with the largest sum: ";
    for (int i = 0; i < (maxSumArray == arr1 ? size1 : size2); i++) {
        std::cout << maxSumArray[i] << " ";
    }
    std::cout << "\n";

    // Освобождаем память
    delete[] arr1;
    delete[] arr2;
    delete[] merged;

    return 0;
}
