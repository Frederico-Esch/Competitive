#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool try_match(char * s, char * goal, size_t begin) {
    size_t len = strlen(s);
    for(size_t i = 0; i < len; i++){
        if (s[(i+begin)%len] != goal[i]) {
            return false;
        }
    }
    return true;
}

bool rotateString(char * s, char * goal) {
    size_t len = strlen(s);
    char first = goal[0];

    for (size_t i = 0; i < len; i++){
        if (s[i] == first){
            if (try_match(s, goal, i)) return true;
        }
    }

    return false;
}


int main() {
    printf("%d\n", rotateString("abcde", "cdeab"));
    printf("%d\n", rotateString("abcde", "abced"));
    return 0;
}
