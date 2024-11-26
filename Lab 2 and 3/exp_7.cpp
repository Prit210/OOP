//Q12 7
#include <iostream>
using namespace std;

class Array {
    int* arr;
    int size;

public:
    Array(int s) : size(s) {
        arr = new int[size];
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) cin >> arr[i];
    }

    int findLargest() const {
        int largest = arr[0];
        for (int i = 1; i < size; i++)
            if (arr[i] > largest)
                largest = arr[i];
        return largest;
    }

    ~Array() { delete[] arr; }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    Array a(n);
    cout << "Largest element: " << a.findLargest() << endl;
    return 0;
}
