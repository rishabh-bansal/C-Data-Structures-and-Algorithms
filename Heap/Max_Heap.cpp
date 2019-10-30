#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    int *arr;
    int capacity;
    int size;

    int parent(int i) {
        if (i == 0) {
            return 0;
        } else {
            return (i - 1) / 2;
        }
    }
    int Lchild(int i) {
        return 2 * i + 1;
    }
    int Rchild(int i) {
        return 2 * i + 2;
    }
    bool isLeaf(int i) {
        if (i >= size)
            return true;
        else
            return false;
    }
    void ShiftUp(int i) {
        if (i == 0)
            return;
        int p_index = parent(i);

        if (arr[p_index] < arr[i]) {
            swap(arr[p_index], arr[i]);
            ShiftUp(p_index);
        }
    }
    void ShiftDown(int i) {
        int l = Lchild(i);
        int r = Rchild(i);

        if (isLeaf(l))
            return;

        int max_index = i;
        if (arr[l] > arr[i]) {
            max_index = l;
        }
        if (!isLeaf(r) && arr[r] > arr[max_index]) {
            max_index = r;
        }

        if (max_index != i) {
            swap(arr[max_index], arr[i]);
            ShiftDown(max_index);
        }
        return;
    }

public:
    MaxHeap(int c) {
        arr = new int[c];
        this->capacity = c;
        this->size = 0;
    }
    void EnsureSize() {
        if (size == capacity) {
            capacity *= 2;
            return;
        }
    }
    int GetSize() {
        return size;
    }
    int GetMax() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return arr[0];
    }
    void Insert(int k) {
        EnsureSize();
        arr[size] = k;
        ShiftUp(size);
        size++;
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int extractMax() {
        int max = arr[0];
        arr[0] = arr[size - 1];
        size--;
        ShiftDown(0);
        return max;
    }
    int DeleteAt(int k) {
        int r = arr[k];
        arr[k] = arr[size - 1];
        size--;

        int p = parent(k);
        if (k == 0 || arr[k] < arr[p])
            ShiftDown(k);
        else
            ShiftUp(k);

        return r;
    }

    //complexity = log n
    void Heapify(int *array, int len) {
        size = len;
        arr = array;

        for (int i = size / 2 - 1; i >= 0; --i) {
            ShiftDown(i);
        }
    }
    void HeapSort() {
        int s = size;
        while (size != 0) {
            int m = arr[0];
            swap(arr[0], arr[size - 1]);
            size--;
            ShiftDown(0);
        }
        size = s;
    }
};

int main() {
    MaxHeap H(5);
    MaxHeap H2(10);
    H.Insert(2);
    H.Insert(13);
    H.Insert(8);
    H.Insert(1);
    H.Insert(5);
    H.Insert(10);
    H.Insert(4);
    H.Insert(20);
    H.Insert(30);
    H.Insert(15);

    H.DeleteAt(0);
    H.HeapSort();
    cout << "\nSorted : " << endl;
    H.GetMax();
    cout << endl;

    int a[] = {10, 20, 50, 30, 40, 5, 15, 25};

    H2.Heapify(a, 8);
    H2.DeleteAt(1);
    H2.GetMax();
    H2.HeapSort();
    cout << "Heapify-^ \n\nSorted : " << endl;
    H2.GetMax();
    cout << endl;

    return 0;
}
