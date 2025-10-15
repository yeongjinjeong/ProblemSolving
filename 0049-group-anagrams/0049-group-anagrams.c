/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    // 문자 정렬용 비교 함수
    int cmpChar(const void *a, const void *b) {
        return (*(char*)a - *(char*)b);
    }

    // 각 문자열의 정렬된 키 생성
    char **keys = (char**)malloc(sizeof(char*) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        int len = strlen(strs[i]);
        keys[i] = (char*)malloc(len + 1);
        strcpy(keys[i], strs[i]);
        qsort(keys[i], len, sizeof(char), cmpChar);
    }

    // used 배열을 동적 할당으로 변경
    int *used = (int*)calloc(strsSize, sizeof(int));

    // 결과 배열 초기화
    char ***result = (char***)malloc(sizeof(char**) * strsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);
    int groupCount = 0;

    for (int i = 0; i < strsSize; i++) {
        if (used[i]) continue;

        result[groupCount] = (char**)malloc(sizeof(char*) * strsSize);
        int count = 0;
        result[groupCount][count++] = strs[i];
        used[i] = 1;

        for (int j = i + 1; j < strsSize; j++) {
            if (used[j]) continue;
            if (strcmp(keys[i], keys[j]) == 0) {
                result[groupCount][count++] = strs[j];
                used[j] = 1;
            }
        }

        (*returnColumnSizes)[groupCount] = count;
        groupCount++;
    }

    *returnSize = groupCount;

    // 메모리 해제
    for (int i = 0; i < strsSize; i++)
        free(keys[i]);
    free(keys);
    free(used);

    return result;
}
