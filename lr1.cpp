#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    //Введите размерность исходного массива
    cin >> n;

    vector<double> arr(n);

    //Введите элементы массива
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Вывод исходного массива
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(3) << arr[i] << " ";
    }
    cout << endl;

    // Добавление суммы и среднего арифметического
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    arr.push_back(sum);
    arr.push_back(sum / n);

    // Вывод массива после добавления
    for (int i = 0; i < arr.size(); i++) {
        cout << fixed << setprecision(3) << arr[i] << " ";
    }
    cout << endl;

    //нечетное
    double nech = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (static_cast<int>(abs(arr[i])) % 2 == 1) {
        nech = arr[i];
        break;
        }
    }
    

    for (int i = 0; i < arr.size(); i++) {
            arr[i] += nech;
        }

    // Вывод массива после выполнения операции
    for (int i = 0; i < arr.size(); i++) {
        cout << fixed << setprecision(3) << arr[i] << " ";
    }
    cout << endl;

    int choice;
    //Выберите действие (1 - добавить элемент, 2 - удалить элемент, 0 - выход)
    cin >> choice;

    while (choice != 0) {
        if (choice == 1) {
            double newElement;
            //Введите элемент для добавления
            cin >> newElement;
            arr.push_back(newElement);
            cout << "+: " << arr.size() << endl;
        }
        else if (choice == 2) {
            if (!arr.empty()) {
                arr.pop_back();
                cout << "-: " << arr.size() << endl;
            }
            else {
                //cout << "Массив пустой, невозможно удалить элемент." << endl;
            }
        }

        // Вывод массива после выполнения операции
        for (int i = 0; i < arr.size(); i++) {
            cout << fixed << setprecision(3) << arr[i] << " ";
        }
        cout << endl;

        // Добавление суммы и среднего арифметического
        sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }
        arr.push_back(sum);
        arr.push_back(sum / (arr.size()-1));

        // Вывод массива после выполнения операции
        for (int i = 0; i < arr.size(); i++) {
            cout << fixed << setprecision(3) << arr[i] << " ";
        }
        cout << endl;

        nech = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (static_cast<int>(abs(arr[i])) % 2 == 1) {
                nech = arr[i];
                break;
            }
        }
    

        for (int i = 0; i < arr.size(); i++) {
            arr[i] += nech;
        }        

        // Вывод массива после выполнения операции
        for (int i = 0; i < arr.size(); i++) {
            cout << fixed << setprecision(3) << arr[i] << " ";
        }
        cout << endl;

        //cout << "Выберите действие (1 - добавить элемент, 2 - удалить элемент, 0 - выход): ";
        cin >> choice;
    }

    return 0;
}