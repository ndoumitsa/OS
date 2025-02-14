#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("pids.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);  // Open file in append mode

    if (fd < 0) {
        perror("File open failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        dprintf(fd, "Child PID: %d\n", getpid());
    } else {
        // Parent process
        dprintf(fd, "Parent PID: %d\n", getpid());
    }

    close(fd);  // Close the file
    return 0;
}
