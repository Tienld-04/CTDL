#include <bits/stdc++.h>

using namespace std;
#ifndef __P_queue__cpp
#define __P_queue__cpp
template <typename T>
class P_queue {
  private:
    vector<T> data;
    void swap(T &a, T &b) {
        T tmp = a;
        a = b;
        b = tmp;
    }

  public:
    P_queue() {
    }
    int Size() {
        return data.size();
    }
    T Peek() {
        T front = data[0];
        return front;
    }
    bool Empty() {
        return data.empty();
    }
    void insert(T x) {
        data.push_back(x);
        int n = data.size() - 1; // thiet lap  n = ... la chi so cua phan tu moi chen
        while (n > 0) {
            int root = (n - 1) / 2; // chi so ptu cha
            if (data[n] <= data[root]) {
                break;
            }
            T tmp = data[n];
            data[n] = data[root];
            data[root] = tmp;
            n = root;
        }
    }
    T dequeue() {
        int k = data.size() - 1; // khoi tao k la phan tu cuoi cung trong mang
        T font_x = data[0];
        data[0] = data[k]; // sao chep phan tu vtri K vao vtri dau tien;
        data.pop_back();   // goi phuong thuc pop_pack de loai bo phan tu cuoi cung
        --k;

        int root = 0; // root
        while (1) {
            int n = root * 2 + 1; // chi so con trai
            if (n > k) {
                break;
            }
            int m = n + 1;                    // chi so con phai
            if (m < k && data[m] > data[n]) { // chon 2 con xem con nao co gtri nho nhat
                n = m;                        // de so sanh va hoan doi vs ptu cha
            }
            if (data[root] >= data[n]) {
                break;
            }
            T tmp = data[root];
            data[root] = data[n];
            data[n] = tmp;
            root = n;
        }
        return font_x;
    }
};

#endif

int main() {
    P_queue<int> pq;
    pq.insert(30);
    pq.insert(30);
    pq.insert(20);
    pq.insert(50);
    pq.insert(40);
    pq.insert(66);
    cout << "top = " << pq.Peek();
    cout << "\nsz = " << pq.Size() << endl;
    pq.dequeue();
    // while (!pq.Empty()) {
    //     cout << pq.dequeue() << endl;
    // }
    cout << "top = " << pq.Peek();
    return 0;
}
