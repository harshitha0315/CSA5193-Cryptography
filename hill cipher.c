#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void hill_encrypt(char *message, int key[2][2]) {
    int len = strlen(message);
    if (len % 2 != 0) {
        printf("Message length must be even for a 2x2 matrix.\n");
        return;
    }
    for (int i = 0; i < len; i++) {
        message[i] = toupper(message[i]);
    }
    for (int i = 0; i < len; i += 2) {
        int char1 = message[i] - 'A';
        int char2 = message[i + 1] - 'A';
        message[i] = (key[0][0] * char1 + key[0][1] * char2) % 26 + 'A';
        message[i + 1] = (key[1][0] * char1 + key[1][1] * char2) % 26 + 'A';
    }
}
int main() {
    char message[100];
    int key[2][2] = {{2, 1}, {3, 4}};
    printf("Enter the message to be encrypted (uppercase): ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;
    hill_encrypt(message, key);
    printf("Encrypted Message: %s\n", message);
    return 0;
}