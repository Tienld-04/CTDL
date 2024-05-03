#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
int partition(int a[], int left, int right) {
    int pivot = a[right]; // phan tu ben phai cuoi cung
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    // dua chot ve vi tri giua
    i++;
    swap(a[i], a[right]);
    return i;
}
void quick_sort(int a[], int left, int right) {
    if (left >= right) {
        return;
    }
    int p = partition(a, left, right);
    quick_sort(a, left, p - 1);
    quick_sort(a, p + 1, right);
}
int main() {
    int n;
    int a[50];
    cout << "Nhap vao n = ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}