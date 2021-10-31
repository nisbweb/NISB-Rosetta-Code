#include <iostream>
using namespace std;

void print(int *a, int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main()
{
    int *a, size, i, k, temp;
    cout << "Enter the array size" << endl;
    cin >> size;
    a = new int[size];
    cout << "Enter the elements" << endl;
    for (i = 0; i < size; i++)
        cin >> a[i];
    cout << "Before rotation" << endl;
    print(a, size);
    cout << "Enter how many times the array needs to be right-rotated" << endl;
    cin >> k;
    while (k != 0)
    {
        temp = a[size - 1];
        for (i = size - 1; i > 0; i--)
            a[i] = a[i - 1];
        a[i] = temp;
        k--;
    }
    cout << "Array after " << k << " right-rotation" << endl;
    print(a, size);
    return 0;
}