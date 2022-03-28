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
    # 짝이 모두 맞으면 1을, 그렇지 않으면 0을 반환한다.

    for elem in string:
        # 여는 괄호들은 스택에 삽입한다.
        if elem == '(' or elem =='{' or elem == '[':
            s.push(elem)

        # 닫는 괄호들은 우선 스택의 맨 위 요소를 확인한다.
        elif elem == ')' or elem == '}' or elem == ']':
            if s.empty():
                # 만일 스택이 비어있어 맨 위 요소를 확인할 수 없는 경우,
                # 현재 탐색 중인 닫는 괄호의 짝이 없다는 의미이므로 error이다.
                return 0
            else:
                # 스택에 요소가 있어 맨 위 요소를 확인할 수 있는 경우
                # 맨 위 요소가 현재 탐색 중인 닫는 괄호와 맞는 짝이면, 이를 pop한다.
                peek_ch = s.pop()
                if (elem == ')' and peek_ch !='(') or (elem == '}' and peek_ch != '{') or (elem == ']' and peek_ch != '['):
                    return 0
        else:
            # 괄호가 아니라면 무시
            pass

    # 문자열 탐색이 모두 끝났다.
    
    if s.empty():
        # 만일 스택에 남은 요소가 없다면, 모든 괄호의 짝이 맞았다는 뜻이다.
        return 1
    else:
        # 만일 스택에 요소가 남아있다면, 이들은 모두 짝이 맞지 않는 여는 괄호 (,{,[란 의미이다. (error 케이스)
        return 0


string = input()  # 문자열을 입력받는다.
s = Stack()  # 스택 객체 s를 선언한다.

ans = check(string)  # 입력받은 문자열을 check 함수를 통해 판정한다.

# 결과값을 출력한다.
print(ans)