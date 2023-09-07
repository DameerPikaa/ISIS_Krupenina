#include <iostream>
#include <vector>

using namespace std;

// Функция для выполнения циклического сдвига массива вправо на n элементов
void cyclicRightShift(vector<int>& arr, int n) {
    int size = arr.size();
    n %= size;  // Убедимся, что n не превышает размер массива
    vector<int> temp(size);
    for (int i = 0; i < size; i++) {
        temp[(i + n) % size] = arr[i];
    }
    arr = temp;
}

int main() {
    int n;
    cin >> n;
    vector<int> Bitstring1(n);
    vector<int> Bitstring2(n);

    for (int i = 0; i < n; i++) {
        cin >> Bitstring1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> Bitstring2[i];
    }
    cout << "Bitstring1 = ";
        for (int i = 0; i < n; i++) {
            cout << Bitstring1[i] << " ";
        }
        cout << endl;

        cout << "not Bitstring1 = ";
        for (int i = 0; i < n; i++) {
            cout << !Bitstring1[i] << " ";
        }
        cout << endl;

        cout << "Bitstring2 = ";
        for (int i = 0; i < n; i++) {
            cout << Bitstring2[i] << " ";
        }
        cout << endl;

        cout << "not Bitstring2 = ";
        for (int i = 0; i < n; i++) {
            cout << !Bitstring2[i] << " ";
        }
        cout << endl;

        cout << "Bitstring1 or Bitstring2 = ";
        for (int i = 0; i < n; i++) {
            cout << (Bitstring1[i] | Bitstring2[i]) << " ";
        }
        cout << endl;

        cout << "Bitstring1 xor Bitstring2 = ";
        for (int i = 0; i < n; i++) {
            cout << (Bitstring1[i] ^ Bitstring2[i]) << " ";
        }
        cout << endl;

        cout << "Bitstring1 and Bitstring2 = ";
        for (int i = 0; i < n; i++) {
            cout << (Bitstring1[i] & Bitstring2[i]) << " ";
        }
        cout << endl;

    int choice;
    while (true) {
        cin >> choice;
        if (choice == 0) {
            break;
        }
        switch (choice) {
            case 1: {
                int shift;
                cin >> shift;
                cyclicRightShift(Bitstring1, shift);
                cout << "cycle sdvig " << shift << " Bitstring1" << endl;
                break;
            }
            case 2: {
                int shift;
                cin >> shift;
                cyclicRightShift(Bitstring2, shift);
                cout << "cycle sdvig " << shift << " Bitstring2" << endl;
                break;
            }
            default:
                break;
        }

        cout << "Bitstring1 = ";
        for (int i = 0; i < n; i++) {
            cout << Bitstring1[i] << " ";
        }
        cout << endl;

        cout << "not Bitstring1 = ";
        for (int i = 0; i < n; i++) {
            cout << !Bitstring1[i] << " ";
        }
        cout << endl;

        cout << "Bitstring2 = ";
        for (int i = 0; i < n; i++) {
            cout << Bitstring2[i] << " ";
        }
        cout << endl;

        cout << "not Bitstring2 = ";
        for (int i = 0; i < n; i++) {
            cout << !Bitstring2[i] << " ";
        }
        cout << endl;

        cout << "Bitstring1 or Bitstring2 = ";
        for (int i = 0; i < n; i++) {
            cout << (Bitstring1[i] | Bitstring2[i]) << " ";
        }
        cout << endl;

        cout << "Bitstring1 xor Bitstring2 = ";
        for (int i = 0; i < n; i++) {
            cout << (Bitstring1[i] ^ Bitstring2[i]) << " ";
        }
        cout << endl;

        cout << "Bitstring1 and Bitstring2 = ";
        for (int i = 0; i < n; i++) {
            cout << (Bitstring1[i] & Bitstring2[i]) << " ";
        }
        cout << endl;
    }

    return 0;
}
