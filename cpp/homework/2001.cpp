#include <iostream>

// Функция для проверки симметричности матрицы
bool isSymmetric(int** matrix, int size) {
    // Проверяем элементы выше и ниже главной диагонали
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

// Функция для сравнения двух матриц
bool areMatricesEqual(int** matrix1, int** matrix2, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Вспомогательная функция для создания двумерного массива
int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

// Вспомогательная функция для освобождения памяти
void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    // Тест на симметричность
    int size = 3;
    int** symmetricMatrix = createMatrix(size, size);
    
    // Заполняем симметричную матрицу
    symmetricMatrix[0][0] = 1; symmetricMatrix[0][1] = 2; symmetricMatrix[0][2] = 3;
    symmetricMatrix[1][0] = 2; symmetricMatrix[1][1] = 4; symmetricMatrix[1][2] = 5;
    symmetricMatrix[2][0] = 3; symmetricMatrix[2][1] = 5; symmetricMatrix[2][2] = 6;
    
    std::cout << "Первая матрица:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << symmetricMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    if (isSymmetric(symmetricMatrix, size)) {
        std::cout << "Матрица симметрична\n";
    } else {
        std::cout << "Матрица не симметрична\n";
    }
    
    // Тест на равенство матриц
    int** matrix1 = createMatrix(2, 2);
    int** matrix2 = createMatrix(2, 2);
    
    // Заполняем первую матрицу
    matrix1[0][0] = 1; matrix1[0][1] = 2;
    matrix1[1][0] = 3; matrix1[1][1] = 4;
    
    // Заполняем вторую матрицу
    matrix2[0][0] = 1; matrix2[0][1] = 2;
    matrix2[1][0] = 3; matrix2[1][1] = 4;
    
    std::cout << "\nСравнение двух матриц 2x2:\n";
    if (areMatricesEqual(matrix1, matrix2, 2, 2)) {
        std::cout << "Матрицы равны\n";
    } else {
        std::cout << "Матрицы не равны\n";
    }
    
    // Освобождаем память
    deleteMatrix(symmetricMatrix, size);
    deleteMatrix(matrix1, 2);
    deleteMatrix(matrix2, 2);
    
    return 0;
}
