package main

import "fmt"

func tribonacci(n int)  {
    if n<=2{
        fmt.Println(string("\033[31m"),"Error : Enter a number above 2")
        return 
    }
    fmt.Print("0 1 1")
        x:=0
        y:=1
        z:=1
        val:=x+y+z
        for n>2 {
            val=x+y+z
            x=y
            y=z
            z=val
            n--
			fmt.Printf(" %d",val)
        }
}

func main(){
    fmt.Println("Enter the number of tribonacci numbers to be printed (Any number above 2)")
    var num int
    fmt.Scanln(&num)
	tribonacci(num)
}