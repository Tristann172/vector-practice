#include <iostream>
#include "Vecto.h"

using namespace std;

int main() {
    try {
        Vecto v1, v2;
        v1.Nhap();
        v2.Nhap();
        
        cout << "Tich vo huong: " << v1 * v2 << endl;
        
        v1[0] = 99.9;
        cout << "Vecto 1 sau khi sua toa do dau tien: ";
        v1.Xuat();
        
    } catch (const exception& e) {
        cout << "Loi: " << e.what() << endl;
    }
    return 0;
}