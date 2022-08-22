package main
import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"sort"
)

type path struct {
	a, b, d int
}
var paths []path

var uf []int
func find(x int) int {
	if uf[x] == x {
		return x
	}
	uf[x] = find(uf[x])
	return uf[x]
}
func isSame(x, y int) bool {
	return find(x) == find(y)
}
func union(x, y int) {
	a, b := find(x), find(y)
	uf[a] = b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	uf = make([]int, n)
	for i := 0; i < n; i++ {
		uf[i] = i
	}
	paths = make([]path, n*n)
	for a := 0; a < n; a++ {
		for b := 0; b < n; b++ {
			scanner.Scan()
			d, _ := strconv.Atoi(scanner.Text())
			paths[a*n+b] = path{a, b, d}
		}
	}
	sort.Slice(paths, func(i, j int) bool {
		return paths[i].d < paths[j].d
	})
	for _, p := range paths {
		if !isSame(p.a, p.b) {
			union(p.a, p.b)
			fmt.Println(p.a+1, p.b+1)
		}
	}
}
