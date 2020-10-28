import random

n=int(input("number of rounds:"))
def main():
    player1=0
    player2=0
    rounds=1
    player1won=0
    player2won=0
    while rounds!=n:
        print("Round "+ str(rounds))
        player1=dice_roll()
        print("player1 "+ str(player1))
        player2=dice_roll()
        print("player2 "+ str(player2))
        if(str(player1)==str(player2)):
            print("Draw")
        elif(str(player1)>str(player2)):
            print("player1 won")
            player1won=player1won+1
        else:
            print("player2 won")
            player2won=player2won+1
        rounds=rounds+1    
    if(player1won==player2won):
        print("draw")
    elif(player1won>player2won):   
        print("winner is player1! and rounds won= "+ str(player1won))
    else:
        print("winner is player2! and rounds won= "+ str(player2won))

def dice_roll():
    diceRoll=random.randint(1,6)
    return diceRoll
main()    

