#include <iostream>
#include <fstream>
#include <ctime>
#include <format>
#include <string>
#include <filesystem>
#include <time.h>
#include <nlohmann/json.hpp>


void create_dirs() {
    std::filesystem::path results_folder_path = "D:\\Университет\\ПарПрог\\lab1\\matrix\\matrix\\results";
    std::filesystem::path result_matrix_folder_path = "D:\\Университет\\ПарПрог\\lab1\\matrix\\matrix\\results\\result_matrix";
    std::filesystem::path result_computings_folder_path = "D:\\Университет\\ПарПрог\\lab1\\matrix\\matrix\\results\\result_computings";
    std::filesystem::path data_folder_path = "D:\\Университет\\ПарПрог\\lab1\\matrix\\matrix\\data";

    if (!std::filesystem::exists(results_folder_path) || !std::filesystem::is_directory(results_folder_path)) {
        std::filesystem::create_directories(results_folder_path);
    }

    if (!std::filesystem::exists(data_folder_path) || !std::filesystem::is_directory(data_folder_path)) {
        std::filesystem::create_directories(data_folder_path);
    }

    if (!std::filesystem::exists(result_matrix_folder_path) || !std::filesystem::is_directory(result_matrix_folder_path)) {
        std::filesystem::create_directories(result_matrix_folder_path);
    }

    if (!std::filesystem::exists(result_computings_folder_path) || !std::filesystem::is_directory(result_computings_folder_path)) {
        std::filesystem::create_directories(result_computings_folder_path);
    }
}

void save_to_json(std::string file_name, double time, int size) {
    nlohmann::json data;

    data["time"] = time;
    data["size"] = size;


    std::ofstream file(file_name);
    if (file.is_open()) {
        file << data.dump(4);
        file.close();
    }

    std::cout << "JSON файл успешно создан и заполнен!\n";

}

int** create_matrix(int size) {
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 300;
       }
    }
    return matrix;
}

void write_matrix_to_file(std::string file_name, int** matrix, int size) {
    std::ofstream file(file_name);
    if (file.is_open()) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file << matrix[i][j] << " ";
            }
            file << std::endl;
        }
        file.close();
        std::cout << "Matrix has been written to file." << std::endl;
    }
}

int** matrix_multiplication(int** first_matrix, int** second_matrix, int size, double& time) {
    int** result_matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        result_matrix[i] = new int[size];
    }

    clock_t start = clock();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result_matrix[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result_matrix[i][j] += first_matrix[i][k] * second_matrix[k][j];
            }
        }
    }
    clock_t end = clock();

    time = (double)(end - start) / CLOCKS_PER_SEC;
    return result_matrix;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    create_dirs();

    int size = 20;
    int** m1 = create_matrix(size);
    int** m2 = create_matrix(size);
    double time;

    int** res = matrix_multiplication(m1, m2, size, time);
    std::cout << "Первая матрица:" << std::endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << m1[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n\nВторая матрица:" << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << m2[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n\nРезультирующая матрица:" << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Время выполнения перемножения матриц: " << time << " seconds" << std::endl;

    save_to_json(std::format("results/result_matrix/result_{}.json", size), time, size);
    write_matrix_to_file(std::format("results/result_computings/result_{}.txt", size), res, size);

    //int sizes[7] = { 100, 500, 1000, 1500, 2000, 3000, 4000 };
    //for (auto size : sizes) {
    //    for (int i = 1; i < 3; i++)
    //    {
    //        write_matrix(create_matrix(size), size, "matrix_" + std::to_string(size) + "_" + std::to_string(i) + ".txt");
    //    }
    //}
}