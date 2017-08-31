package algorithm

import (
	"testing"
)

func TestQsort(t *testing.T) {
	input := []int{3, 6, 13, 4, 5, 9, 6, 1}

	Qsort(input)

	min := 0
	for _, v := range input {
		if min > v {
			t.Errorf("Test failed for Qsort")
		}
		min = v
	}
}
