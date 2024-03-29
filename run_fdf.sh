#!/bin/bash

FDF_DIR="tm"

for file in "$FDF_DIR"/*.fdf; do
	make && ./fdf "$file"
done
