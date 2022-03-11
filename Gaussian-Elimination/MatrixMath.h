#ifndef MATRIX_MATH_
#define MATRIX_MATH_

#include "Matrix.h"

class MatrixMath
{
public:
	template<typename T, size_t X, size_t Y>
	static Matrix<T, X, Y>& swap_rows(Matrix<T, X, Y>&, size_t, size_t);

	template<typename T, size_t X, size_t Y>
	static Matrix<T, X, Y>& multiply_row(Matrix<T, X, Y>&, size_t, size_t);

	template<typename T, size_t X, size_t Y>
	static Matrix<T, X, Y>& merge_rows(Matrix<T, X, Y>&, size_t, size_t, size_t);

	template<typename T, size_t X, size_t Y>
	static Matrix<T, X, Y>& gaussian_elimination(Matrix<T, X, Y>&);

	template<typename T, size_t X, size_t Y>
	static Matrix<T, Y, X>& inverse(Matrix<T, X, Y>&);

private:
	MatrixMath() = delete;
};

#endif
