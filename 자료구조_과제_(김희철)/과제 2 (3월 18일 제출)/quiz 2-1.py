ans = list(map(int, input().split()))
worth = list(map(int, input().split()))
submit = list(map(int, input().split()))

score = 0
for i in range(len(ans)):
    if ans[i] == submit[i]:
        score += worth[i]

print(score)