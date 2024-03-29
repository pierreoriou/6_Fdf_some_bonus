#!/bin/bash

FDF_DIR="tm"

for file in "$FDF_DIR"/*.fdf; do
	make && valgrind ./fdf "$file"
done
