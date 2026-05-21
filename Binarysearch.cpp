#include <iostream>
using namespace std;

int main()
{
    int n, key, comp = 0;

    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter key: ";
    cin >> key;

    int low = 0, high = n - 1;
    int found = -1;

    while(low <= high)
    {
        comp++;

        int mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            found = mid;
            break;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(found != -1)
        cout << "Key found at index " << found << endl;
    else
        cout << "Key not found" << endl;

    cout << "Comparisons = " << comp;

    return 0;
}
