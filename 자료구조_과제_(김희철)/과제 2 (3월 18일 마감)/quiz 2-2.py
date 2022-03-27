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


# 출력1. 최고 성적을 출력합니다.
max_score = score_lst[0][0]
print(max_score)