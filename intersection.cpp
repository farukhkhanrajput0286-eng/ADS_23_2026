#include <iostream>
using namespace std;

int main()
{
    int n1, n2;

    cout << "Enter size of first array: ";
    cin >> n1;

    int *arr1 = new int[n1];

    cout << "Enter elements of first sorted array:\n";
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> n2;

    int *arr2 = new int[n2];

    cout << "Enter elements of second sorted array:\n";
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    int i = 0;
    int j = 0;

    cout << "Intersection: ";

    while (i < n1 && j < n2)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    delete[] arr1;
    delete[] arr2;

    return 0;
}