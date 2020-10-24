def solution(phone_book):
    answer = True
    # ["111", "11"] 같은 케이스를 위해서 정렬 필요함
    phone_book.sort()
    check = set()
    for n in phone_book:
        if answer == False:
            break
        for i in range(len(n)):
            if n[:i] in check: 
                answer = False
                break
        check.add(n)        
    return answer