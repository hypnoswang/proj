package main

import (
	"os"
	"fmt"
	"simplemath"
	"strconv"
)

var Usage = func () {
	fmt.Println("Usage: calc <command> {arguments...}")
	fmt.Println("\nThe command are:\n\tadd: addition of two values\n\tsqrt: square root of a non-negative value")
}

func main() {
	args := os.Args
	if args == nil || len(args) < 2 {
		Usage()
		return
	}

	switch args[1] {
		case "add":
			if len(args) != 4 {
				fmt.Println("Usage: calc add <val1> <val2>")
				return
			}

			v1, err1 := strconv.Atoi(args[2])
			v2, err2 := strconv.Atoi(args[3])
			if err1 != nil || err2 != nil {
				fmt.Println("Usage: calc add <val1> <val2>")
				return
			}
			ret := simplemath.Add(v1, v2)
			fmt.Println("The result is ", ret)
		case "sqrt":
			if len(args) != 3 {
				fmt.Println("Usage: calc sqrt <non-negative val>")
				return
			}
			v1, err1 := strconv.ParseFloat(args[2], 3)
			if err1 != nil || v1 < 0 {
				fmt.Println("Usage: calc sqrt <non-negative val>")
				return
			}
			ret := simplemath.Sqrt(v1)
			fmt.Println("The result is ", ret)
		default:
			Usage()
	}


}
