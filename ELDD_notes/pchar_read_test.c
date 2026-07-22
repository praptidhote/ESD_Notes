#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd, cnt;
    char ubuf[32];
    fd = open("/dev/pchar0", O_RDWR);
    printf("device file opened: fd=%d\n", fd);

    memset(ubuf, 0, sizeof(ubuf));
    cnt = read(fd, ubuf, 10);
    printf("device file read: %d bytes => %s\n", cnt, ubuf);

    close(fd);
    printf("device file closed\n");
    return 0;
}