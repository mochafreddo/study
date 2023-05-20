# 출처 : 파이썬 알고리즘 인터뷰(박상길 지음)
# 유효한 팰린드롬
# 주어진 문자열이 팰린드롬인지 확인하라. 대소문자를 구분하지 않으며, 영문자와 숫자만을 대상으로 한다.

import collections
import re
from collections import deque


class Solution:
    # 리스트로 변환
    def isPalindrome(self, s: str) -> bool:
        strs = []
        for char in s:
            if char.isalnum():
                strs.append(char.lower())

        # 팰린드롬 여부 판별
        while len(strs) > 1:
            if strs.pop(0) != strs.pop():
                return False

        return True


class solution2:
    """리스트의 pop(0)이 O(n)인 데 반해, 데크의 popleft()는 O(1).
    각각 n번씩 반복하면, 리스트 구현은 O(n^2), 데크 구현은 O(n)으로 성능 차이가 크다.
    """

    # 데크 자료형을 이용한 최적화
    def isPalindrome(self, s: str) -> bool:
        # 자료형 데크로 선언
        strs: deque = collections.deque()

        for char in s:
            if char.isalnum():
                strs.append(char.lower())

        while len(strs) > 1:
            if strs.popleft() != strs.pop():
                return False

        return True


class Solution3:
    """내부적으로 C로 빠르게 구현되어 있어 훨씬 더 좋은 속도를 기대할 수 있다."""

    # 슬라이싱 사용
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        # 정규식으로 불필요한 문자 필터링
        s = re.sub("[^a-z0-9]", "", s)

        return s == s[::-1]  # 슬라이싱


class Solution4:
    """In this corrected version, we correctly use the compiled regex to
    substitute non-alphanumeric characters with an empty string. This reduces
    the number of intermediate strings created and improves performance when
    the function is called multiple times.
    """

    _alphanumeric_regex = re.compile("[^a-z0-9]")

    def isPalindrome(self, s: str) -> bool:
        if len(s) < 2:
            return True

        s = s.lower()
        s = self._alphanumeric_regex.sub("", s)

        return s == s[::-1]
