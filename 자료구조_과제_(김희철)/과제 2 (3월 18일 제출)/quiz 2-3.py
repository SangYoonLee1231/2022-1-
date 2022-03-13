# 입력값을 각각의 배열에 담습니다.
ans = list(map(int, input().split()))
worth = list(map(int, input().split()))

# 각각의 답안지들은 2차원 리스트에 1차원 리스트의 형태로 담습니다.
n = int(input())
submit_lst = [
    list(map(int, input().split()))
    for _ in range(n)
]

# 각 답안지의 점수를 담을 리스트를 미리 선언합니다.
score_lst = []


# 각 답안지와 정답을 비교하여 점수를 계산합니다.
# 그리고 그 점수와 해당 id를 하나로 묶어 리스트 score_lst에 차례대로 저장합니다.
for i in range(n):
    score = 0
    for j in range(len(ans)):
        if ans[j] == submit_lst[i][j+1]:
            score += worth[j]
    score_lst.append([score, submit_lst[i][0]])

# 점수 리스트를 점수값에 따라 내림차순으로 정렬합니다.
score_lst.sort(key=lambda x: -x[0])
# 그럼 첫번째 원소에 최고점을 받은 학생의 정보가 위치하게 됩니다.


# 출력1. 최고 성적 출력
max_score = score_lst[0][0]
print(max_score)

# 출력2. 최고 성적 출력
# 우선, 최고 성적을 받은 id를 담을 리스트를 선언합니다.
max_score_id_lst = []

# 최고 성적을 받은 id를 리스트에 담습니다.
i = 0
while max_score == score_lst[i][0]:
    max_score_id_lst.append(score_lst[i][1])
    i += 1

# 받은 리스트를 정렬하여 출력합니다.
max_score_id_lst.sort()

for elem in max_score_id_lst:
    print(elem, end=" ")


'''
# [문제 수정 전]

# 입력값을 각각의 배열에 담습니다.
ans = list(map(int, input().split()))
worth = list(map(int, input().split()))

# 각각의 답안지들은 2차원 리스트에 1차원 리스트의 형태로 담습니다.
n = int(input())
submit_lst = [
    list(map(int, input().split()))
    for _ in range(n)
]

# 걱 문제 별 정답률을 담을 리스트를 미리 선언해, 0으로 초기화합니다.
correct_rate = [0] * len(ans)


# 각 문제 별 정답률을 계산하여 correct_rate 리스트에 넣습니다.
for i in range(len(ans)):
    for j in range(n):
        if ans[i] == submit_lst[j][i+1]:
            correct_rate[i] += (1 / n)


# 출력 1. 최소 정답률을 min 내장함수를 통해 찾고, 이를 출력합니다.
# (% 단위로 치환, 반올림하여 소수 첫째 자리까지)
lowest_correct_rate = min(correct_rate)
print(f"{(lowest_correct_rate * 100):.1f}")

# 출력 2. 최소 정답률인 모든 문제의 번호를 오름차순으로 출력합니다.
for i, elem in enumerate(correct_rate, start=1):
    if elem <= lowest_correct_rate:
        print(i, end=" ")
'''