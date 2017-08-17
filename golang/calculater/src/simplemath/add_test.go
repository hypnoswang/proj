package simplemath

import "testing"

func testAdd(t *testing.T) {
	r := Add(1, 2)
	if r != 3 {
		t.Errorf("Add(1,2) failed, got %d while expecting 3", r);
	}
}
