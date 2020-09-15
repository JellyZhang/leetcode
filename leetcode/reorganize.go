package main

import (
	"fmt"
	"io/ioutil"
	"os"
)

func main() {
	path := "/Users/jelly/leetcode/leetcode"
	pathw := "/Users/jelly/leetcode/leetcode/1-100/"
	files := readDir(path)
	for _, f := range files {
		if !f.IsDir() {
			continue
		}
		p := path + "/" + f.Name() + "/" + "README.md"
		fmt.Printf("readp = %v\n", p)
		content, err := readFile(p)
		if err != nil {
			continue
		}
		pw := pathw + f.Name() + ".md"
		fmt.Printf("writep = %v\n", pw)
		writeFile(pw, content)
	}
}

func readFile(path string) (string, error) {
	content, err := ioutil.ReadFile(path)
	if err != nil {
		return "", err
	}
	fmt.Printf("--------- readFile of %v success ---------\n", path)
	return string(content), nil
}

func writeFile(path string, content string) error {
	if err := ioutil.WriteFile(path, []byte(content), 0644); err != nil {
		return err
	}
	fmt.Printf("--------- writeFile in %v success ---------\n", path)
	return nil
}

func readDir(path string) []os.FileInfo {
	files, err := ioutil.ReadDir(path)
	if err != nil {
		panic(err)
	}
	return files
}
