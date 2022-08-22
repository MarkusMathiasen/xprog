package main
import "fmt"

func main() {
	var n int
	fmt.Scanln(&n)
	for i := 1; true; i++ {
		if (n+i)%100 == 99 {
			fmt.Println(n+i)
			return
		} else if (n-i)%100 == 99 {
			fmt.Println(n-i)
			return
		}
	}
}
