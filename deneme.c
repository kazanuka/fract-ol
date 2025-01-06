
#include <stdio.h>
#include <ctype.h>

int is_number(const char *str) {
    int i = 0;
    int has_decimal = 0;

    if (str == NULL || *str == '\0') {
        return 0;
    }
    if (str[i] == '+' || str[i] == '-') {
        i++;
    }

    while (str[i] != '\0') {
        if (str[i] == '.') {
            if (has_decimal) {
                return 0;  
            }
            has_decimal = 1; 
        } else if (!isdigit((unsigned char)str[i])) {
            return 0; 
        }
        i++;
    }
    return 1; 
}


    int main() {
    const char *test1 = "123";
    const char *test2 = "123.456";
    const char *test3 = "123a";
    const char *test4 = "123.456.789";
    const char *test5 = "-123.456";
    const char *test6 = "+123";

    printf("Test 1: %s -> %d\n", test1, is_number(test1));
    printf("Test 2: %s -> %d\n", test2, is_number(test2));
    printf("Test 3: %s -> %d\n", test3, is_number(test3));
    printf("Test 4: %s -> %d\n", test4, is_number(test4));
    printf("Test 5: %s -> %d\n", test5, is_number(test5));
    printf("Test 6: %s -> %d\n", test6, is_number(test6));

    return 0;
}

