#include <bits/stdc++.h>
using namespace std;

class Heap {
   private:
    vector<int> array;
    int capacity;

   public:
    int count;

    Heap(int capa) {
        count = 0;
        capacity = capa;
        array = vector<int>(capa);
    }

    Heap(vector<int> v) {
        count = v.size();
        capacity = v.size();
        array = v;
        for (int i = (count - 1) / 2; i >= 0; i--) {
            percolateDown(i);
        }
    }

    int leftChild(int i) {
        int left = 2 * i + 1;
        if (left >= count)
            return -1;
        return left;
    }

    int rightChild(int i) {
        int right = 2 * i + 2;
        if (right >= count)
            return -1;
        return right;
    }

    int getMin() {
        if (count == 0)
            return -1;
        return array[0];
    }

    void percolateDown(int i) {
        int l, r, min, temp;
        l = leftChild(i);
        r = rightChild(i);
        if (l != -1 && array[l] < array[i])
            min = l;
        else
            min = i;
        if (r != -1 && array[r] < array[min])
            min = r;
        if (min != i) {
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        } else {
            return;
        }

        percolateDown(min);
    }

    int deleteMin() {
        int data;
        if (count == 0)
            return -1;
        data = array[0];
        array[0] = array[count - 1];
        count--;
        percolateDown(0);
        return data;
    }

    void resizeHeap() {
        vector<int> array_old = array;
        array = vector<int>(capacity * 2);
        for (int i = 0; i < capacity; i++) {
            array[i] = array_old[i];
        }
        capacity *= 2;
    }

    void insert(int data) {
        int i;
        if (count == capacity) {
            resizeHeap();
        }
        count++;
        i = count - 1;
        while (i > 0 && data < array[(i - 1) / 2]) {
            array[i] = array[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        array[i] = data;
    }

    void display() {
        for (int i = 0; i < count; i++) {
            cout << array[i] << " ";
        }
    }
};

int32_t main() {
    // Heap h(20);
    // h.insert(2);
    // h.insert(1);
    // h.insert(100);
    // h.deleteMin();

    // h.display();

    cout << gcd(979, 999) << endl; 

    vector<int> v = {1, 4, 100, 2, 3, 5};
    Heap h(v);

    // h.insert(1000);
    // h.insert(0);
    // h.deleteMin();

    // h.display();
}