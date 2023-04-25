/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define concat(a, b) a ## b
#define macro_var(name) concat(name, __LINE__)
#define defer(start, end) for( \
    int macro_var(_i_) = (start, 0); \
    !macro_var(_i_);           \
    (macro_var(_i_) += 1), end) \

typedef struct Test {
    int x;
    int y;
} Test;

Test get_test(void) {
    Test test = {.x = 10, .y=20};
    return test;
}

int main()
{
    defer(0, printf("hello world\n")) {
        Test z = get_test();
        printf("%d %d\n", z.x, z.y);
    }
}
