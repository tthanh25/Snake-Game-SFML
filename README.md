# **Snake-Game-SFML**
## **Video mô tả game**
[Link]()

## **Hướng dẫn xây dựng**
---
### *Yêu cầu:*
* Visual Studio Code ( hoặc bất kì trình biên dịch C++ nào khác, ở đây em sử dụng Visual Studio Code ) 
* Mingw32 ( phiên bản 7.3.0 )
* Thư viện SFML (đã có trong file src)
### *Cách chạy chương trình:*
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
* MenuGame
* GamePlay
* GamePause (sử dụng nút Space)
* GameOver (sử dụng nút Enter để chơi lại)

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
* Sinh ra thức ăn (food) chưa được chính xác
* Lỗi về hướng đi khi nhấn nhiều tổ hợp phím
* Kiểm tra va chạm chưa chính xác
* Hướng phát triển:
	* Sửa các lỗi như trên
	* Xây dựng logic, chuyển động game mượt hơn
	* Nâng cấp đồ họa game
	* Thêm các vật phẩm mới như : tăng tốc, bất tử có thời gian, cộng nhiều điểm hơn nữa, sinh ra dài hơn,...
  * Xây dựng chương trình game với nhiều level
