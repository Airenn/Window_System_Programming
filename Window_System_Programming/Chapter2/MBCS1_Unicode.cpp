#include <stdio.h>
#include <string.h>

int main(void)
{
	wchar_t str[] = L"ABC";
	int size = sizeof(str); // sizeof�� �Լ��� �ƴ϶� �������̹Ƿ� �迭�� ũ�⸦ ��Ȯ�ϰ� ����� ��ȯ���ش�
	int len = strlen(str); // strlen �Լ���  SBCS ��� ���ڿ� �Լ��� �����ڵ� ���ڿ� str ó�� �Ұ�

	printf("�迭�� ũ�� : %d \n", size);
	printf("���ڿ� ���� : %d \n", len);

	return 0;
}