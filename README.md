# Robot Mê Cung 🤖

![Banner](https://via.placeholder.com/800x200.png?text=Robot+Mê+Cung)  

## Giới thiệu ℹ️
Dự án **Robot Mê Cung** là một hệ thống robot tự động được phát triển dựa trên vi điều khiển Arduino, có khả năng dò đường và tránh chướng ngại vật trong mê cung. Đây là một dự án ứng dụng lập trình nhúng và cảm biến, hướng đến việc tạo ra một robot thông minh với khả năng tự điều hướng.

---

## Tính năng nổi bật ✨
- Tự động phát hiện và tránh chướng ngại vật bằng cảm biến siêu âm.
- Điều khiển linh hoạt các động cơ DC thông qua mạch L298N.
- Dễ dàng tùy chỉnh và mở rộng mã nguồn.

---

## Phần cứng sử dụng 🛠️
| Linh kiện                  | Mô tả                                      |
|----------------------------|--------------------------------------------|
| **Arduino UNO R3 SMD**     | Vi điều khiển chính của hệ thống.          |
| **Mạch L298N**             | Điều khiển động cơ DC để di chuyển robot.  |
| **Cảm biến HC-SR04**       | Phát hiện chướng ngại vật bằng sóng siêu âm.|

---

## Thành viên tham gia 👥
- [**Đỗ Quang Hợp**](https://github.com/doquanghop)
- [**Nguyễn Thu Hương**](https://github.com/nguyenthuhuong)
- [**Nguyễn Việt Anh**](https://github.com/DevxVAnh)
- [**Đỗ Công Trí**](https://github.com/docongtri)
- [**Nguyễn Hồng Lịch**](https://github.com/Cry-0) 

---

## Hướng dẫn cài đặt ⚙️
### Yêu cầu trước
- [Arduino IDE](https://www.arduino.cc/en/software) đã được cài đặt.
- Các thư viện cần thiết: `NewPing` (cho HC-SR04).

### Các bước thực hiện
1. **Clone dự án**  
   ```bash
   git clone https://github.com/dqh999/arduino-maze-solver.git
   ```
2. **Mở mã nguồn**  
   - Mở file `Main.ino` trong Arduino IDE.  
3. **Cài đặt thư viện**  
   - Vào `Sketch > Include Library > Manage Libraries`, tìm và cài đặt `NewPing`.  
4. **Kết nối phần cứng**  
   - Lắp ráp linh kiện theo sơ đồ (xem phần **Sơ đồ mạch** bên dưới).  
   - Kết nối Arduino với máy tính qua cáp USB.  
5. **Tải code lên Arduino**  
   - Nhấn `Upload` trong Arduino IDE để nạp chương trình.

---

## Sơ đồ mạch 📏
*(Chèn ảnh sơ đồ mạch tại đây, ví dụ:)*  
![Sơ đồ mạch](https://via.placeholder.com/600x400.png?text=Sơ+đồ+mạch)

---

## Cách sử dụng 🚀
1. Đặt robot vào mê cung.
2. Cấp nguồn cho Arduino.
3. Robot sẽ tự động di chuyển, phát hiện và tránh chướng ngại vật.

---

## Đóng góp 🤝
Chúng tôi hoan nghênh mọi đóng góp! Để tham gia:
1. Fork repository này.
2. Tạo branch mới: `git checkout -b feature/ten-branch`.
3. Commit thay đổi: `git commit -m "Mô tả thay đổi"`.
4. Push lên branch: `git push origin feature/ten-branch`.
5. Tạo Pull Request.

---

## Giấy phép 📜
Dự án được phát hành dưới [MIT License](LICENSE). Xem file `LICENSE` để biết thêm chi tiết.

---

## Liên hệ 📧
Nếu bạn có câu hỏi hoặc cần hỗ trợ, hãy liên hệ qua:  
- Email: example@email.com  
- Issues: [GitHub Issues](https://github.com/dqh999/arduino-maze-solver/issues)

---

⭐️ *Nếu bạn thấy dự án hữu ích, hãy để lại một ngôi sao trên GitHub!* ⭐️
```

### Hướng dẫn tải về:
1. **Sao chép nội dung**: Copy toàn bộ đoạn mã trên.
2. **Tạo file `README.md`**:
   - Mở một trình soạn thảo văn bản (như Notepad, VS Code, hoặc bất kỳ IDE nào).
   - Dán nội dung vào và lưu với tên `README.md`.
3. **Đẩy lên GitHub**:
   - Đặt file này vào thư mục gốc của repository dự án (`arduino-maze-solver`).
   - Commit và push file lên GitHub bằng lệnh:
     ```bash
     git add README.md
     git commit -m "Thêm file README.md"
     git push origin main
     ```
