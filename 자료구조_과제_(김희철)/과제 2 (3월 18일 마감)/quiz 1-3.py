# 4번
yy1, yy2 = tuple(map(int, input().split()))
first_day_of_yy1 = input()
week = ['월', '화', '수', '목', '금', '토', '일']

# 딕셔너리를 활용하여, yy1년 1월 1일의 요일이 week 리스트의 몇 번째 원소인지 계산합니다.
mapper = {
    '월' : 0,
    '화' : 1,
    '수' : 2,
    '목' : 3,
    '금' : 4,
    '토' : 5,
    '일' : 6
}

first_day_of_yy1 = mapper[first_day_of_yy1]


# 입력받은 '년(年)'이 윤년인지 확인하는 함수를 작성합니다.
def is_leap_year(y):
    if y % 400 == 0:
        return True
    
    if y % 100 == 0:
        return False

    if y % 4 == 0:
        return True
    
    return False


# yy1년 1월 1일부터 yy2년 1월 1일까지 전체 일수를 for문을 이용하여 계산합니다.
# 이 때, 윤년을 고려해서 전체 일수를 세고, 그 값을 7로 나눈 나머지를 활용하여,
# yy2년 1월 1일의 요일이 yy1년 1월 1일의 요일보다 며칠 후의 요일인지를 추정합니다.
total_day = 0

for current_y in range(yy1, yy2):
    if is_leap_year(current_y):
        total_day += 366
    else:
        total_day += 365

# yy2년 1월 1일의 요일을 구하여 한글로 출력합니다.
first_day_of_yy2 = (first_day_of_yy1 + (total_day % 7)) % 7
print(week[first_day_of_yy2])