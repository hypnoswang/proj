package simplemath

import "testing"

func testSqrt(t *testing.T) {
	r := Sqrt(4)
	if r != 2 {
		t.Errorf("Sqrt(4) failed, got %d while expecting 2", r);
	}
}
