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

    // 각 문자열의 정렬하여 저장
    char **sorted_str = (char**)malloc(sizeof(char*) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        int len = strlen(strs[i]);
        sorted_str[i] = (char*)malloc(len + 1);
        strcpy(sorted_str[i], strs[i]);
        qsort(sorted_str[i], len, sizeof(char), cmpChar);
    }

    // 그룹에 포함 되었는지 표시
    int *used = (int*)calloc(strsSize, sizeof(int));

    // 결과 배열
    char ***result = (char***)malloc(sizeof(char**) * strsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);
    int groupCount = 0;

    for (int i = 0; i < strsSize; i++) {
        //각 그룹의 첫번째 문자열 등록
        if (used[i]) continue;
        result[groupCount] = (char**)malloc(sizeof(char*) * strsSize);
        int count = 0;
        result[groupCount][count++] = strs[i];
        used[i] = 1;

        //이후 정렬된 값이 같은 것들을 그룹에 등록
        for (int j = i + 1; j < strsSize; j++) {
            if (used[j]) continue;
            if (strcmp(sorted_str[i], sorted_str[j]) == 0) {
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
        free(sorted_str[i]);
    free(sorted_str);
    free(used);

    return result;
}
