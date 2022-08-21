package main
import "fmt"

func main() {
	var n int
	fmt.Scanln(&n)
	for i := 0; true; i++ {
		if 1 << i >= n {
			fmt.Println(i+1)
			break
		}
	}
}
