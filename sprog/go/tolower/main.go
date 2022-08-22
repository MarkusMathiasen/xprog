package main
import (
	"fmt"
	"unicode"
)

func main() {
	var P, T int
	fmt.Scanln(&P, &T)
	res := 0
	for p := 0; p < P; p++ {
		pass := 1
		for t := 0; t < T; t++ {
			var s string
			fmt.Scanln(&s)
			pass &= verify(s)
		}
		res += pass
	}
	fmt.Println(res)
}

func verify(s string) int {
	for i, x := range s {
		if i == 0 {
			continue
		}
		if unicode.IsUpper(x) {
			return 0
		}
	}
	return 1
}
