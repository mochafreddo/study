# 세 정수의 최댓값 구하기


def max(a, b, c):
    """a,b,c의 최댓값을 구하여 반환"""
    maximum = a
    if b > maximum:
        maximum = b
    if c > maximum:
        maximum = c
    return maximum  # 최댓값 반환


print(f"max(3, 2, 1) = {max(3, 2, 1)}")  # [A] a > b > c
print(f"max(3, 2, 2) = {max(3, 2, 2)}")  # [B] a > b = c
print(f"max(3, 1, 2) = {max(3, 1, 2)}")  # [C] a > c > b
print(f"max(3, 2, 3) = {max(3, 2, 3)}")  # [D] a = c > b
print(f"max(2, 1, 3) = {max(2, 1, 3)}")  # [E] c > a > b
print(f"max(3, 3, 2) = {max(3, 3, 2)}")  # [F] a = b > c
print(f"max(3, 3, 3) = {max(3, 3, 3)}")  # [G] a = b = c
print(f"max(2, 3, 1) = {max(2, 3, 1)}")  # [H] b > a > c
print(f"max(3, 2, 3) = {max(3, 2, 3)}")  # [I] a = c > b
print(f"max(1, 3, 2) = {max(1, 3, 2)}")  # [J] b > c > a
print(f"max(2, 3, 3) = {max(2, 3, 3)}")  # [K] b = c > a
print(f"max(1, 2, 3) = {max(1, 2, 3)}")  # [L] c > b > a
print(f"max(1, 3, 3) = {max(1, 3, 3)}")  # [M] b = c > a
