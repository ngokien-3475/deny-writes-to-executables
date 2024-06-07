#include <stdio.h>
#include <sys/file.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main()
{
	int fd;
	char buf[16]={0};

	if(-1 == (fd = open("./text.txt", O_RDWR, 0666)))
	{
		printf("can not open file\n");
		return 0;
	} else 
	{
		printf("open file text.txt\n");
	}
	
	if(-1 == flock(fd, LOCK_EX | LOCK_NB))  // check khoá độc quyền (EX) có chưa nếu có rồi thì k thể ghi đc 
						// nếu chưa có thì có thể ghi vào 
						// (NB) để check 1 lần không cần chờ được mở khoá. nếu không có
						// thì chương trình sẽ chờ cho tới khi được mở khoá thì mới chạy tiếp
	{
		printf("can not write mothaiba \n");
	}else
	{
                if(write(fd,"mothaiba", strlen("mothaba")+1) > 0)    // hàm ghi vào file txt. nếu đúng thì trả về số kí tự in thành công , -1 là lỗi , 0 là khoong thể ghi
                {
                        printf("write mothaiba success\n");
                }

	}

		if(-1 == read(fd, buf, sizeof(buf)-1))     // hàm đọc file txt
		{
			printf("can not read file \n");
		} else
		{
			printf("%s\n", buf);
		}
	

	close(fd);

	return 0;
}

