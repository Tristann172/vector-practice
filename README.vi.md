# Thư viện Thao tác Vecto (C++)
> [English version](README.md)

Chương trình triển khai lớp đối tượng Vecto n chiều trong C++, hỗ trợ cấp phát bộ nhớ động, quản lý tài nguyên an toàn theo chuẩn C++ và nạp chồng đầy đủ các toán tử đại số cơ bản.

## Điểm nổi bật về kỹ thuật

- Hỗ trợ số chiều động: Khởi tạo vector với kích thước linh hoạt tại thời điểm thực thi thông qua bộ nhớ heap.
- Tuân thủ quy tắc Rule of Three: Triển khai tường minh Destructor, Copy Constructor và Copy Assignment Operator, đảm bảo sao chép sâu (deep copy) và loại bỏ hoàn toàn rò rỉ bộ nhớ (memory leak).
- An toàn ngoại lệ với Copy-and-Swap: Áp dụng kỹ thuật copy-and-swap trong toán tử gán nhằm đạt mức an toàn ngoại lệ mạnh (strong exception safety).
- Nạp chồng toán tử trực quan: Hỗ trợ phép cộng, phép trừ và tích vô hướng (dot product) giữa hai vector.
- Truy cập an toàn qua chỉ mục: Nạp chồng toán tử subscript (`[]`) cho cả hai trường hợp đọc/ghi, đồng thời kiểm tra biên và ném ngoại lệ chuẩn khi chỉ số không hợp lệ.
- Cơ chế bắt lỗi chuẩn hóa: Ném ngoại lệ `std::invalid_argument` khi lệch số chiều hoặc thao tác trên vector rỗng, và `std::out_of_range` khi truy cập chỉ số ngoài phạm vi.

## Cấu trúc thư mục

```text
.
├── Vecto.h        # Khai báo lớp Vecto, các nguyên mẫu phương thức và toán tử
├── Vecto.cpp      # Định nghĩa chi tiết các phương thức và nạp chồng toán tử
├── main.cpp       # Chương trình kiểm thử và minh họa tính năng
├── .gitignore     # Cấu hình bỏ qua các file biên dịch trung gian của Git
└── README.md      # Tài liệu hướng dẫn kỹ thuật của dự án
```

## Bảng tra cứu API

### Hàm khởi tạo và Hủy

| Cú pháp | Mô tả |
| :--- | :--- |
| `Vecto(int dim = 0)` | Khởi tạo vector có số chiều `dim` với tất cả phần tử bằng 0. |
| `Vecto(const Vecto& v)` | Hàm khởi tạo sao chép. Cấp phát vùng nhớ độc lập và thực hiện sao chép sâu. |
| `~Vecto()` | Hàm hủy. Giải phóng toàn bộ bộ nhớ động đã cấp phát cho vector. |

### Phương thức thành viên

| Cú pháp | Mô tả |
| :--- | :--- |
| `void Nhap()` | Nhập số chiều và tọa độ vector từ luồng đầu vào chuẩn. Giải phóng dữ liệu cũ trước khi cấp phát mới. |
| `void Xuat() const` | In tọa độ vector ra màn hình. Xuất thông báo "Vecto rong" nếu số chiều bằng 0. |

### Nạp chồng toán tử

| Cú pháp | Kiểu trả về | Mô tả |
| :--- | :--- | :--- |
| `operator+(const Vecto& b) const` | `Vecto` | Cộng từng phần tử tương ứng của hai vector. Ném `std::invalid_argument` nếu lệch số chiều hoặc rỗng. |
| `operator-(const Vecto& b) const` | `Vecto` | Trừ từng phần tử tương ứng của hai vector. Ném `std::invalid_argument` nếu lệch số chiều hoặc rỗng. |
| `operator*(const Vecto& b) const` | `double` | Tính tích vô hướng của hai vector. Ném `std::invalid_argument` nếu lệch số chiều hoặc rỗng. |
| `operator=(const Vecto& other)` | `Vecto&` | Toán tử gán sao chép sâu theo kỹ thuật copy-and-swap. |
| `operator[](int index)` | `double&` | Truy cập phần tử để đọc/ghi theo chỉ mục. Ném `std::out_of_range` nếu chỉ mục vượt biên. |
| `operator[](int index) const` | `const double&` | Truy cập phần tử chỉ đọc theo chỉ mục. Ném `std::out_of_range` nếu chỉ mục vượt biên. |

## Hướng dẫn biên dịch và thực thi

### Yêu cầu môi trường

- Trình biên dịch GCC / G++ (hỗ trợ C++11 trở lên, khuyến nghị C++17)

### Lệnh biên dịch

Biên dịch các file nguồn bằng trình biên dịch `g++`:

```bash
g++ -std=c++17 -Wall -Wextra -O2 main.cpp Vecto.cpp -o vector_program
```

### Lệnh thực thi

#### Trên Linux / macOS:
```bash
./vector_program
```

#### Trên Windows (Command Prompt / PowerShell):
```cmd
vector_program.exe
```

## Ví dụ sử dụng

```cpp
#include <iostream>
#include "Vecto.h"

int main() {
    try {
        Vecto v1, v2;

        std::cout << "Nhap vector v1:\n";
        v1.Nhap();

        std::cout << "Nhap vector v2:\n";
        v2.Nhap();

        // Tinh tich vo huong
        double dot_product = v1 * v2;
        std::cout << "Tich vo huong (v1 * v2): " << dot_product << std::endl;

        // Thay doi gia tri phan tu qua toan tu []
        v1[0] = 99.9;
        std::cout << "Vector v1 sau khi sua phan tu dau tien: ";
        v1.Xuat();

        // Phep cong hai vector
        Vecto v3 = v1 + v2;
        std::cout << "Tong hai vector (v1 + v2): ";
        v3.Xuat();

    } catch (const std::exception& e) {
        std::cerr << "Loi thuc thi: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
```
