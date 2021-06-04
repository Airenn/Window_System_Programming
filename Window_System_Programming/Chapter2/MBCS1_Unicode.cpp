#include <stdio.h>
#include <string.h>

int main(void)
{
	wchar_t str[] = L"ABC";
	int size = sizeof(str); // sizeof는 함수가 아니라 연산자이므로 배열의 크기를 정확하게 계산해 반환해준다
	int len = strlen(str); // strlen 함수는  SBCS 기반 문자열 함수라 유니코드 문자열 str 처리 불가

	printf("배열의 크기 : %d \n", size);
	printf("문자열 길이 : %d \n", len);

	return 0;
}