class Node:
    def __init__(self, val):
        self.data = val
        self.link = None

class LinkedStack:
    def __init__(self):
        self.top = None
    
    def isEmpty(self):
        return self.top == None
    
    def push(self, val):
        newNode = Node(val)
        newNode.link = self.top
        self.top = newNode
    
    def pop(self):
        if self.isEmpty == None:
            return "Empty"
        e = self.top.data
        self.top = self.top.link
        return e
        


def add(a, b):
    return a + b

def sub(a, b):
    return a - b

def mul(a, b):
    return a * b

def div_quo(a, b):
    return a // b

def div_rem(a, b):
    return a % b


def func(postfix_lst):
    for elem in postfix_lst:
        if type(elem) is int:
            ls.push(elem)
        else:
            op = elem
            opr2 = ls.pop()
            opr1 = ls.pop()

            if opr2 == "Empty" or opr1 == "Empty":
                return None

            ls.push(math_func[op](opr1, opr2))
    
    ans = ls.pop()

    if ls.isEmpty:
        return ans
    else:
        return None


math_func = {
    '+' : add,
    '-' : sub,
    '*' : mul,
    '//' : div_quo,
    '%' : div_rem
}


ls = LinkedStack()
postfix_lst = list(input().split())

ans = func(postfix_lst)

if ans == None:
    print("Stack is Empty")
else:
    print(ans)
    