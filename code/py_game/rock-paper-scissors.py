from random import randint

choice=['rock','paper','scissors']
computer=choice[randint(0,2)]
print("welcome to the game")
player=input("player: ").lower()
print("computer: "+ computer)
if player==computer:
    print("draw")
elif player=="rock" and computer=="paper" : 
    print("computer won")
elif player=="rock" and computer=="scissors" :
    print("player won")
elif player=="paper" and computer=="rock" :
    print("player won")  
elif player=="paper" and computer=="scissors" :
    print("computer won")
elif player=="scissors" and computer=="rock" :
    print("computer won")
elif player=="scissors" and computer=="paper" :   
    print("player won")        
