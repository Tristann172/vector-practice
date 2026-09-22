# C++ Dynamic Vector Library (`vector-practice`)

Một thư viện lớp `Vecto` toán học trong C++ xử lý không gian n chiều, áp dụng các kỹ thuật quản lý bộ nhớ động nâng cao, chuẩn thiết kế hướng đối tượng (OOP) và xử lý ngoại lệ an toàn.

---

## 🚀 Tính năng nổi bật

- **Cấu trúc module hóa**: Phân tách rõ ràng giữa giao diện (`Vecto.h`) và cài đặt chi tiết (`Vecto.cpp`).
- **Quy tắc 3 (Rule of Three)**: Hiện thực đầy đủ Constructor mặc định, Copy Constructor và Destructor nhằm ngăn ngừa rò rỉ bộ nhớ (memory leak).
- **Copy-and-Swap Idiom**: Toán tử gán (`operator=`) đạt chuẩn Strong Exception Safety, tự động dọn dẹp tài nguyên và chống gán chính nó (`self-assignment`).
- **Const-Correctness**: Hỗ trợ nạp chồng `operator[]` cả dạng đọc-ghi (`double&`) và dạng chỉ đọc (`const double&`).
- **Xử lý ngoại lệ (Exception Handling)**: Bắt lỗi lệch số chiều toán học (`std::invalid_argument`) và truy cập ngoài vùng nhớ (`std::out_of_range`).

---

## 📁 Cấu trúc thư mục

```text
├── Vecto.h        # Khai báo lớp Vecto (Interface)
├── Vecto.cpp      # Cài đặt chi tiết các phương thức & toán tử
├── main.cpp       # Chương trình kiểm thử logic và nạp chồng toán tử
├── .gitignore     # Chặn các file nhị phân rác (*.exe, *.obj)
└── README.md      # Tài liệu hướng dẫn sử dụng
```
🛠️ Hướng dẫn biên dịch & chạy
Yêu cầu trình biên dịch hỗ trợ C++11 trở lên (như GCC, Clang, hoặc MSVC).

1. Biên dịch qua Terminal (g++)
Bash
# Gom tất cả các file mã nguồn thành file chạy
g++ *.cpp -o my_app
2. Khởi chạy chương trình
Windows:

PowerShell
.\my_app.exe
Linux / macOS:

Bash
./my_app
💻 Mã nguồn mẫu (Usage Example)
C++
#include <iostream>
#include "Vecto.h"

int main() {
    try {
        Vecto v1(3), v2(3);
        
        // Gán giá trị bằng toán tử []
        v1[0] = 1.0; v1[1] = 2.0; v1[2] = 3.0;
        v2[0] = 4.0; v2[1] = 5.0; v2[2] = 6.0;

        // Các phép toán vectơ
        Vecto tong = v1 + v2;
        double tich_vo_huong = v1 * v2;

        std::cout << "Tong: ";
        tong.Xuat();
        std::cout << "Tich vo huong: " << tich_vo_huong << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Loi: " << e.what() << std::endl;
    }
    return 0;
}
👤 Tác giả
GitHub: @Tristann172


Sau khi tạo xong file này, bạn chỉ cần gõ cụm 3 lệnh quen thuộc để cập nhật lên GitHub:
```bash
git add .
git commit -m "Them file README mo ta du an"
git push
