#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

int twoStacks(int maxSum, int a_count, int* a, int b_count, int* b) {
    int count = 0, sum = 0, x = 0, y = 0;

    while (x < a_count && (sum + a[x]) <= maxSum) {
        sum += a[x];
        x++;
        count++;
    }

    int maxi = count;

    while (y < b_count) {
        sum += b[y];
        y++;
        
        while (sum > maxSum && x > 0) {
            x--;
            sum -= a[x];
        }
        
        if (sum <= maxSum) {
           
            if(x+y>maxi ){
                maxi = x+y;
            }
            
        }
    }

    return maxi;
}



int main() {
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int g = parse_int(ltrim(rtrim(readline())));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        char** first_multiple_input = split_string(rtrim(readline()));

        int n = parse_int(*(first_multiple_input + 0));
        int m = parse_int(*(first_multiple_input + 1));
        int maxSum = parse_int(*(first_multiple_input + 2));

        char** a_temp = split_string(rtrim(readline()));
        int* a = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) a[i] = parse_int(*(a_temp + i));

        char** b_temp = split_string(rtrim(readline()));
        int* b = malloc(m * sizeof(int));
        for (int i = 0; i < m; i++) b[i] = parse_int(*(b_temp + i));

        int result = twoStacks(maxSum, n, a, m, b);
        fprintf(fptr, "%d\n", result);

        free(a);
        free(b);
        free(a_temp);
        free(b_temp);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
        if (!line) break;
        data_length += strlen(cursor);
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') break;
        alloc_length <<= 1;
        data = realloc(data, alloc_length);
        if (!data) return '\0';
    }

    if (data[data_length - 1] == '\n') data[data_length - 1] = '\0';
    else data = realloc(data, data_length + 1);
    return data;
}

char* ltrim(char* str) {
    if (!str || !*str) return str;
    while (*str != '\0' && isspace(*str)) str++;
    return str;
}

char* rtrim(char* str) {
    if (!str || !*str) return str;
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");
    int spaces = 0;
    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) return splits;
        splits[spaces - 1] = token;
        token = strtok(NULL, " ");
    }
    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') exit(EXIT_FAILURE);
    return value;
}