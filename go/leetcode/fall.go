package leetcode

// 1.猜数字
func Game(guess []int, answer []int) int {
	ret := 0
	for i := 0; i < 3; i++ {
		if guess[i] == answer[i] {
			ret++
		}
	}
	return ret
}

// 2.分式化简
func fraction(cont []int) []int {
	l := len(cont)
	if len(cont) == 1 {
		return []int{cont[0], 1}
	}

	b := fractionB(cont[l-2], []int{cont[l-1], 1})
	//tmpb := make([]int, 2)
	for i := len(cont) - 3; i >= 0; i-- {
		//tmpb[0], tmpb[1] = b[0], b[1]
		ret := fractionB(cont[i], b)

		b[0], b[1] = ret[0], ret[1]
	}

	r := gcb(b[0], b[1])
	return []int{b[0] / r, b[1] / r}
}

func fractionB(a int, b []int) []int {
	return []int{a*b[0] + b[1], b[0]}
}

// 求最大公约数
func gcb(x int, y int) int {
	tmp := x % y
	if tmp > 0 {
		return gcb(y, tmp)
	}

	return y
}

// 3.机器人
func robot(command string, obstacles [][]int, x int, y int) bool {
	a, b := 0, 0
	l := len(command)
	n := 0
	for {
		i := n % l
		switch string(command[i]) {
		case "U":
			b++
		case "R":
			a++
		default:
			panic(a)
		}
		for key, obstacle := range obstacles {
			if obstacle[0] == a && obstacle[1] == b {
				return false
			} else if obstacle[0] < a && obstacle[1] < b {
				obstacles = append(obstacles[:key], obstacles[key+1:]...)
			}
		}

		if a == x && b == y {
			return true
		}else if a > x && b > y {
			return false
		}
		n++
	}
}
