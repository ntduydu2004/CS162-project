# Project changes
1. Thêm 2 file functions.cpp và functions.h, 2 file này sẽ tham gia vào các hàm chính của systems.Trong file functions gồm có:
	- Menu chính: biểu diễn menu
	- inputstudent - inputstaff: Nhập vào thông tin của user từ file csv
	- outputstudent - outputstaff: Xuất ra thông tin của user nếu user bấm vào "View profile"
	- studentFunc - staffFunc: Vẽ menu và cũng là hàm chính của 2 loại user. 
2. Đem hết source code trong hàm main để vào trong hàm menu chính trong file functions.
3. Trong struct user tui có khai báo thêm cái string locate để tìm class của user nhanh hơn.
4. Ở dưới cùng của file user.h tui có thêm sẵn các biến cố định ở dưới cùng, trong khai báo có chữ "extern" để có thể thay đổi và sử dụng giá trị của biến trong các file khác mà ko cần đặt thêm tên biến
