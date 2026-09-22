#pragma once

class Vecto {
private:
    int n;
    double *coor;
    void clear();
public:
    Vecto(int dim = 0);
    Vecto(const Vecto& v);
    ~Vecto();

    void Nhap();
    void Xuat() const;
    
    Vecto operator+(const Vecto &b) const;
    Vecto operator-(const Vecto &b) const;
    double operator*(const Vecto &b) const;
    Vecto& operator=(const Vecto &other);

    double& operator[](int index);
    const double& operator[](int index) const;
};