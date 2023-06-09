#for i  in range(0, 11, 2):
# print (i)

'''
num = int(input('어디까지 계산할까요?'))
result1 = 0;
for i in range(1, num+1, 2):
   result1 += i

print (result1)


sec = int(input())
for i in range(sec, 0, -1):
    print(i, end =' ')
print ( '발사!!')


num = int(input("몇 단을 출력할까요? "))
for i in range(1, 10):
    print(f'{num} * {i} = {num*i}')


num = int(input("몇 줄? > "))
line = 1
for i in range(0, num):
    for j in range(0 ,line):
        print('*', end ='')
    line += 1
    print()


num = int(input("몇 줄? > "))
for i in range(num,  0, -1):
    for j in range(1 ,num+1):
        if i <= j:
            print('*' , end ='')
        else:
            print(' ', end='')
    print()


num = int(input("몇 줄? > "))
star = '*'
star2 = '**'
for i in range(num, 0, -1):
    for j in range(1, num + 1):
        if i <=  j:
            print(star)
            break;
        else:
            print(' ', end ='')
    star += star2

num = int(input("몇 줄? > "))
star = '*'
star2 = '**'
for i in range(1, num + 1):
      print(' ' * (num - i), '*' * i)

temp = list(map(int, input("숫자 여러개 입력").split()))
print(temp)
print(f'가장 큰 값 : {max(temp)}')
print(f'가장 작은 값 : {min(temp)}')
print(f'나머지 값의 평균 : {(sum(temp) - max(temp) - min(temp)) / (len(temp) - 2)}')
'''
'''
N, M = map(int, input().split())

S = {inp.ut() for _ in range(N)}
cnt = 0
for i in range(M):
    if input() in S:
        cnt += 1

print(cnt)
'''


'''
dic = {'Alice' : 85, 'Bob' : 90, 'Charlie' : 95}
print(dic)
dic['David'] = 80
print(dic)
dic['Alice'] = 88
print(dic)
del(dic['Bob'])
print(dic)
'''
'''
def check_machine():
    print(f'남은 음료수 : {vending_machine}')
    
def is_drink(b):
    if b not in vending_machine :
        return False
    else :
        return True

def add_drink():
    print('추가')
    b = input()
    if is_drink(b) :
        vending_machine.insert(vending_machine.index(liquid), b)
    else:
        vending_machine.append(b)     

def remove_drink(b):
    if is_drink(b) :
        del vending_machine[vending_machine.index(b)]
    else :
        print('없음')
       


vending_machine = ['게토레이', '레쓰비', '생수', '이프로']
check_machine()
while True :
    user = int(input('사용자 종류를 입력하세요 0 : 주인/ 1 : 소비자'))

    if user == 1 :
        b = input('마시고 싶은 음료? ')
        remove_drink(b)
        check_machine()
        
    elif user == 0:
        isAdd = int(input())
        if isAdd == 0 :
            add_drink()
            
        elif isAdd == 1:
            print('삭제')
            b = input()
            remove_drink(b)
        else:
            print("0 or 1 입력")
        print(f'남은 음료수 : {vending_machine}')
    else :
        print("0 or 1 입력")
'''
'''
temp = []
def Push(i):
    temp.insert(0,i)

def Top():
     if len(temp) == 0:
         print(-1)
     else:
        print(temp[0])
  

def Size():
    print(len(temp))
    
def Empty():
    if len(temp) == 0:
        print(1)
    else :
        print(0)
def Pop():
    if len(temp) == 0:
        print(-1)
    else:
        print(temp[0])
        del(temp[0])
        
N = int(input())
for i in range(N):
    s = input()
    if s == 'pop':
        Pop()
    elif s == 'size':
        Size()
    elif s == 'empty':
        Empty()
    elif s == 'top':
        Top()
    else:
        a, b= s.split()
        Push(b)
'''
N = int(input('숫자 입력 : '))
temp = {0:1, 1:1}
def myself(i):
    if i in temp :
        return temp[i]
    temp[i] = myself(i-2) + myself(i-1)
    return temp[i]

myself(N)
for i in temp.values():
    print(i, end= ' ')
    
    

