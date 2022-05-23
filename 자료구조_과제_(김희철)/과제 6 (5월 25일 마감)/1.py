class Student:
    def __init__(self, st_no, name):
        self.st_no = st_no
        self.name = name


class Course:
    def __init__(self):
        self.st_list = []


    def register(self, st_no, name):
        self.st_list.append(Student(st_no, name))


    def withdraw(self, st_no):
        idx = -1
        for i, elem in enumerate(self.st_list):
            if st_no == elem.st_no:
                idx = i
                break
        del(self.st_list[idx])


    def display(self, st_no):
        idx = -1
        for i, elem in enumerate(self.st_list):
            if st_no == elem.st_no:
                idx = i
                break


    def display_all(self):
        temp_list = self.st_list.copy()
        temp_list.sort(key=lambda x: x.st_no)
        
        for elem in enumerate(temp_list):
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
        # 끝내기
    else:
        print("잘못된 명령어입니다.")