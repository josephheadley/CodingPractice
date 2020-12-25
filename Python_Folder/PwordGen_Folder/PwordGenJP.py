import random

characters = "あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわをアイウエオカキクケコサシスセソタチツテトハヒフホマミムメモヤユヨラリルレロワヲ零一二三四五六七八九十！＠＃＄％＾＆＊＋＝：；？"
clength = len(characters)-1 

def makepword():
    plength = int(input("Please state the number of characters you want your random password to have: "))
    pslength = plength//4
    pword = ""
    if plength >= 8 and plength <= 32:
        for num in range(pslength):
            charac1 = characters[random.randint(0,45)]
            charac2 = characters[random.randint(46,90)]
            charac3 = characters[random.randint(91,101)]
            charac4 = characters[random.randint(102,clength)]
            z = random.randint(1,24)
            if z == 1:
                pword += charac1+charac2+charac3+charac4
            if z == 2:
                pword += charac1+charac2+charac4+charac3 
            if z == 3:
                pword += charac1+charac3+charac2+charac4
            if z == 4:
                pword += charac1+charac3+charac4+charac2
            if z == 5:
                pword += charac1+charac4+charac2+charac3
            if z == 6:
                pword += charac1+charac4+charac3+charac2
            if z == 7:
                pword += charac2+charac1+charac3+charac4
            if z == 8:
                pword += charac2+charac1+charac4+charac3
            if z == 9:
                pword += charac2+charac3+charac1+charac4
            if z == 10:
                pword += charac2+charac3+charac4+charac1
            if z == 11:
                pword += charac2+charac4+charac1+charac3
            if z == 12:
                pword += charac2+charac4+charac3+charac1
            if z == 13:
                pword += charac3+charac1+charac2+charac4
            if z == 14:
                pword += charac3+charac1+charac4+charac2
            if z == 15:
                pword += charac3+charac2+charac1+charac4
            if z == 16:
                pword += charac3+charac2+charac4+charac1
            if z == 17:
                pword += charac3+charac4+charac1+charac2
            if z == 18:
                pword += charac3+charac4+charac2+charac1
            if z == 19:
                pword += charac4+charac1+charac2+charac3
            if z == 20:
                pword += charac4+charac1+charac3+charac2
            if z == 21:
                pword += charac4+charac2+charac1+charac3
            if z == 22:
                pword += charac4+charac2+charac3+charac1
            if z == 23:
                pword += charac4+charac3+charac1+charac2
            if z == 24:
                pword += charac4+charac3+charac2+charac1 
        if plength%4 != 0:
            count = plength%4
            for thing in range(count):
                excharac = characters[random.randint(0,clength)]
                pword += excharac
        return pword
    else:
        print("The length must be between 8 and 32 characters. Keep that in mind and try again.")
        plength = int(input("Please state the number of characters you want your random password to have:"))
        return makepword()

print(makepword())