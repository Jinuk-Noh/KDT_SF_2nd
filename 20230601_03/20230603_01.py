from calc_module import add, sub

#num = calc_module.add(2, 3)
#print(num)

#num = calc_module.sub(2, 3)
#print(num)


# num = add(2, 3)
# print(num)

# num = sub(2, 3)
# print(num)


# f = open("./member.txt", "w")
# for i in range(3):
#     n= input("회원의 이름과 비밀번호를 입력하세요")
#     f.write(n + "\n")

# f.close()

# inputID = input('아이디 비밀번호 입력 : ')
# login = False
# f = open("./member.txt", "r")
# #print(f.read())

# ids = f.readlines()
# #print(ids)
# for i in ids:
#     if inputID == i.strip('\n'):
#         login = True
#         break

# if login:
#     print('로그인 성공')
# else:
#     print('로그인 실패')

# f.close()

# if login:
#     tel = input('전화번호를 입력하세요 : ')
#     f = open("./member_tel.txt")
#     id, pw = inputID.split()
#     tels = f.readlines()
#     exists = False

#     for i in tels:
#         if id == i.strip().split()[0]:
#             tels[tels.index(i)] = i.strip().split()[0] + " " + tel + "\n"
#             exists = True
#             break
    
#     if exists == False:
#         tels.append(id + " " + tel + "\n")
#     f.close()

#     f = open("./member_tel.txt", "w")

#     f.writelines(tels)
    
#     f.close()

# shop = [1,2,3,4,5,6]

# try:
#     print(shop[2])
#     print(shop[10])
# except IndexError as msg:
#     print(shop[-1])
#     print(msg)
    #print('Index 범위를 벗어났습니다.')

# try:
#     number = int(input("숫자 입력 : "))
# except:
#     print('Err 발생')

while True:
    num = input('정수를 입력')
    try:
        print(f'정수 입력 성공 {int(num)}')
        break
    except ValueError:
        print('정수가 아님! 정수를 입력해주세요!')


