#include <stdio.h>
#include <sys/file.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    char text[16] = {0};

    sprintf(text, "hello world \n");  // truyền hello vào biến text
    if (-1 == (fd = open("./text.txt", O_RDWR | O_CREAT, 0666))) {   // nếu chưa có thì tạo
        printf("can not create file\n");
        return 0;
    } else {
        printf("create file text.txt\n");
    }

    if (-1 == write(fd, text, sizeof(text))) {      // ghi hello vào file text.txt
        printf("can not write file \n");
        return 0;
    } else {
        printf("write file \n");
    }
	//LOCK_SH là LOCK share lOCK_EX là lock độc quyền chi 1 file có thể lock
    if (-1 == flock(fd, LOCK_SH)) {       // đặt key để khoá text.txt lại ( cái này giống như 
					  // như một biến toàn hệ thống để check mỗi lần truy
					  // cập vào file:
        perror("flock "); // log ra các lỗi hoặc thể hiện nó đã bị lock ở 1 file khác rồi
    } else {
        printf("set lock \n");
    }

    while(1){
    }
    close(fd);

    return 0;
}
