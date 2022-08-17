package main
import "fmt"

func main() {
	var s string
	fmt.Scanln(&s)
	fmt.Print("h")
	for i := 0; i < 2*len(s)-4; i++ {
		fmt.Print("e")
	}
	fmt.Println("y")
}
