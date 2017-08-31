package algorithm

func Qsort(input []int) {
	qsort(input, 0, len(input)-1)
}

func qsort(input []int, left int, right int) {
	flag := input[left]
	base := left
	i, j := left, right

	for i <= j {
		for i <= j && input[j] >= flag {
			j--
		}

		if i <= j {
			input[j], input[i] = input[i], input[j]
			base = j
		}

		for i <= j && input[i] <= flag {
			i++
		}

		if i <= j {
			input[j], input[i] = input[i], input[j]
			base = i
		}
	}

	if left < j {
		qsort(input, left, j)
	}

	if base == i {
		i++
	}

	if i < right {
		qsort(input, i, right)
	}
}
