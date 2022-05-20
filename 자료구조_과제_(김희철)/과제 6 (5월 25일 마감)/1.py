class Student:
    def __init__(self,st_no, name):
        self.st_no = st_no
        self.name = name


class Student:
    def __init__(self):
        self.st_list = []
    
    def register(self, ...):
    
    def withdraw(self, ...):



while True:
    command = input().split()

    if command[0] == 'N':
        # 학번이 st_no인 학생이 수강 신청을 함
    elif command[0] == 'C':
        # 학번이 st_no인 학생이 수강 취소함
    elif command[0] == 'R':
        # 학번이 st_no인 학생의 정보를 출력
    elif command[0] == 'P':
        # 수강 학생들의 수와 학생들의 정보(학번, 이름)을 학번순서(오름차순)대로 출력
    elif command[0] == 'Q':
        # 끝내기
    else:
        print("잘못된 명령어입니다.")