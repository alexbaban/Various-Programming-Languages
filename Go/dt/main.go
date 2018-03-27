// copies the current date and time (formatted) to clipboard

package main

import (
	"fmt"
	"time"

	"github.com/atotto/clipboard"
)

func main() {
	dt := time.Now().Format("20060102_1504")
	fmt.Println(dt)
	err := clipboard.WriteAll(dt)
	if err != nil {
		panic(err)
	}
}
