#include <stdio.h>
#include <string.h>

#define MAX 128

void shiftTable(char *p, int *shifts) {
    int m = strlen(p);
    for (int i = 0; i < MAX; i++) {
        shifts[i] = m;  
    }
    for (int j = 0; j < m - 1; j++) {
        shifts[(int)p[j]] = m - 1 - j;  
    }
}

int horspool(char *text, char *pattern) {
    int m = strlen(pattern);
    int n = strlen(text);
    int shifts[MAX];

    shiftTable(pattern, shifts);

    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
        }
        if (k == m) {
            return i - m + 1;  
        } else {
            i += shifts[(int)text[i]];  
        }
    }
    return -1;  
}

int main() {
    char text[] = "Jim saw me in a Barber shop";
    char pattern[] = "Barber";
    
    int position = horspool(text, pattern);
    
    if (position != -1) {
        printf("Pattern found at position %d\n", position);
    } else {
        printf("Pattern not found\n");
    }
    
    return 0;
}
