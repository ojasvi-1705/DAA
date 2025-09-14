#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkAnagram(char *s1, char *s2) {
    if(strlen(s1) != strlen(s2)) return false;
    int count[256] = {0};
    for(int i = 0; s1[i]; i++) {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for(int i = 0; i < 256; i++) {
        if(count[i] != 0) return false;
    }
    return true;
}

int main() {
    char str1[] = "listen";
    char str2[] = "silent";
    if(checkAnagram(str1, str2)) printf("Anagram\n");
    else printf("Not Anagram\n");
    return 0;
}
