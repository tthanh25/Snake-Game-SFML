# **Snake-Game-SFML**
## **Video mô tả game**
[Link](https://www.youtube.com/watch?v=VpKniGcmSfs&t=54s)
-  Đã sửa lỗi sinh ngẫu nhiên thức ăn (trước kia có thể thức ăn bị ở giữa thân rắn).
-  Thêm 2 level khi chọn menu, GameOver nhấn Enter để chọn lại level.
- BestScore được update khi thoát cửa sổ main.exe và chạy lại main.exe.
## **Hướng dẫn xây dựng**
---
### *Yêu cầu:*
* Visual Studio Code ( hoặc bất kì trình biên dịch C++ nào khác, ở đây em sử dụng Visual Studio Code ) 
* Mingw32 ( phiên bản 7.3.0 )
* Thư viện SFML (đã có trong file src)
### *Cách chạy chương trình:* 
* Có thể chỉ clone về và chạy file main.exe để trải nghiệm game
* Mở Visual Studio Code => Terminal => New Terminal (Tổ hợp phím Control + Shift + ` )
* Gõ lệnh: 
###
``` 
    git clone https://github.com/tthanh25/Snake-Game-SFML.git
```
* Tại giao diện Visual Studio Code, chọn File => Open Folfder => chọn      folder vừa được tạo => Open.
* Hoặc vào folder vừa clone về, chuột phải chọn " open with Code " cho VSCode
* chỉnh sửa file configurations bằng cách thêm dòng này vào include path
 ```
                "${workspaceFolder}/**",
                "${workspaceFolder}/include",
                "${workspaceFolder}/src",
                "${workspaceFolder}/source"
 ```
* Hoặc nhấn tổ hợp Control + Shift + P gõ configurations chọn Edit Configurations (UI) rồi thêm những dòng bên trên vào
* Sau khi mở được folder, di chuyển xuống Terminal, gõ 2 lệnh sau:
```
    mingw32-make
    .\main.exe
```
---
## **Mô tả chung:**
* Game được xây dựng dựa trên rắn săn mồi.
* Các thành phần game: sân chơi (board), rắn (snake), thức ăn (food), điểm (score)
## **Các chức năng đã cài đặt**
### Cấu trúc game: Game có đủ các trạng thái cơ bản:
####
* MenuGame (Sử dụng các phím WASD hoặc Up,Down,Left,Right và Enter)
* GamePlay
* GamePause (sử dụng nút Space)
* GameOver (sử dụng nút Enter để chọn level chơi lại)
## Tính năng được bổ sung
* Táo vàng giúp rắn trở nên siêu bất tử, rắn có thể đi xuyên cơ thể và có thể đi ra ngoài map. Trạng thái kết thúc khi rắn ăn táo màu đỏ
* Ăn táo vàng +5 điểm, táo đỏ + 1 điểm. Rắn đi ra ngoài map là tính năng em chỉnh, không phải bug ạ. (Có thể chỉnh lại bằng cách xoá hết những câu lệnh chứa biển bool FLAG trong Game.h và Game.cpp )
* Khi đạt mốc 50 điểm, rắn ăn táo đỏ sẽ biến thành màu đỏ
## **Kỹ thuật lập trình được sử dụng**
* Lập trình đồ họa
* Class
* Mảng
* Hàm
* std::list
* Các biến đếm
## **Kết luận**
* Game cơ bản đã có đủ các cấu trúc của 1 game cơ bản
* Tồn tại một số lỗi trong chương trình game như:
* Lỗi về hướng đi khi nhấn nhiều tổ hợp phím
* Hướng phát triển:
	* Sửa các lỗi như trên
	* Xây dựng logic, chuyển động game mượt hơn
	* Nâng cấp đồ họa game
	* Thêm các vật phẩm mới như : tăng tốc, bất tử có thời gian, cộng nhiều điểm hơn nữa, sinh ra dài hơn,...
  * Xây dựng chương trình game với nhiều level (đã thêm 2 level mới)
