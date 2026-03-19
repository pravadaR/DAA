#include<iostream>
using namespace std;

int linearSearch(int A[], int n, int value)
{
    for (int i = 0; i < n;i++)
    {
        if(A[i]==value)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n, value;
    cout << "Enter number of elemts:";
    cin >> n;

    int A[n];
    cout << "Enter\t" << n << "elements:\n";
    for (int i = 0; i < n;i++)
        cin >> A[i];

    cout << "Enter value to search:";
    cin >> value;

    int index = linearSearch(A, n, value);

    if(index != -1)
        cout << "Value found at index" << index << endl;
        else
      cout << "value not found" << endl;
        return 0;
}
