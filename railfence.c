#include <stdio.h>
#include <string.h>
void railFenceEncrypt(char text[]) {
    int rails = 2;
    int textLen = strlen(text);
    char encrypted[textLen];
    int idx = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = i; j < textLen; j += rails) {
            encrypted[idx++] = text[j];
        }
    }
    encrypted[idx] = '\0';
    printf("Encrypted Text: %s\n", encrypted);
}
int main() {
    char plaintext[] = "attackatonce";
    printf("Original Text: %s\n", plaintext);
    railFenceEncrypt(plaintext);
    return 0;
}
