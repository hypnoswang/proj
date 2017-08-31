package main

import (
	"bufio"
	"flag"
	"fmt"
	"io"
	"os"
	"strconv"
	"time"

	"algorithm"
)

var (
	infile  *string
	outfile *string
	alg     *string
)

func parseCmd() bool {
	infile = flag.String("i", "infile", "The input file containing the unsorted data")
	outfile = flag.String("o", "outfile", "The output file receiving the sorted data")
	alg = flag.String("a", "qsort", "The algorithm used to sort the data")

	flag.Parse()
	if infile == nil {
		fmt.Println("The input file missed")
		return false
	}

	//fmt.Println("The input file is ", *infile, ", output file is ", *outfile, ", algorithm is ", *algorithm)

	return true
}

func readValues(infile string) (vals []int, err error) {
	file, err := os.Open(infile)
	if err != nil {
		fmt.Println("Failed to open input file ", infile)
		// here, vals is empty, but err is the return value of os.Open
		return
	}

	defer file.Close()

	br := bufio.NewReader(file)
	vals = make([]int, 0)

	for {
		line, isPrefix, err1 := br.ReadLine()
		if err1 != nil {
			if err1 != io.EOF {
				err = err1
			}
			break
		}

		if isPrefix {
			fmt.Println("a too lang line, should not be expected")
			return
		}

		str := string(line) //convert the byte array to string

		val, err1 := strconv.Atoi(str)
		if err1 != nil {
			fmt.Println("an integer has been expected")
			return
		}

		vals = append(vals, val)
	}

	return
}

func writeValues(vals []int, outfile string) error {
	file, err := os.Create(outfile)
	if err != nil {
		fmt.Println("Create output file failed")
		return err
	}

	defer file.Close()

	for _, v := range vals {
		str := strconv.Itoa(v)
		_, err := file.WriteString(str + "\n")
		if err != nil {
			fmt.Println("Write to output file failed")
			return err
		}
	}

	return nil

}

func main() {
	parseCmd()

	unsortedData, err := readValues(*infile)
	if err != nil {
		fmt.Println("Read input file data failed: ", err)
		return
	}

	fmt.Println("Before sorting: ")
	for _, data := range unsortedData {
		fmt.Printf("%d ", data)
	}
	fmt.Printf("\n")

	t1 := time.Now()
	switch *alg {
	case "qsort":
		algorithm.Qsort(unsortedData)
	case "bsort":
		algorithm.Bsort(unsortedData)
	default:
		fmt.Printf("Not supported algorithm: %s\n", *alg)
		return
	}
	t2 := time.Now()

	fmt.Printf("The algorithm %s took %d nano second to complete\n", *alg, t2.Sub(t1))

	fmt.Println("After sorting: ")
	for _, data := range unsortedData {
		fmt.Printf("%d ", data)
	}
	fmt.Printf("\n")

	err = writeValues(unsortedData, *outfile)
	if err != nil {
		fmt.Println("Write result to file failed: ", err)
		return
	}

}
