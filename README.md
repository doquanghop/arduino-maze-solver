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

## Cấu trúc dự án
```
arduino-maze-solver/
├── idea/                    # Thư mục chứa file cấu hình của IntelliJ IDEA (nếu dùng IDE này)
├── src/                     # Thư mục chứa mã nguồn chính
│   ├── constants.h          # File chứa các hằng số (constants) của dự án
│   ├── line_sensor.cpp      # File nguồn cho cảm biến dò đường (line sensor)
│   ├── line_sensor.h        # File header cho cảm biến dò đường
│   ├── main.ino             # File chính của Arduino, chứa hàm setup() và loop()
│   ├── motor_control.cpp    # File nguồn cho class điều khiển động cơ
│   ├── motor_control.h      # File header cho class điều khiển động cơ
│   ├── obstacle_sensor.cpp  # File nguồn cho cảm biến phát hiện chướng ngại vật (HC-SR04)
│   ├── obstacle_sensor.h    # File header cho cảm biến phát hiện chướng ngại vật
│   ├── robot_line.cpp       # File nguồn cho logic điều khiển robot dò đường
│   ├── robot_line.h         # File header cho logic điều khiển robot dò đường
│   ├── robot_scan.cpp       # File nguồn cho logic quét và điều hướng mê cung
│   ├── robot_scan.h         # File header cho logic quét và điều hướng mê cung
├── data/                    # Thư mục chứa dữ liệu 
│   ├── map.txt              # File chứa bản đồ mê cung (nếu dùng)
│   ├── routes.txt           # File chứa các tuyến đường đã quét (nếu dùng)
├── pathfinder_algo.cpp.cpp  # File nguồn cho thuật toán tìm đường tối ưu
├── README.md                # File mô tả dự án (file này)
```
---

## Thành viên tham gia 👥
- [**Đỗ Quang Hợp**](https://github.com/doquanghop)
- [**Nguyễn Thu Hương**](https://github.com/nguyenthuhuong)
- [**Nguyễn Việt Anh**](https://github.com/DevxVAnh)
- [**Đỗ Công Trí**](https://github.com/docongtri)
- [**Nguyễn Hồng Lịch**](https://github.com/Cry-0) 

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
- Email: dqhdev.q@email.com  
- Issues: [GitHub Issues](https://github.com/dqh999/arduino-maze-solver/issues)

---

