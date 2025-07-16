#!/bin/bash

if [ -d "compiled_output" ]; then
	echo "Previous compiled_output directory was found, cleaning up"
	rm -r compiled_output/
fi
mkdir compiled_output
echo Compiling...
g++ -o compiled_output/cholesky_decomposition src/cholesky_decomposition.cpp
g++ -o compiled_output/math_stat_task src/math_stat_task.cpp
g++ -o compiled_output/numerical_integration src/numerical_integration.cpp
g++ -o compiled_output/lagrange_polynomial src/lagrange_polynomial.cpp
g++ -o compiled_output/newton_method src/newton_method.cpp
g++ -o compiled_output/random_matrix_generator src/random_matrix_generator.cpp
echo Done.

