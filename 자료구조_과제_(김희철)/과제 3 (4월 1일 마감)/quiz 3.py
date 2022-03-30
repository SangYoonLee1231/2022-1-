'''
import sys

data = sys.stdin.readlines()
print(data)
'''

class Stack():
    # Stack을 클래스로 미리 구현하였다.
    def __init__(self):
        self.items = []
    
    def push(self, item):
        self.items.append(item)

    def pop(self):
        try:
            return self.items.pop()
        except IndexError:
            print("Stack is empty");
    
    def top(self):
        try:
            return self.items[-1]
        except IndexError:
            print("Stack is empty")

    def size(self):
        return len(self.items)

    def empty(self):
        return not self.items
        # return not self.items


def check(string):
    # 입력받은 문자열 내 괄호들이 모두 짝이 맞는지 검사하는 함수이다.
    # error_idx값과 error_num값, 총 2개의 반환값을 갖는다.

    global error_idx, error_num
    # error_idx : 에러가 처음 발생한 괄호의 인덱스

    # error_num : error 번호
    # error_num == 0 : 모든 괄호가 짝이 맞음 (error 아님)
    # error_num == 1 : )에 대응하는 (가 없을 경우
    # error_num == 2 : }에 대응하는 {가 없을 경우
    # error_num == 3 : ]에 대응하는 [가 없을 경우
    # error_num == 4 : (에 대응하는 )가 없을 경우
    # error_num == 5 : {에 대응하는 }가 없을 경우
    # error_num == 6 : [에 대응하는 ]가 없을 경우


    # 입력받은 문자열을 순차적으로 탐색한다.
    for i, elem in enumerate(string):
        # 여는 괄호들을 스택에 삽입한다.
        # 이 떄 그 괄호가 어느 위치의 괄호인지 알 수 있도록, 인덱스 값과 함꼐 튜플로 묶어 스택에 삽입한다.
        if elem == '(' or elem =='{' or elem == '[':
            s.push((i, elem))
        
        # 닫는 괄호들은 우선 스택의 맨 위 요소를 확인한다.
        elif elem == ')' or elem == '}' or elem == ']':
            # 만일 스택이 비어있어 맨 위 요소를 확인할 수 없는 경우,
            # 현재 탐색 중인 닫는 괄호의 짝이 없다는 의미이므로 error이다.
            if s.empty():
                if elem == ')':
                    error_num = 1
                    return i, error_num
                if elem == '}':
                    error_num = 2
                    return i, error_num
                if elem == ']':
                    error_num = 3
                    return i, error_num

            # 스택에 요소가 있어 맨 위 요소를 확인할 수 있는 경우
            else:
                # 맨 위 요소가 현재 탐색 중인 닫는 괄호와 맞는 짝이면, 이를 pop한다.
                _, peek_ch = s.pop()

                # 그렇지 않으면 error이다.
                if (elem == ')' and peek_ch !='('):
                    error_num = 1
                    return i, error_num
                if (elem == '}' and peek_ch != '{'):
                    error_num = 2
                    return i, error_num
                if (elem == ']' and peek_ch != '['):
                    error_num = 3
                    return i, error_num
                # 위의 세 경우 모두 아나리면 정상적으로 pop 수행

        else:
            # 탐색 중인 요소가 괄호가 아니라 공백 or 다른 문자일 경우 그냥 무시한다.
            pass
    
    # 문자열 탐색이 모두 끝났다.

    # 만일 스택에 남은 요소가 없다면, 모든 괄호의 짝이 맞았다는 뜻이다.
    if s.empty():
        return None, 0
    
    # 만일 스택에 요소가 남아있다면, 이들은 모두 짝이 맞지 않는 여는 괄호 (,{,[란 의미이다. (error 케이스)
    else:
        # 이 중 스택의 가장 위에 있는 요소가 제일 먼저 발견된, 짝 없는 괄호이다.
        idx, peek_ch = s.pop()

        if peek_ch == '(':
            error_num = 4
            return idx, error_num
        elif peek_ch == '{':
            error_num = 5
            return idx, error_num
        elif peek_ch == '[':
            error_num = 6
            return idx, error_num
        else: pass


string = input()  # 문자열을 입력받는다.

s = Stack()  # 스택 객체 s를 선언한다.
error_idx = 0; error_num = 0

error_idx, error_num = check(string)  # 입력받은 문자열을 check 함수를 통해 판정한다.

# error_num == 0 : error 발생 X, 모든 괄호의 짝이 맞음, 1을 출력한다.
if error_num == 0:
    print(1)

# error_num == 1~6 : error 발생, error_idx값과 error_num값을 출력한다.
else:
    print(f"{error_idx}  error{error_num}")