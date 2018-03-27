// prints the public and local (private) IP addresses of the computer

package main

import (
	"fmt"
	"io"
	"log"
	"net"
	"net/http"
	"os"
)

func main() {

	fmt.Println()
	fmt.Println("IP Addresses:")
	fmt.Println()
	printPublicIP()
	printLocalIP()
	fmt.Println()

}

func printPublicIP() {
	r, err := http.Get("http://ident.me")

	if err != nil {
		log.Fatal(err)
	}

	if r.StatusCode != http.StatusOK {
		log.Fatal(r.Status)
	}

	io.Copy(os.Stdout, r.Body)
	fmt.Println(" // public")
}

func printLocalIP() {
	host, _ := os.Hostname()
	addrs, _ := net.LookupIP(host)
	for _, addr := range addrs {
		if ipv4 := addr.To4(); ipv4 != nil {
			fmt.Println(ipv4, " // local")
		}
	}

}
