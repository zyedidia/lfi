package lfi_test

import (
	"fmt"
	"log"
	"testing"

	"github.com/zyedidia/lfi/lfi-go"
)

func TestLfi(t *testing.T) {
	engine := lfi.NewEngine(lfi.Options{
		StackSize: 1024 * 1024,
		PageSize:  4096,
		Syscall: func(ctx any, num uint64, args [6]uint64) uint64 {
			fmt.Println("syscall")
			return 0
		},
	})
	err := engine.AutoAddVaspaces()
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(engine.MaxProcs())
}
