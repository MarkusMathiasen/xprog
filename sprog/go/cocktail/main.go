package main
import (
	"fmt"
	"sort"
)

func main() {
	var n, t int
	fmt.Scanln(&n, &t)
	A := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanln(&A[i])
	}
	sort.Ints(A)
	for i, x := range A {
		if i*t >= x {
			fmt.Println("NO")
			return
		}
	}
	fmt.Println("YES")
}
