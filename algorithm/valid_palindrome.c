// 출처 : 파이썬 알고리즘 인터뷰(박상길 지음)
// 유효한 팰린드롬
// 주어진 문자열이 팰린드롬인지 확인하라.대소문자를 구분하지 않으며, 영문자와 숫자만을 대상으로 한다.

#include <stdbool.h>

// 문자열을 저장하는 char 포인터에 대한 직접 조작으로 가능한 한 빠르게 동작하도록 작성
// 필터링해야 하는 문자는 bias_left, bias_right 변수를 이용해 한 칸씩 건너뛰는 형태로 처리
bool isPalindrome(char *s)
{
    int bias_left = 0;
    int bias_right = 1;

    int str_len = strlen(s);
    for (int i = 0; i < str_len; i++)
    {
        // 스킵 포인터 처리
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

        if (i + bias_left >= str_len - i - bias_right)
            break;
        // 팰린드롬 비교
        if (tolower(s[i + bias_left]) != tolower(s[str_len - i - bias_right]))
            return false;
    }
    return true;
}

/*
In this revised version of the function:

1. I added a null-check for the input string `s` at the beginning of the
   function. This is to ensure that the function doesn't crash when trying to
   call `strlen` on a `NULL` pointer.

2. I added a check to ensure that both `*left` and `*right` are alphanumeric
   characters before comparing them. This is to make sure that the function
   correctly ignores non-alphanumeric characters, as was the intended
   functionality in your original code. This is particularly important when the
   string `s` contains only non-alphanumeric characters or if non-alphanumeric
   characters are at the ends of the string.

Note that in C, it's always a good idea to check that your pointers are not
`NULL` before dereferencing them, to prevent segmentation faults. However, in
this case, if the function is used correctly (i.e., it's never called with a
`NULL` argument), the initial null-check might not be necessary. This depends
on the specifics of your use case and your coding standards.
*/
bool isPalindrome(char *s)
{
    // Ensure that s is not NULL before calling strlen
    if (s == NULL)
        return false;

    char *left = s;
    char *right = s + strlen(s) - 1;

    while (left < right)
    {
        while (left < right && !isalnum(*left))
        {
            left++;
        }
        while (left < right && !isalnum(*right))
        {
            right--;
        }

        // Check if characters are alphanumeric before comparing
        if (isalnum(*left) && isalnum(*right) && tolower(*left) != tolower(*right))
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}
