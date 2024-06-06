#!/bin/bash

for f in ./**/*.tex; do
	filename=$(basename "$f")
	echo "Now compiling $filename..."
	echo
	read -rp "Press Enter to continue..." _
	cd "$(dirname "$f")" || return
	pwd
	if [ -f "$filename" ]; then
		xelatex "$filename" -synctex=1 -interaction=nonstopmode --shell-escape --enable-8bit-chars -recorder
	else
		echo "Error: File not found: $filename"
	fi
done
