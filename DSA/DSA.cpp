#include<iostream>
using namespace std;

int LinearSearch(int list[], int size, int key)
{
    for (int i = 0; i < size; i++) {
        if (list[i] == key) {
            return i;
        }
    }

    return -1;
}

int BinarySearch(int list[], int size, int key)
{

    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (list[mid] == key) {
            return mid;
        }
        else if (list[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}
void simpleSort(int list[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (list[i] > list[j]) {
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;

            }
        }
    }
   

}
void BubbleSort(int list[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++)
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
}
void SelectionSort(int list[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (list[j] < list[minIndex]) {
                minIndex = j;
            }
        }
        int temp = list[i];
        list[i] = list[minIndex]; 
        list[minIndex] = temp;
    }
}
void InsertionSort(int list[], int size) {
    for (int i = 1; i < size - 1; i++) {
        for (int j = i; j >= 1; j--) {
            if (list[j - 1] > list[j]) {
                int temp = list[j];
                list[j] = list[j - 1];
                list[j - 1] = temp;
            }
            else
                break;
        }
    }
}
void BinaryInsertionSort(int list[], int size, int key) {
    for (int i = 1; i < size; i++) {
        int key = list[i];
        int pos = BinarySearch(list, key, i - 1);
        int j = i - 1;
        while (j >= pos) {
            list[j + 1] = list[j];

        }
    }
      
}


void MainMenu(int choice, int list[], int size) {
    switch (choice) {
    case 1:
        cout << "Searching MENU\n1.Linear Search\n2.Binary Search\n3.Back to MENU\nEnter your choice: ";
        int choice1;
        cin >> choice1;
        switch (choice1) {
        case 1:
            cout << "Enter the key to search: ";
            int key;
            cin >> key;
            cout << "The answer is: ";
            cout << LinearSearch(list, size, key) << endl;
            break;
        case 2:
            cout << "Enter the key to search: ";
            int key2;
            cin >> key2;
            cout << "The answer is: ";
            cout << BinarySearch(list, size, key2) << endl;
            break;
        case 3:
            break;
        default:
            cout << "Invalid choice\n";

        }
        break;
    case 2:
        cout << "Sorting MENU\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n4.Binary Insertion Sort\n5.Back to MENU\nEnter your choice: ";
        int choice2;
        cin >> choice2;
        switch (choice2) {
        case 1:
            BubbleSort(list, size);
            cout << "The sorted list is: ";
            for (int i = 0; i < size; i++) {
                cout << list[i] << ", ";
            }
            cout << endl;
            break;
        case 2:
            InsertionSort(list, size);
            cout << "The sorted list is: ";
            for (int i = 0; i < size; i++) {
                cout << list[i] << ", ";
            }
            break;
        case 3:
            SelectionSort(list, size);
            cout << "The sorted list is: ";
            for (int i = 0; i < size; i++) {
                cout << list[i] << ", ";
            }
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice\n";
        }

    }
}