#include <iostream>
using namespace std;

int main()
{
    int n, key, comp = 0;

    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter key: ";
    cin >> key;

    int found = -1;

    for(int i = 0; i < n; i++)
    {
        comp++;

        if(arr[i] == key)
        {
            found = i;
            break;
        }
    }

    if(found != -1)
        cout << "Key found at index " << found << endl;
    else
        cout << "Key not found" << endl;

    cout << "Comparisons = " << comp;

    return 0;
}
