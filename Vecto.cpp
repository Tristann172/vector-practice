#include "Vecto.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

void Vecto::clear() {
    delete[] coor;
    coor = nullptr;
    n = 0;
}

Vecto::Vecto(int dim) : n(dim), coor(nullptr) {
    if (n > 0) {
        coor = new double[n];
        for (int i = 0; i < n; i++) {
            coor[i] = 0;
        }
    }
}

Vecto::Vecto(const Vecto& v) : n(v.n), coor(nullptr) {
    if (n > 0 && v.coor != nullptr) {
        coor = new double[n];
        for (int i = 0; i < n; i++) {
            coor[i] = v.coor[i];
        }
    }
}

Vecto::~Vecto() {
    clear();
}

void Vecto::Nhap() {
    clear();
    cout << "Nhap so chieu: ";
    cin >> n;
    if (n > 0) {
        coor = new double[n];
        cout << "Nhap toa do vecto: ";
        for (int i = 0; i < n; i++) {
            cin >> coor[i];
        }
    }
}

void Vecto::Xuat() const {
    if (n == 0) cout << "Vecto rong";
    for (int i = 0; i < n; i++) {
        cout << coor[i] << " ";
    }
    cout << endl;
}

Vecto Vecto::operator+(const Vecto &b) const {
    if (this->n == 0 || b.n == 0) throw invalid_argument("Vecto rong, khong the cong!");
    if (this->n != b.n) throw invalid_argument("Lech so chieu!");
    
    Vecto res(n);
    for (int i = 0; i < n; i++) {
        res.coor[i] = this->coor[i] + b.coor[i];
    }
    return res;
}

Vecto Vecto::operator-(const Vecto &b) const {
    if (this->n == 0 || b.n == 0) throw invalid_argument("Vecto rong, khong the tru!");
    if (this->n != b.n) throw invalid_argument("Lech so chieu!");
    
    Vecto res(n);
    for (int i = 0; i < n; i++) {
        res.coor[i] = this->coor[i] - b.coor[i];
    }
    return res;
}

double Vecto::operator*(const Vecto &b) const {
    if (this->n == 0 || b.n == 0) throw invalid_argument("Khong the nhan tich vo huong vecto rong!");
    if (this->n != b.n) throw invalid_argument("Khong cung so chieu!");
    
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += this->coor[i] * b.coor[i];
    }
    return res;
}

Vecto& Vecto::operator=(const Vecto &other) {
    if (this == &other) return *this;
    Vecto temp(other);
    swap(this->n, temp.n);
    swap(this->coor, temp.coor);
    return *this;
}

double& Vecto::operator[](int index) {
    if (index < 0 || index >= n) throw out_of_range("Loi: Chi so nam ngoai mang!");
    return coor[index];
}

const double& Vecto::operator[](int index) const {
    if (index < 0 || index >= n) throw out_of_range("Loi: Chi so nam ngoai mang!");
    return coor[index];
}