n = int(input())

# 입력값 n이 완전수인지 판별하는 함수를 작성합니다.
def is_complete_num(m):
    divisor_sum = 0

    for j in range(1, m):
        if m % j == 0:
            divisor_sum += j
    
    if divisor_sum == m:
        return True
    else:
        return False

# 1부터 n까지 순차대로 탐색하여 완전수의 개수를 셉니다.
# 이 때, cnt 변수를 선언하여 0으로 초기화하고, is_complete_num 함수의 결과값이 True일 때마다 cnt의 값을 1씩 증가해나갑니다.
cnt = 0
for i in range(1, n + 1):
    if is_complete_num(i):
        cnt += 1

# 탐색을 마치고 결과를 출력합니다.
print(cnt)