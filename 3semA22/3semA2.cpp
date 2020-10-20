#include <iostream>
#include<chrono>
#include<fstream>
#include<math.h> 
using namespace std;

bool isSorted(int* arr, int size) {
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1]) return false;
    return true;
}

int BinarySearch(int arr[], int size, int x) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] > x) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

void QuickSort(int* arr, long int left, long int right) {
    long int pivot = arr[(left + right) / 2];
    long int i = left, j = right;
    while (i < j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]); i++; j--;
        }
    }
    if (left < j) QuickSort(arr, left, j);
    if (i < right) QuickSort(arr, i, right);
}

void BubbleSort(int* arr, long int size) {
    bool swapp;
    for (long int j = 0; j < size; j++) {
        swapp = false;
        for (long int i = 0; i < size - j - 1; i++)
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]); swapp = true;
            }
        if (swapp == false) break;
    }
}

void BogoSort(int* arr, int size) {
    while (!isSorted(arr, size)) {
        for (int i = 0; i < size; i++)
            swap(arr[i], arr[rand() % size]);
    }
}

void CountingSort(char* arr, int size) {
    const int count_size = 128;
    int count[count_size]; 
    int j = 0;
    for (int i = 32; i < count_size; i++) count[i] = 0;
    for (int i = 0; i < size; i++)  count[(int)arr[i]]++;
    for (int i = 32; i < count_size; i++) {
        while (count[i] != 0) { 
            count[i]--; 
            arr[j] = (char)i; 
            j++; 
        }
    }

}

int main()
{ 
    fstream f; f.open("out.csv");
    long int n;
    //char* arr = new char[n];
    f << "N; Bubble; Quick" << endl;
    for (int i = 0; i <= 5; i++) {
        n = pow(10, i);
        int* arr = new int[n]; int* arr2 = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = rand(); arr2[i] = arr[i];
        }
        auto begin = chrono::steady_clock::now();
        BubbleSort(arr, n);
        auto end = chrono::steady_clock::now();
        auto elapsed_bub = chrono::duration_cast<chrono::nanoseconds>(end - begin);


        begin = chrono::steady_clock::now();
        QuickSort(arr2, 0, n - 1);
        end = chrono::steady_clock::now();
        auto elapsed_quick = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        //auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
        f << n << ";" << elapsed_bub.count() << ";" << elapsed_quick.count() << "\n";
        cout << n << ": " << elapsed_bub.count() << " " << elapsed_quick.count() << " ns\n";
    }
    f.close();
    
    //for (int i = 0; i < n; i++) cout << arr[i] << " ";
}