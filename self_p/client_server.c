#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pipe(pipefd);

    // Child 1 (Client)
    if (fork() == 0) {
        close(pipefd[0]);
        int nums[2] = {10, 20};
        write(pipefd[1], nums, sizeof(nums));
        close(pipefd[1]);
        exit(0);
    }

    wait(NULL);

    // Parent (Server)
    close(pipefd[1]);
    int nums[2];
    read(pipefd[0], nums, sizeof(nums));
    int sum = nums[0] + nums[1];

    printf("Sum = %d\n", sum);

    // Child 2 (Exec display)
    if (fork() == 0) {
        char result[50];
        sprintf(result, "Sum is %d", sum);
        execl("/bin/echo", "echo", result, NULL);
        exit(1);
    }

    wait(NULL);
    return 0;
}
