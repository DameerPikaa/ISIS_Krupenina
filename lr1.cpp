#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

int main() {
    int n;
    //Введите размерность исходного массива
    std::cin >> n;

    std::vector<double> arr(n);

    //Введите элементы массива
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // Вывод исходного массива
    std::cout << n << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << std::fixed << std::setprecision(3) << arr[i] << " ";
    }
    std::cout << std::endl;

    // Добавление суммы и среднего арифметического
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    arr.push_back(sum);
    arr.push_back(sum / n);

    // Вывод массива после добавления
    for (int i = 0; i < arr.size(); i++) {
        std::cout << std::fixed << std::setprecision(3) << arr[i] << " ";
    }
    std::cout << std::endl;

    //нечетное
    double nech = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (static_cast<int>(std::abs(arr[i])) % 2 == 1) {
            nech = arr[i];
            break;
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] += nech;
    }

    // Вывод массива после выполнения операции
    for (int i = 0; i < arr.size(); i++) {
        std::cout << std::fixed << std::setprecision(3) << arr[i] << " ";
    }
    std::cout << std::endl;

    int choice;
    //Выберите действие (1 - добавить элемент, 2 - удалить элемент, 0 - выход)
    std::cin >> choice;

    while (choice != 0) {
        if (choice == 1) {
            double newElement;
            //Введите элемент для добавления
            std::cin >> newElement;
            arr.push_back(newElement);
            std::cout << "+: " << arr.size() << std::endl;
        }
        else if (choice == 2) {
            if (!arr.empty()) {
                arr.pop_back();
                std::cout << "-: " << arr.size() << std::endl;
            }
            else {
                //std::cout << "Массив пустой, невозможно удалить элемент." << std::endl;
            }
        }

        // Вывод массива после выполнения операции
        for (int i = 0; i < arr.size(); i++) {
            std::cout << std::fixed << std::setprecision(3) << arr[i] << " ";
        }
        std::cout << std::endl;

        // Добавление суммы и среднего арифметического
        sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }
        arr.push_back(sum);
        arr.push_back(sum / (arr.size() - 1));

        // Вывод массива после выполнения операции
        for (int i = 0; i < arr.size(); i++) {
            std::cout << std::fixed << std::setprecision(3) << arr[i] << " ";
        }
        std::cout << std::endl;

        nech = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (static_cast<int>(std::abs(arr[i])) % 2 == 1) {
                nech = arr[i];
                break;
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] += nech;
        }

        // Вывод массива после выполнения операции
        for (int i = 0; i < arr.size(); i++) {
            std::cout << std::fixed << std::setprecision(3) << arr[i] << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;

        //std::cout << "Выберите действие (1 - добавить элемент, 2 - удалить элемент, 0 - выход): ";
        std::cin >> choice;
    }

    return 0;
}
