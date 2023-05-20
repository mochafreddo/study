// 다음은 이 코드를 디버그 모드로 살펴볼 수 있는 테스트 코드입니다. "TestString1"이라는 문자열을 이용하여 팰린드롬을 확인하는
// 간단한 테스트를 진행하며, 각 단계에서의 i, bias_left, bias_right, s[i + bias_left] 및
// s[str_len - i - bias_right] 값을 출력하도록 합니다.

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *s)
{
    int bias_left = 0;
    int bias_right = 1;

    int str_len = strlen(s);
    for (int i = 0; i < str_len; i++)
    {
        while (!isalnum(s[i + bias_left]))
        {
            bias_left++;
            if (i + bias_left == str_len)
                return true;
        }
        while (!isalnum(s[str_len - i - bias_right]))
        {
            bias_right++;
        }

        printf("i: %d, bias_left: %d, bias_right: %d, left char: %c, right char: %c\n", i, bias_left, bias_right, s[i + bias_left], s[str_len - i - bias_right]);

        if (i + bias_left >= str_len - i - bias_right)
            break;
        if (tolower(s[i + bias_left]) != tolower(s[str_len - i - bias_right]))
            return false;
    }
    return true;
}

int main()
{
    char TestString1[] = "A man, a plan, a canal: Panama";
    bool result = isPalindrome(TestString1);
    printf("Is the string a palindrome? %s\n", result ? "True" : "False");

    return 0;
}

// 이 코드를 실행하면 각 단계에서 문자열의 양 끝에서부터 시작하여 비교하는 문자와 bias_left, bias_right 값을 확인할 수
// 있습니다. 또한, 마지막에 "Is the string a palindrome?"이라는 문장이 출력되며, 이는 문자열이 팰린드롬인지
// 아닌지를 알려줍니다. 이 문자열은 팰린드롬이므로 "True"가 출력됩니다.