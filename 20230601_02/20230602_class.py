'''
class 클래스명 :
    코드
    필드
    메소드
'''
'''
class Movie:
    count = 0
    #생성자
    def __init__(self, title):       
        print('생성자')

        #필드 선언
        self.title = title 
        self.audience = 2
        #private __ 사용
        self.__test = 'private'

        #protected _ 사용
        self._test2 = 'protected'
        
        Movie.count += 1

    def get_title(self):
        return self.__test

    def set_title(self, test):
        self__test = test
        
    def show_info(self):
        print(f'제목 : {self.title}, 관객수는 {self.audience}')

    def test():
        print(f'테스트')

class Caclue:
    def __init__(self, num1, num2):
        self.num1 = num1
        self.num2 = num2

    def Sum(self):
        return self.num1+ self.num2

    def Sub(self):
        return self.num1- self.num2

    def Mul(self):
        return self.num1 * self.num2

    def Div(self):
        return self.num1 / self.num2

movie1 = Movie('Movie')
movie1.show_info()

movie2 = Movie('Movie2')
movie2.show_info()

print(Movie.count)
print(movie1.count)
print(movie2.count)

num1, num2 = map(int, input().split())
c =  Caclue(num1, num2)
print(c.Sum())
print(c.Sub())
print(c.Mul())
print(c.Div())




class Supermarket:
    def __init__(self, loc, nm, product, customer):
        self.location = loc
        self.name = nm
        self.product = product
        self.customer = customer

    def print_location(self):
        print(self.location)

    def change_category(self, product):
        self.product = product

    def show_list(self):
        print(self.product)

    def enter_customer(self):
        self.customer += 1

    def show_info(self):
        print('-- show info --')
        print(f'가게 이름 :  {self.name}')
        print(f'위치 :  {self.location}')
        print(f'파는 물건 :  {self.product}')
        print(f'손님 수 :  {self.customer}')
        print('-- -- --')


s = Supermarket('한국', '신발 상점', '구두', 0)
s.print_location()
s.show_list()
s.change_category('운동화')
s.show_info()
s.enter_customer()
s.show_info()
'''

'''
class Character:
    def __init__(self, name):
        self.name = name
        self.level = 0
        self.item_num = 0

    def change_name(self, name):
        self.name = name

    def level_up(self):
        self.level += 1

    def use_item(self):
        self.item_num -= 1
        if self.item_num < 0 : self.item_num = 0

    def get_item(self):
        self.item_num += 1

    def show_info(self):
        print(f'이름 : {self.name}')
        print(f'Level : {self.level}')
        print(f'item : {self.item_num}')


name = input("이름 입력")
c = Character(name)

while True :
    num = int(input('명령 입력 : '))

    if num == 0:
        print('종료')
        break;
    elif num == 1:
        name = input('새 이름 입력 : ')
        c.change_name(name)
    elif num == 2:
        c.level_up()
    elif num == 3:
        c.get_item()
    elif num == 4:
        c.use_item()
    elif num == 5:
        c.show_info()
'''
'''
class Caculator:
    def __init__(self):
        self.value = 100

    def sub(self, value):
        self.value -= value

class MinLimitCaculator(Caculator):
    def __init__(self):
        super().__init__()

    def sub(self, value):
        super().sub(value)
        if self.value < 0 : self.value = 0

cal = MinLimitCaculator()
cal.sub(20)
print(cal.value)
cal.sub(90)
print(cal.value)



class Shape:
    def __init__(self, cnt, length):
        self.line_cnt = cnt
        self.underline_len = length

    def printInfo(self):
        print (f'변의 개수 : {self.line_cnt} / 밑변의 길이 : {self.underline_len}')

class Rectangle(Shape):
    def __init__(self, length, height):
        super().__init__(4, length)
        self.height = height

    def area(self):
        return self.underline_len * self.height

class Triangle(Shape):
    def __init__(self, length, height):
        super().__init__(3, length)
        self.height = height

    def area(self):
        return self.underline_len * self.height / 2


s = Rectangle(5, 2)
print(s.area())
s.printInfo()

t = Triangle(5, 2)
print(t.area())
t.printInfo()
'''
num = int(input())
if num == 0:
    print('숫자 0')
elif num % 2 == 0:
    print("짝수")
else:
    print("홀수")

















