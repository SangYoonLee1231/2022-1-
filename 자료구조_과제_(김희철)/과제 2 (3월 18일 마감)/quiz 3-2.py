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

n = len(string)

substring_lst = []  # 모든 부문자열을 저장하는 리스트입니다.
max_substr_len = 0  # 최장 부문자열의 길이를 나타내는 변수입니다.
max_substring_lst = []  # 모든 최장 부문자열을 저장하는 리스트입니다.

# 입력받은 문자열을 이중 for문을 통해 순회하여 모든 부문자열을 찾아 리스트 substring_lst에 저장합니다.
# 이 과정 중 부문자열의 최장 길이를 함께 조사하여 변수 max_substr_len에 저장합니다.
for i in range(n):
    for j in range(i + 1, n + 1):
        substring = string[i:j]
        if(is_palindrome(substring)):
            substring_lst.append(substring)
            if max_substr_len < len(substring):
                max_substr_len = len(substring)

# 저장된 부문자열 중 길이가 가장 긴 부문자열들만 따로 리스트 max_substring_lst에 저장합니다.
for elem in substring_lst:
    if len(elem) == max_substr_len:
        max_substring_lst.append(elem)

# 저장된 최장 부문자열들을 set을 이용하여 중복을 제거하고, 사전순으로 정렬한 후, 순서대로 출력합니다.
max_substring_set = set(max_substring_lst)
max_substring_lst = list(max_substring_set)
max_substring_lst.sort()
for elem in max_substring_lst:
    print(elem, end=" ")