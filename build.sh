#!/bin/bash

if [ -d "bin" ]; then
	echo "Previous bin directory was found, cleaning up"
	rm -r bin/
fi
mkdir bin
echo Compiling...
for file in src/*.cpp; do
	base_name=$(basename "$file")
	name_without_extension="${base_name%.*}"
	echo "g++ -o bin/$name_without_extension $file"
	g++ -o bin/"$name_without_extension" "$file"
done
echo Done.

