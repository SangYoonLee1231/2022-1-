def is_palindrome(string):
    # 우선, 맨 앞자리와 맨 끝자리 문자를 서로 비교하고,
    # 그 다음 자리의 문자들을 서로 비교하는 식으로 회문 여부를 확인합니다.
    n = len(string)
    for i in range(n // 2):
        if(string[i] != string[n-1-i]):
            # 하나라도 같지 않으면 회문이 아닙니다.
            return False
    return True