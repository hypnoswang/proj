package algorithm

func Bsort(input []int) {
	len := len(input)

	for i := 0; i < len; i++ {
		for j := 0; j < len-i-1; j++ {
			if input[j] > input[j+1] {
				input[j], input[j+1] = input[j+1], input[j]
			}
		}
	}
}
