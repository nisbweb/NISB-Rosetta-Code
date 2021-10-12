# -*- coding: utf-8 -*-
"""
Created on Mon Jun  7 17:47:01 2021
jumbled
@author: Madhusudan Joshi
"""
import random

def choose():
    words=['computer','python','english','work','random','pencil','frustration','understand','words','water','apple','smartphone','laptop','quality','movie']
    pick=random.choice(words)
    return pick

def jumble(w):
    j="".join(random.sample(w,len(w)))
    return j
    
def play():
    p1=input("Enter Player1 name ")
    p2=input("Enter Player1 name ")
    sp1=0
    sp2=0
    turn=0
    while(1):
        word=choose()
        q=jumble(word)
        print("Guess the word :",q)
        if(turn%2==0):
            print(p1,"'s turn")
            a=input("The word is: ")
            if(a==word):
                sp1=sp1+1
                print(p1,"'s score is",sp1)
            else:
                print("Ahh the word was ",word)
            c=input("press c to continue e to quit: ")
            if c=='e':
                print("Thank you for playing \n ",p1,"'s score:",sp1,p2,"'s score:",sp2)
                break
        else:
            print(p2,"'s turn")
            a=input("The word is: ")
            if(a==word):
                sp2=sp2+1
                print(p2,"'s score is",sp2)
            else:
                print("Ahh the word was ",word)
            c=input("press c to continue e to quit: ")
            if c=='e':
                print("Thank you for playing \n ",p1,"'s score:",sp1,p2,"'s score:",sp2)
                break
        turn=turn+1

play()
        
            