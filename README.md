# C++ Vecto Class (OOP)

Chương trình triển khai lớp đối tượng `Vecto` (Vector n chiều) trong C++ hỗ trợ cấp phát bộ nhớ động, quản lý tài nguyên an toàn theo chuẩn C++ (Rule of Three) và nạp chồng các toán tử cơ bản.

---

## 📌 Tính năng chính

- **Quản lý bộ nhớ động**: Khởi tạo vector với số chiều linh hoạt, giải phóng vùng nhớ tự động tránh rò rỉ bộ nhớ (Memory Leak).
- **Copy Constructor & Copy Assignment Operator**: Áp dụng idiom Copy-and-Swap để sao chép sâu (Deep Copy) và gán đối tượng an toàn.
- **Nạp chồng toán tử đại số**:
  - `+`, `-`: Phép cộng, trừ hai vector cùng số chiều.
  - `*`: Tích vô hướng (dot product) giữa hai vector.
- **Truy cập phần tử qua chỉ mục**: Nạp chồng toán tử `[]` (cả bản non-const để sửa giá trị và const để đọc dữ liệu an toàn) có bắt lỗi vượt biên mảng (`std::out_of_range`).
- **Xử lý ngoại lệ (Exception Handling)**: Bắt lỗi lệch số chiều, vector rỗng hoặc chỉ số ngoài phạm vi bằng ngoại lệ chuẩn C++ (`std::invalid_argument`, `std::out_of_range`).

---

## 📁 Cấu trúc thư mục

```
├── Vecto.h        # Khai báo lớp Vecto và các nguyên mẫu phương thức / toán tử
├── Vecto.cpp      # Định nghĩa chi tiết các phương thức và nạp chồng toán tử
├── main.cpp       # Mã kiểm thử tính năng (nhập, xuất, tính toán, bắt ngoại lệ)
└── README.md      # Tài liệu hướng dẫn sử dụng
```

---

## 🛠️ Hướng dẫn biên dịch và chạy

Sử dụng trình biên dịch GCC/G++:

### 1. Biên dịch:
```bash
g++ main.cpp Vecto.cpp -o VectoProgram -std=c++11
```

### 2. Thực thi:
- **Trên Linux / macOS:**
  ```bash
  ./VectoProgram
  ```
- **Trên Windows (cmd / PowerShell):**
  ```cmd
  VectoProgram.exe
  ```

---

## 💻 Ví dụ chạy chương trình

### Dữ liệu nhập:
```text
Nhap so chieu: 3
Nhap toa do vecto: 1 2 3
Nhap so chieu: 3
Nhap toa do vecto: 4 5 6
```

### Kết quả xuất:
```text
Tich vo huong: 32
Vecto 1 sau khi sua toa do dau tien: 99.9 2 3 
```
*(Tích vô hướng: $1 \times 4 + 2 \times 5 + 3 \times 6 = 32$)*
