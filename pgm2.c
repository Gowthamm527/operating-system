#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buf[1024];
    int source = open("input.txt", O_RDONLY);
    int target = open("output.txt", O_WRONLY | O_CREAT, 0644);

    int n;
    while ((n = read(source, buf, sizeof(buf))) > 0) {
        write(target, buf, n);
    }

    close(source);
    close(target);
    return 0;
}
