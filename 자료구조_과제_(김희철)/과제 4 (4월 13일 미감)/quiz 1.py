# Node 클래스 구현
class Node:
    def __init__(self, val):
        self.data = val
        self.link = None

# Linked 스택 클래스 구현
class LinkedStack:
    def __init__(self):
        self.top = None
    
    # 비어있는가?
    def isEmpty(self):
        return self.top == None
    
    # 삽입
    def push(self, val):
        newNode = Node(val)
        newNode.link = self.top
        self.top = newNode
    
    # 삭제 후 반환 (pop)
    def pop(self):
        if self.isEmpty():
            return None
        e = self.top.data
        self.top = self.top.link
        return e
        

# 덧셈 함수
def add(a, b):
    return a + b

# 뺼셈 함수
def sub(a, b):
    return a - b

# 곰셈 함수
def mul(a, b):
    return a * b

# 몫 반환 함수
def div_quo(a, b):
    return a // b

# 나머지 반환 함수
def div_rem(a, b):
    return a % b

# 후위 표기 수식을 받아 결과값을 계산하는 함수
def func(postfix_lst):
    # 후위 표기 수식의 각 요소를 순서대로 탐색
    for elem in postfix_lst:
        # 요소가 연산자라면, 스택에서 두 요소를 pop해 해단 연산 수행
        if elem == '+' or elem == '-' or elem == '*' or elem == '//' or elem == '%':
            op = elem
            opr2 = ls.pop()
            opr1 = ls.pop()

            # pop할 요소(수)가 없다면, 후위 표기 수식에 오류 존재
            if opr2 == None or opr1 == None:
                return None

            # math_func 딕셔너리를 활용하여 계산
            ls.push(math_func[op](opr1, opr2))

        # 맨 끝에 있는 ';'는 무시
        elif elem == ';':
            pass
        
        # 요소가 숫자라면, 스택에 push
        else:
            ls.push(int(elem))

    # 탐색이 끝났으면 스택엔 최종 결과값 하나만 있어야 한다.
    # 이를 pop해 반환            
    ans = ls.pop()

    if ls.isEmpty:
        return ans
    else:
        # 요소에 ans 외 다른 요소가 있다면, 후외 표기 수식에 오류 존재
        return None



# main 함수 시작

# 계산을 도울 math_func 딕셔너리 정의
math_func = {
    '+' : add,
    '-' : sub,
    '*' : mul,
    '//' : div_quo,
    '%' : div_rem
}

# ls Linked 스택을 정의하고, 후위 표기 수식을 입력 받음
ls = LinkedStack()
postfix_lst = list(input().split())

# 입력 받은 후위 표기 수식을 func 함수로 넘겨 답 계산
ans = func(postfix_lst)

# 답이 None이라면 후위 표기 수식에 오류가 있다는 의미이므로 오류 출력, 그렇지 않으면 정답 출력
if ans == None:
    print("error")
else:
    print(ans)
    