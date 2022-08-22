package main
import (
	"fmt"
	"bufio"
	"os"
	"strconv"
)

func main() {
	var n int
	scanner := bufio.NewScanner(os.Stdin)
	fmt.Scanln(&n)
	A := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		A[i], _ = strconv.Atoi(scanner.Text())
	}
	for i := n-1; i >= 0; i-- {
		fmt.Println(A[i])
	}
}
