#include <stdio.h>
#include <string.h>
void prepareKey(char key[], char *newKey) {
    int keyLen = strlen(key);
    int newKeyLen = 0;
    char used[26] = {0};
    for (int i = 0; i < keyLen; i++) {
        if (key[i] != ' ' && used[key[i] - 'A'] == 0) {
            newKey[newKeyLen++] = key[i];
            used[key[i] - 'A'] = 1;
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c != 'J' && used[c - 'A'] == 0) {
            newKey[newKeyLen++] = c;
            used[c - 'A'] = 1;
        }
    }
    newKey[newKeyLen] = '\0';
}
void findRowColumn(char key[], char c, int *row, int *col) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (key[i * 5 + j] == c) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void decryptPlayfair(char key[], char ciphertext[]) {
    char newKey[26];
    prepareKey(key, newKey);
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i += 2) {
        char a = ciphertext[i];
        char b = ciphertext[i + 1];
        int rowA, colA, rowB, colB;
        findRowColumn(newKey, a, &rowA, &colA);
        findRowColumn(newKey, b, &rowB, &colB);
        if (rowA == rowB) {
            colA = (colA - 1 + 5) % 5;
            colB = (colB - 1 + 5) % 5;
        } else if (colA == colB) {
            rowA = (rowA - 1 + 5) % 5;
            rowB = (rowB - 1 + 5) % 5;
        } else {
            int temp = colA;
            colA = colB;
            colB = temp;
        }
        printf("%c%c", newKey[rowA * 5 + colA], newKey[rowB * 5 + colB]);
    }
    printf("\n");
}
int main() {
    char key[] = "MONARCHY";
    char ciphertext[] = "ATTACK";
    printf("the output value is:");
    decryptPlayfair(key, ciphertext);
    return 0;
}