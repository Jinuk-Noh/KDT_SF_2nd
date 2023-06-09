# #리스트
# a = []
# b = [1, 2, 3]
# c = ['a', 'b', 'c']
# d = [1, 2, 'a', 'b']

# print("a 리스트 : ",a)
# print("b 리스트 : ",b)
# print("c 리스트 : ",c)
# print("d 리스트 : ",d)

# # 슬라이싱
# a = [9,4,2,5,25,6,7]
# print("a[3] : ",a[3])
# print("a[:3:] : ",a[:3:])
# print("a[-1] : ",a[-1])
# print("a[::2] :",a[::2])

# # +, * 연산
# a = [1 , 2, 3, 4]
# b = [2, 3, 4, 5]
# c = a + b
# print("c : ",c)
# d= [0] * 3
# print("d :",d)
# e = a * 2
# print("e : ",e)

# 함수
# 추가/ 삭제
# a = [1, 2, 3, 5, 6]
# a.append(5)
# print("append 함수 : ",a)
# a.remove(5)
# print("rmove 함수 : ", a)

# a = [1, 2, 3, 5, 6, 10, 12,50, 55, 32, 70]
# a.insert(2,'a')
# print("insert : ", a)
# a.pop()
# print("pop : ", a)
# a.pop(2)
# print("pop(index) : ", a)
# del a[0]
# print("del a[1] :", a)
# del a[2:4]
# print("del a[2:4] :", a)

a = [9, 5, 2, 5, 1, 3 ,7]

print('len : ', len(a))
print('count : ', a.count(5))
print('index : ', a.index(5))

# print('sorted(reverse) : ',sorted(a, reverse= True)) # b = sorted(a)
# print('sorted : ',a)

# a.sort(reverse=True)
# print('sort(reverse = ) : ', a)

# a = [ 1, 2, 3]
# b = ( 1, 2, 3)

# a[0] = 9
# print('a :', a)

#b[0] = 9 error 발생

# numbers = {1, 2, 3, 3, 5, 6, 8}

# #요소 추가
# numbers.add(56)
# print('add : ', numbers)

# #특정 요소 삭제
# numbers.remove(1)
# print('remove : ', numbers)

# #임의 요소 삭제
# numbers.pop()
# print('pop : ', numbers)

# #모든 요소 삭제
# numbers.clear()
# print('clear : ', numbers)

# { 키 : 값 }
# dict1 = { 1 : 'a', 2:'b', 3:'c'}
# print('dict1 : ', dict1)
# print('dict1[1] : ', dict1[1]) # key에 해당하는 요소 출력
# print('keys : ', dict1.keys()) #key 값 출력
# print('values : ', dict1.values())#value 값 출력

# 빈 딕셔너리 생성
# dict2 = dict()

# # 값 추가
# dict2['a'] = "apple"
# dict2['b'] = 'banana'
# print('dict2 : ',dict2)

# # 요소 삭제
# del(dict2['a'])
# print("del(dict2['a'] : ", dict2)

# #key 존재 확인
# print('키 여부 : ', 'a' in dict2)
# print('키 여부 : ', 'b' in dict2)

# # range(시작값, 끝값 + 1, 증가값)
# # 0 ~ 9
# for i in range(10):
#     print(i , end = ' ')
# print()

# # 5 ~ 9
# for i in range(5, 10):
#     print(i , end = ' ')
# print()

# # 5 ~ 9 +2
# for i in range(5, 10, 2):
#     print(i , end = ' ')
# print()

# a = [9, 5, 2, 5, 1, 3 ,7]
# print('list 반복')
# for i in a:
#     print(i, end = ' ')
# print()

# print('dict key 반복')
# dict1 = { 1 : 'a', 2:'b', 3:'c'}
# for k in dict1.keys():
#     print('k : ', k)
# print()

# print('dict value 반복')
# for v in dict1.values():
#     print('v : ', v)
# print()

# print('dict key/value 반복')
# for k , v in dict1.items():
#     print('k : ', k)
#     print('v : ', v)
# print()

b = { 'a', 'b', 'c', 'f', 'g'}
for i in b:
    print(i)