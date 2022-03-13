# 입력값을 각각의 배열에 저장합니다.
ans = list(map(int, input().split()))
worth = list(map(int, input().split()))
submit = list(map(int, input().split()))

# 제출한 답안지와 정답를 비교하여, 맞으면 해당 배점을 더하는 방식으로 총점을 계산합니다.
score = 0
for i in range(len(ans)):
    if ans[i] == submit[i]:
        score += worth[i]

# 계산한 총점을 출력합니다..
print(score)