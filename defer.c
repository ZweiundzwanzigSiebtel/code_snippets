#include <stdio.h>

#define concat(a, b) a ## b
#define macro_var(name) concat(name, __LINE__)
#define defer(start, end) for( \
    int macro_var(_i_) = (start, 0); \
    !macro_var(_i_);           \
    (macro_var(_i_) += 1), end) \

int main() {
    FILE *fp = fopen("example.txt", "w");
    if (fp == NULL) {
        printf("couldn't open file");
        return 1;
    }

    defer(0, fclose(fp))
    {
        fprintf(fp, "hello world");
        // more code could go here...
    }

    return 0;
}
