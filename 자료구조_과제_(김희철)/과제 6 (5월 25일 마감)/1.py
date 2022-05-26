# 학생의 정보를 저장하는 학생 클래스
class Student:
    def __init__(self, st_no, name):
        self.st_no = st_no
        self.name = name


# 수강생을 관리하는 코스 클래스
class Course:
    def __init__(self):
        self.st_list = []

    # 수강생 등록 (수강 신청)
    def register(self, st_no, name):
        self.st_list.append(Student(st_no, name))

    # 수강생 삭제 (수강 취소)
    def withdraw(self, st_no):
        idx = -1
        for i, elem in enumerate(self.st_list):
            if st_no == elem.st_no:
                idx = i
                break
        del(self.st_list[idx])

    # 특정 학번 학생의 정보 출력
    def display(self, st_no):
        idx = -1
        for i, elem in enumerate(self.st_list):
            if st_no == elem.st_no:
                idx = i
                print(self.st_list[idx].st_no, self.st_list[idx].name)
                break

    # 모든 학생의 정보를 학번의 오름차순으로 출력
    def display_all(self):
        temp_list = self.st_list.copy()
        temp_list.sort(key=lambda x: x.st_no)
        
        print(len(self.st_list))
        for elem in temp_list:
            print(elem.st_no, elem.name)



course = Course()

while True:
    command = input().split()

    if command[0] == 'N':
        # 학번이 st_no인 학생이 수강 신청을 함
        st_number = command[1]
        st_name = command[2]
        course.register(st_number, st_name)

    elif command[0] == 'C':
        # 학번이 st_no인 학생이 수강 취소함
        st_number = command[1]
        course.withdraw(st_number)

    elif command[0] == 'R':
        # 학번이 st_no인 학생의 정보를 출력
        st_number = command[1]
        course.display(st_number)

    elif command[0] == 'P':
        # 수강 학생들의 수와 학생들의 정보(학번, 이름)을 학번순서(오름차순)대로 출력
        course.display_all()

    elif command[0] == 'Q':
        break
        # 끝내기
    else:
        print("잘못된 명령어입니다.")