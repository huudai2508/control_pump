#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Hàm để đọc giá trị từ cảm biến nhiệt độ và độ ẩm
// Hàm này sẽ trả về một số nguyên ngẫu nhiên trong khoảng từ 0 đến 100
// Đơn vị của nhiệt độ là độ C, đơn vị của độ ẩm là %
int read_sensor(int *temp, int *humid) {
    srand(time(NULL)); // Khởi tạo bộ sinh số ngẫu nhiên
    *temp = rand() % 101; // Gán giá trị ngẫu nhiên cho biến temp
    *humid = rand() % 101; // Gán giá trị ngẫu nhiên cho biến humid
    return 0; // Trả về 0 nếu không có lỗi
}

//Hàm để hiển thị kết quả ra màn hình nhúng/LED
void display_result(int temp, int humid) {
    printf("Temperature: %d C\n", temp); // In ra giá trị của nhiệt độ
    printf("Humidity: %d %%\n", humid); // In ra giá trị của độ ẩm
}

// hàm để điều khiển máy bơm nước
void control_pump(int temp, int humid) {
    // Đặt ngưỡng cho nhiệt độ và độ ẩm
    int temp_threshold = 30; // Nhiệt độ ngưỡng là 30 độ C
    int humid_threshold = 50; // Độ ẩm ngưỡng là 50 %

    // Kiểm tra xem có cần bật máy bơm nước hay không
    if (temp > temp_threshold || humid < humid_threshold) {
        printf("Pump is ON\n"); // In ra thông báo bật máy bơm nước
        // Gửi lệnh điều khiển đến một cổng giao tiếp để bật máy bơm nước
        // Giả sử rằng cổng giao tiếp là GPIO và mã lệnh là 1
        // Câu lệnh sau đây chỉ mang tính minh họa, bạn cần thay thế bằng câu lệnh thực tế cho hệ nhúng của bạn
        // gpio_write(GPIO_PIN, 1);
    } else {
        printf("Pump is OFF\n"); // In ra thông báo tắt máy bơm nước
        // Gửi lệnh điều khiển đến một cổng giao tiếp để tắt máy bơm nước

    }
}

// Hàm chính của chương trình
int main() {
    // Khai báo các biến để lưu trữ giá trị của nhiệt độ và độ ẩm
    int temp, humid;

    // Lặp vô hạn để thực hiện các công việc yêu cầu
    while (1) {
        // Đọc giá trị từ cảm biến nhiệt độ và độ ẩm
        read_sensor(&temp, &humid);

        // Hiển thị kết quả ra màn hình nhúng/LED
        display_result(temp, humid);

        // Điều khiển máy bơm nước
        control_pump(temp, humid);

        // Đợi một khoảng thời gian nhất định trước khi lặp lại
        // Giả sử rằng khoảng thời gian này là 10 giây
        sleep(5); // Hàm sleep sẽ dừng chương trình trong một số giây nhất định
    }

    return 0; // Kết thúc chương trình
}
