package main
import "fmt"

func main() {
	var s string
	fmt.Scanln(&s)
	if s[:3] == "555" {
		fmt.Println("1")
	} else {
		fmt.Println("0")
	}
}
