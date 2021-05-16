#include <iostream>
#include <windows.h>
using namespace std;

void PrintString(char** arr, int n)
{
    cout << endl << "Вывод массива строк: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". ";
        for (int j = 0; j < 100; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

void DeletionString(char**& arr, int& n, int k)
{
    n = n - k;
    char** stringArray2 = new char* [n]();
    for (int i = 0; i < n; i++)
    {
        stringArray2[i] = arr[i + k];
    }
    arr = stringArray2;
    stringArray2 = nullptr;
}

int main()
{
    system("color F0");
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    do
    {
        cout << "Введите кол-во строк: ";
        cin >> n;
    } while (n < 1);

    char** stringArray = new char* [n]();
    for (int i = 0; i < n; i++)
    {
        stringArray[i] = new char[100]();
    }
    cout << "Введите строки " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> stringArray[i];
    }
    PrintString(stringArray, n);

    int k;
    do
    {
        cout << "Введите номер строки по которую необходимо удалить строки: ";
        cin >> k;
    } while (k < 0 || k > n);
    
    DeletionString(stringArray, n, k);
    PrintString(stringArray, n);

    for (int i = 0; i < n; i++) 
    {
        delete[] stringArray[i];
    }
    delete[] stringArray;
    return 0;
}