#include <bits/stdc++.h>
using namespace std;

void sieve(int n, vector<bool> &prime) {
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) prime[i] = false;
        }
    }
}

int merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i, j, k;
    int inv_count = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int _mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int mergeSort(vector<int>& arr, int array_size) {
    vector<int> temp(array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}

int main() {
    int n = 5;
    vector<int> arr = {1, 20, 6, 4, 5};
    int ans = mergeSort(arr, n);
    cout << " Number of inversions are " << ans;
    return 0;
}