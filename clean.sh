#!/bin/bash

if [ -d "bin" ]; then
	echo "Cleaning up..."
	rm -r bin/
	echo "Done."
else
	echo "Could not find the bin directory, quitting."
fi
