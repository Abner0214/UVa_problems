a = 0
while 1 :
    try:
        line = input()
        exec("a = " + line)
        print(a)
    except:
        break