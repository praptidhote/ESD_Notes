#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

#define FILE_NAME "data.txt"

int main() {
    int pipefd[2];
    pipe(pipefd);

    // -------- P1 --------
    if (fork() == 0) {
        int fd = open(FILE_NAME, O_CREAT | O_WRONLY | O_TRUNC, 0644);
        char msg[] = "Temperature=28C\n";
        write(fd, msg, strlen(msg));
        close(fd);
        exit(0);
    }
    wait(NULL);

    // -------- P2 --------
    if (fork() == 0) {
        close(pipefd[0]);
        int fd = open(FILE_NAME, O_RDONLY);
        char buf[100];
        int n = read(fd, buf, sizeof(buf));
        write(pipefd[1], buf, n);
        close(fd);
        close(pipefd[1]);
        exit(0);
    }

    // -------- P3 --------
    if (fork() == 0) {
        execl("/bin/cp", "cp", FILE_NAME, "backup.txt", NULL);
        perror("exec");
        exit(1);
    }

    // -------- Parent --------
    close(pipefd[1]);
    char out[100];
    read(pipefd[0], out, sizeof(out));
    printf("Received: %s", out);
    close(pipefd[0]);

    wait(NULL);
    wait(NULL);
    return 0;
}
