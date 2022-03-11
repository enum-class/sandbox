#ifndef MATRIX_INL_H_
#define MATRIX_INL_H_

#ifndef MATRIX_H_
#error "Matrix-inl.h" should only be included in "Matrix.h" file.
#endif

#include <array>
#include <algorithm>

using namespace std;

template <typename T, size_t X, size_t Y>
Matrix<T, X, Y>::Matrix(Matrix&& other) noexcept
: matrix(std::move(other.matrix))
{
}

template <typename T, size_t X, size_t Y>
Matrix<T, X, Y>::Matrix(const Matrix<T, X, Y>& other)
: matrix(other.matrix)
{
}

template <typename T, size_t X, size_t Y>
Matrix<T, X, Y>& Matrix<T, X, Y>::operator = (Matrix<T, X, Y>&& other)
{
	matrix = std::move(other.matrix);
	return *this;
}

template <typename T, size_t X, size_t Y>
Matrix<T, X, Y>& Matrix<T, X, Y>::operator = (const Matrix<T, X, Y>& other)
{
	if (&other == this)
		return *this;
	
	matrix = other.matrix;
	return *this;
}

template <typename T, size_t X, size_t Y>
Matrix<T, X, Y>&& Matrix<T, X, Y>::operator + (const Matrix<T, X, Y>& other) const noexcept
{
	Matrix<T, X, Y> result;
	for (size_t row = 0; row < X; ++row)
		transform(matrix.at(row).begin(), matrix.at(row).end(),
				other.matrix.at(row).begin(),
				result.matrix[row].begin(),
				plus<>{});

	return move(result);
}

template <typename T, size_t X, size_t Y>
Matrix<T, X, Y>&& Matrix<T, X, Y>::operator - (const Matrix<T, X, Y>& other) const noexcept
{
	Matrix<T, X, Y> result;
	for (size_t row = 0; row < X; ++row)
		transform(matrix.at(row).begin(), matrix.at(row).end(),
				other.matrix.at(row).begin(),
				result.matrix[row].begin(),
				minus<>{});

	return move(result);
}

template <typename T, size_t X, size_t Y>
Matrix<T, X, Y>&& Matrix<T, X, Y>::operator * (const Matrix<T, X, Y>& other) const noexcept
{
	Matrix<T, X, Y> result;
	for (size_t row = 0; row < X; ++row)
		transform(matrix.at(row).begin(), matrix.at(row).end(),
				other.matrix.at(row).begin(),
				result.matrix[row].begin(),
				multiplies<>{});

	return move(result);
}

template <typename T, size_t X, size_t Y>
const Matrix<T, X, Y>& Matrix<T, X, Y>::operator & (const Matrix<T, X, Y>& other) const noexcept
{
	return other;
}

template <typename T, size_t X, size_t Y>
Matrix<T, X, Y>&& Matrix<T, X, Y>::operator * (size_t magnitude) const noexcept
{
	Matrix<T, X, Y> result;
	for (size_t row = 0; row < X; ++row)
		transform(matrix.at(row).begin(), matrix.at(row).end(),
				result.matrix[row].begin(),
				[magnitude](const auto& e) { return e * magnitude; }	);

	return move(result);
}

template <typename T, size_t X, size_t Y>
const std::array<T, Y>& Matrix<T, X, Y>::row(size_t r) const
{
	return matrix[r];
}

template <typename T, size_t X, size_t Y>
const std::array<T, X>& Matrix<T, X, Y>::column(size_t c) const
{
	Matrix<T, Y, X> result = this.rotate();
	return result[c];
}


Matrix<T, X, Y>&& rotate() const noexcept
{
	Matrix<T, Y, X> result;
	
	for (size_t row = 0; row < X; ++row)
		for (size_t col = 0; col < Y; col++)
			result.matrix[col][row] = matric[row][col];

	return move(result);
}

#endif
