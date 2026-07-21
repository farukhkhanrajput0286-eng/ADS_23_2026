#include <iostream>
using namespace std;

int main()
{
    int arr[10];

    cout << "Enter 10 elements: ";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    cout << "\nElement\tAddress\n";

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << "\t" << &arr[i] << endl;
    }

    return 0;
}