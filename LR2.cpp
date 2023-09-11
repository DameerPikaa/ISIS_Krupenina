#include <iostream>
#include <vector>

// Функция для выполнения циклического сдвига массива вправо на n элементов
void cyclicRightShift(std::vector<int>& arr, int n) {
    int size = arr.size();
    n %= size;  // Убедимся, что n не превышает размер массива
    std::vector<int> temp(size);
    for (int i = 0; i < size; i++) {
        temp[(i + n) % size] = arr[i];
    }
    arr = temp;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> Bitstring1(n);
    std::vector<int> Bitstring2(n);

    for (int i = 0; i < n; i++) {
        std::cin >> Bitstring1[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> Bitstring2[i];
    }
    std::cout << "Bitstring1 = ";
    for (int i = 0; i < n; i++) {
        std::cout << Bitstring1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "not Bitstring1 = ";
    for (int i = 0; i < n; i++) {
        std::cout << !Bitstring1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Bitstring2 = ";
    for (int i = 0; i < n; i++) {
        std::cout << Bitstring2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "not Bitstring2 = ";
    for (int i = 0; i < n; i++) {
        std::cout << !Bitstring2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Bitstring1 or Bitstring2 = ";
    for (int i = 0; i < n; i++) {
        std::cout << (Bitstring1[i] | Bitstring2[i]) << " ";
    }
    std::cout << std::endl;

    std::cout << "Bitstring1 xor Bitstring2 = ";
    for (int i = 0; i < n; i++) {
        std::cout << (Bitstring1[i] ^ Bitstring2[i]) << " ";
    }
    std::cout << std::endl;

    std::cout << "Bitstring1 and Bitstring2 = ";
    for (int i = 0; i < n; i++) {
        std::cout << (Bitstring1[i] & Bitstring2[i]) << " ";
    }
    std::cout << std::endl;

    int choice;
    while (true) {
        std::cin >> choice;
        if (choice == 0) {
            break;
        }
        switch (choice) {
            case 1: {
                int shift;
                std::cin >> shift;
                cyclicRightShift(Bitstring1, shift);
                std::cout << "cycle sdvig " << shift << " Bitstring1" << std::endl;
                break;
            }
            case 2: {
                int shift;
                std::cin >> shift;
                cyclicRightShift(Bitstring2, shift);
                std::cout << "cycle sdvig " << shift << " Bitstring2" << std::endl;
                break;
            }
            default:
                break;
        }

        std::cout << "Bitstring1 = ";
        for (int i = 0; i < n; i++) {
            std::cout << Bitstring1[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "not Bitstring1 = ";
        for (int i = 0; i < n; i++) {
            std::cout << !Bitstring1[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Bitstring2 = ";
        for (int i = 0; i < n; i++) {
            std::cout << Bitstring2[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "not Bitstring2 = ";
        for (int i = 0; i < n; i++) {
            std::cout << !Bitstring2[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Bitstring1 or Bitstring2 = ";
        for (int i = 0; i < n; i++) {
            std::cout << (Bitstring1[i] | Bitstring2[i]) << " ";
        }
        std::cout << std::endl;

        std::cout << "Bitstring1 xor Bitstring2 = ";
        for (int i = 0; i < n; i++) {
            std::cout << (Bitstring1[i] ^ Bitstring2[i]) << " ";
        }
        std::cout << std::endl;

        std::cout << "Bitstring1 and Bitstring2 = ";
        for (int i = 0; i < n; i++) {
            std::cout << (Bitstring1[i] & Bitstring2[i]) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
