#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg {
    long type;
    char text[100];
};

int main() {
    struct msg message;
    int msgid = msgget(1234, 0666 | IPC_CREAT);

    if (fork() == 0) {
        message.type = 1;
        strcpy(message.text, "Hello from child!");
        msgsnd(msgid, &message, sizeof(message.text), 0);
    } else {
        msgrcv(msgid, &message, sizeof(message.text), 1, 0);
        printf("Parent reads: %s\n", message.text);
        msgctl(msgid, IPC_RMID, NULL);
    }
    return 0;
}
