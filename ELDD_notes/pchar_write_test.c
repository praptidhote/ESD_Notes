#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd, cnt;
    char ubuf[32]="";
    fd = open("/dev/pchar0", O_RDWR);
    printf("device file opened: fd=%d\n", fd);
    cnt = write(fd, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26);
    printf("device file written: %d bytes\n", cnt);
    close(fd);
    printf("device file closed\n");
    return 0;
}