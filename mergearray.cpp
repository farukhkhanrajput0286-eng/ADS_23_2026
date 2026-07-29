#include <iostream>
using namespace std;

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};

    int n1 = 4;
    int n2 = 4;

    int merged[8];

    int i = 0;
    int j = 0;
    int k = 0;

    // Compare both arrays
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            merged[k] = arr1[i];
            i++;
        }
        else
        {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of arr1
    while (i < n1)
    {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    // Copy remaining elements of arr2
    while (j < n2)
    {
        merged[k] = arr2[j];
        j++;
        k++;
    }

    // Print merged array
    cout << "Merged Array: ";
    for (int x = 0; x < n1 + n2; x++)
    {
        cout << merged[x] << " ";
    }

    return 0;
}