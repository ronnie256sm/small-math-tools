#!/bin/bash

if [ -d "compiled_output" ]; then
	echo "Cleaning up..."
	rm -r compiled_output/
	echo "Done."
else
	echo "Could not find the compiled_output directory, quitting."
fi
