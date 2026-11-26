#include <iostream>
#include <string>
using namespace std;

template<class T>
class Queue {
private:
    T a[100]; // Chứa các phần tử
    int F;    // Vị trí phần tử đầu tiên
    int L;    // Vị trí ô trống tiếp theo để thêm phần tử
    int num;  // Số phần tử hiện có trong hàng đợi

public:
    Queue() {
        F = L = num = 0;
    }

    int size() {
        return num;
    }

    // 4. Kiểm tra hàng đợi rỗng
    bool isEmpty() {
        return num == 0;
    }

    // 3a. Lấy phần tử ở đầu hàng đợi
    T& front() {
        return a[F];
    }

    T& back() {
        return a[(L - 1 + 100) % 100];
    }

    // 2. Thêm phần tử vào cuối hàng đợi
    void enqueue(T x) {
        if (num == 100) {
            cout << "Hang doi day!\n";
            return;
        }
        a[L] = x;
        L = (L + 1) % 100;
        num++;
    }

    // 3b. Xóa phần tử ở đầu hàng đợi
    void dequeue() {
        if (isEmpty()) {
            cout << "Hang doi rong!\n";
            return;
        }
        F = (F + 1) % 100;
        num--;
    }

    // 5. Hiển thị các phần tử từ đầu đến cuối hàng đợi
    void display() {
        if (isEmpty()) {
            cout << "Hang doi rong!\n";
            return;
        }
        for (int i = 0; i < num; i++) {
            cout << a[(F + i) % 100] << " ";
        }
        cout << "\n";
    }
};

int main() {
    // Chạy dữ liệu theo yêu cầu
    Queue<int> q;
    int data[] = {10, 20, 30, 40, 50};
    for (int x : data) {
        q.enqueue(x);
    }
    cout << "Sau khi them 10, 20, 30, 40, 50: ";
    q.display();

    cout << "Phan tu dau (front): " << q.front() << "\n";
    q.dequeue();
    cout << "Phan tu dau sau dequeue lan 1: " << q.front() << "\n";
    q.dequeue();
    cout << "Sau 2 lan dequeue: ";
    q.display();

    q.enqueue(60);
    q.enqueue(70);
    cout << "Sau khi them 60, 70: ";
    q.display();

    // 6. Mô phỏng hệ thống phục vụ khách hàng (FIFO)
    cout << "\n--- Mo phong phuc vu khach hang ---\n";
    Queue<string> khachHang;
    khachHang.enqueue("Khach A");
    khachHang.enqueue("Khach B");
    khachHang.enqueue("Khach C");

    cout << "Hang doi ban dau: ";
    khachHang.display();

    while (!khachHang.isEmpty()) {
        cout << "Dang phuc vu: " << khachHang.front() << "\n";
        khachHang.dequeue();
    }
    cout << "Da phuc vu het khach (isEmpty = "
         << (khachHang.isEmpty() ? "true" : "false") << ")\n";

    return 0;
}