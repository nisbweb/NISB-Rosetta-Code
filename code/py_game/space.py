import os
import turtle
import math
#init screen

wn=turtle.Screen()
wn.bgcolor("black")
wn.title("Space Invaders")
wn.register_shape("space_invaders_background.gif")
wn.bgpic("space_invaders_background.gif")
wn.register_shape("invader.gif")
wn.register_shape("player.gif")
# Draw border

borderPen=turtle.Turtle()
borderPen.speed(0)
borderPen.color("grey")
borderPen.penup()
borderPen.setposition(-300,-300)
borderPen.pendown()
borderPen.pensize(3)
for side in range(4):
	borderPen.fd(600)
	borderPen.lt(90)

borderPen.hideturtle()

#create player
player=turtle.Turtle()
player.color("Blue")
player.shape("player.gif")
player.penup()
player.speed(0)
player.setposition(0,-250)
player.setheading(90)

playerspeed=10

#Create enemy

enemy=turtle.Turtle()
enemy.color("red")
enemy.shape("invader.gif")
enemy.penup()
enemy.speed(0)
enemy.setposition(-200,250)

enemyspeed=5

#create bullet
bullet=turtle.Turtle()
bullet.color("yellow")
bullet.shape("circle")
bullet.penup()
bullet.speed(0)
bullet.setheading(90)
bullet.shapesize(0.5,0.5)
bullet.hideturtle()
bulletspeed=40
bulletState="ready"


#Move player left and right
def moveLeft():
	x=player.xcor()
	x-=playerspeed
	if x<-280:
		x=-280
	player.setx(x)

def moveRight():
	x=player.xcor()
	x+=playerspeed
	if x>280:
		x=280
	player.setx(x)

def fireBullet():
	global bulletState
	if bulletState=="ready":
		bulletState="fire"
		#Move bullet upwards from where it is fired
		x=player.xcor()
		y=player.ycor()+10
		bullet.setposition(x,y)
		bullet.showturtle()

def isCollision(t1,t2):
	distance=math.sqrt(math.pow(t1.xcor()-t2.xcor(),2)+math.pow(t1.ycor()-t2.ycor(),2))
	if distance<15:
		return True
	else:
		return False

#keyboard binding
turtle.listen()
turtle.onkey(fireBullet,"space")
turtle.onkey(moveLeft,"Left")
turtle.onkey(moveRight,"Right")

while True:
	wn.update()
	#Moving the enemy
	x=enemy.xcor()
	x+=enemyspeed
	enemy.setx(x)
	#Move the enemy down and change direction
	if enemy.xcor()>280:
		y=enemy.ycor()
		y=y-30
		enemyspeed *=-1
		enemy.sety(y)

	if enemy.xcor()<-280:
		y=enemy.ycor()
		y=y-30
		enemyspeed *=-1
		enemy.sety(y)

	if bulletState=="fire":
		y=bullet.ycor()
		y=y+bulletspeed
		bullet.sety(y)

	#if bullet reaches  the top

	if bullet.ycor()>275:
		bullet.hideturtle()
		bulletState="ready"

	#detect collision between bullet and enemy
	if isCollision(bullet,enemy):
		#reset the bullet
		bullet.hideturtle()
		bulletState="ready"
		bullet.setposition(0,-400)
		#reset the enemy
		enemy.setposition(-200,250)

	if isCollision(player,enemy):
		print("Game Over")

delay=input("Enter the key to finish\n")
