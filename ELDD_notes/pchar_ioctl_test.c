#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "pchar.h"

int main(int argc, char *argv[]) {
    int fd, ret;
    if(argc < 2) {
        printf("ERROR: %s clear|info|resize \n", argv[0]);
        exit(1);
    }
    fd = open("/dev/pchar0", O_RDWR);
    if(fd < 0) {
        perror("failed to open device:");
        exit(2);
    }
    
    if(strcmp(argv[1], "clear") == 0) {
        ret = ioctl(fd, FIFO_CLEAR);
        printf("ioctl() fifo clear returned: %d\n", ret);
    }
    
    else if(strcmp(argv[1], "info") == 0) {
        info_t info;
        ret = ioctl(fd, FIFO_GET_INFO, &info);
        printf("ioctl() fifo get info returned: %d\n", ret);
        if(ret == 0)
            printf("fifo size=%d\nfifo len=%d\nfifo avail=%d\n", 
                info.size, info.len, info.avail);
    }
    
     else if(strcmp(argv[1], "resize") == 0) {
        if(argc < 3) {
            printf("ERROR: resize requires a size argument. E.g., resize 64\n");
            close(fd);
            exit(3);
        }
        int new_size = atoi(argv[2]);
        ret = ioctl(fd, FIFO_RESIZE, &new_size);
        printf("ioctl() fifo resize returned: %d\n", ret);
    }
    else
        printf("invalid fifo ioctl command.\n");
    
    close(fd);
    return 0;
}