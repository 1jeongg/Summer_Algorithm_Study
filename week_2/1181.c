#include <stdio.h>
#include <string.h> // strcmp를 사용하기 위해
#include <stdlib.h> // quick sort를 사용하기 위해
int sorting(const void *a, const void *b);

typedef struct {
    char str[51];
    int len;
}Str;		//문자열과 문자열의 길이를 구조체 배열로 저장

int main(){
    int N, i, min = 0, max = 0;
    
    scanf("%d", &N);		//몇개를 입력받을지 입력
    Str s[N];
    
    for (i = 0; i < N; i++){		//우선 입력받은 문자열의 길이를 저장
        scanf("%s", s[i].str);
        s[i].len = strlen(s[i].str);
    }
    
    qsort(s, N, sizeof(Str), sorting);		// quick sort 기능을 사용하여 정렬 
    puts(s[0].str);             // 같은 단어라도 한 번은 무조건 출력되어야 하므로
    for (i = 1; i < N; i++)
        if (strcmp(s[i-1].str, s[i].str))
            puts(s[i].str);				// 출력 
}

int sorting(const void *a, const void *b){		
    Str s1 = *(Str*)a, s2 = *(Str*)b;
    if (s1.len < s2.len)			// 첫번째 변수가 두번째 변수보다 작기 때문에 -1 반환 
        return -1;
        
    else if (s1.len > s2.len)
        return 1;					// 첫번째 변수가 두번째 변수보다 크기 때문에 1 반환 
        
    return strcmp(s1.str, s2.str);
}
