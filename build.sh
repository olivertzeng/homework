#!/bin/bash

for f in ./**/*.tex; do
	filename=$(basename "$f")
	echo "Now compiling $filename..."
	cd "$(dirname "$f")" || return
	if [ -f "$filename" ]; then
		xelatex -synctex=1 -interaction=nonstopmode --shell-escape --enable-8bit-chars -recorder "$filename"
	else
		echo "Error: File not found: $filename"
	fi
done
