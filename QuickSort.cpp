
/*Practice with quicksort in C++ for better understanding of algorithm when analyzing runtime*/

#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

  
// A utility function to swap two elements  
void swap(int* a, int* b)  
{  
    int c = *a;  
    *a = *b;  
    *b = c;  
}  
/* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    cout << "[" << arr[0];
    for (i = 1; i < size; i++)  
        cout  << ", " << arr[i];  
    cout << "]" << endl;  
}  
/* Typical pivot function*/
int partition (int arr[], int left, int right)  
{  
	//    int arr[] = {2, 4, 7, 5, 1, 9, 6};  

    int pivot = arr[right]; // pivot  
    cout << "pivot = " << pivot << endl;
    int i = (left - 1); // Index of smaller element  
  
    for (int j = left; j <= right - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
        printArray(arr, right + 1);
    }  
    swap(&arr[i + 1], &arr[right]);  
    printArray(arr, right + 1);
    cout << endl << "i + 1 = " << i+1 << endl;
    return (i + 1);  
}  
  
/* The main function that implements QuickSort */
void quickSort(int arr[], int left, int right)  
{  
    if (left < right)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, left, right);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, left, pi - 1);  
        quickSort(arr, pi + 1, right);  
    }  
}   
  
// Driver Code 
int main()  
{  
    int arr[] = {2, 4, 7, 5, 1, 9, 6};  

    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}  
