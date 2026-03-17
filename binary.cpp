#include<iostream>
using namespace std;

int binarySearch(int A[], int n, int x)
{
    int lowerBound = 0;
    int upperBound = n - 1;

    while(lowerBound<=upperBound)
    {
        int midPoint = lowerBound + (upperBound - lowerBound) / 2;
        if(A[midPoint]<x)
        {
            lowerBound = midPoint + 1;

        }
        else if(A[midPoint]>x)
        {
            upperBound = midPoint - 1;
        }
        else{
            return midPoint;

        }
        }
        return -1;
    }
    
    int main()
    {
        int n, x;
        cout << "Enter number of elemts(sorted array):";
        cin >> n;

        int A[n];
        cout << "Enter " << n << "elemets in sorted order:\n";
        for (int i = 0; i < n;i++)
            cin >> A[i];
        cout << "Enter value to search:";
        cin >> x;

        int index = binarySearch(A, n, x);
        if(index != -1)
            cout << "value found at index" << index << endl;
        else
            cout << "Value not found in array" << endl;
        return 0;

    }
