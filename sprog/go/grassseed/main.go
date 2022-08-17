package main
import "fmt"

func main() {
	var C, res float64
	var L int
	fmt.Scanln(&C)
	fmt.Scanln(&L)
	for i := 0; i < L; i++ {
		var w, l float64
		fmt.Scanln(&w, &l)
		res += C*w*l
	}
	fmt.Println(res)
}
