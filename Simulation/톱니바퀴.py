from copy import deepcopy

wheels = [list(map(int, input())) for _ in range(4)]
K = int(input())

def rotate(wheels, direction):
    temp = deepcopy(wheels)
    if direction == 1:
        for i in range(8):
            idx = i + 1 if i + 1 < 8 else 0
            temp[idx] = wheels[i]
    else:
        for i in range(8):
            idx = i - 1 if i - 1 >= 0 else 7
            temp[idx] = wheels[i]
    return temp

for _ in range(K):
    no, direction = map(int, input().split())
    no -= 1
    new_wheels = deepcopy(wheels)
    new_wheels[no] = rotate(wheels[no], direction)

    curr_direction = direction
    for i in range(no+1, 4):
        if wheels[i-1][2] == wheels[i][6]:
            break
        curr_direction *= -1
        new_wheels[i] = rotate(wheels[i], curr_direction)
    
    curr_direction = direction
    for i in range(no-1, -1, -1):
        if wheels[i+1][6] == wheels[i][2]:
            break
        curr_direction *= -1
        new_wheels[i] = rotate(wheels[i], curr_direction)

    wheels = new_wheels

answer = 0
if wheels[0][0] == 1:
    answer += 1
if wheels[1][0] == 1:
    answer += 2
if wheels[2][0] == 1:
    answer += 4
if wheels[3][0] == 1:
    answer += 8

print(answer)