#!/bin/bash

if [ -d "compiled_output" ]; then
	echo "Previous compiled_output directory was found, cleaning up"
	rm -r compiled_output/
fi
mkdir compiled_output
echo Compiling...
for file in src/*.cpp; do
	base_name=$(basename "$file")
	name_without_extension="${base_name%.*}"
	echo "g++ -o compiled_output/$name_without_extension $file"
	g++ -o compiled_output/"$name_without_extension" "$file"
done
echo Done.

