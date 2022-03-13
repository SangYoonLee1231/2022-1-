def is_palindrome(string):
    # 우선, 맨 앞자리와 맨 끝자리 문자를 서로 비교하고,
    # 그 다음 자리의 문자들을 서로 비교하는 식으로 회문 여부를 확인합니다.
    n = len(string)
    for i in range(n // 2):
        if(string[i] != string[n-1-i]):
            # 하나라도 같지 않으면 회문이 아닙니다.
            return False
    return True


# 문자열을 입력받습니다.
string = input()
# 대소문자를 구별하지 않으므로 입력받은 문자열을 모두 소문자로 바꿔줍니다.
string = string.lower()

# 문자열의 회문 여부를 확인하는 함수 is_palindrome를 이용하여 결과를 출력합니다.
if (is_palindrome(string)):
    print("yes")
else:
    print("no")