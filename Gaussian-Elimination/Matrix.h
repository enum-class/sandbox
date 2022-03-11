#ifndef MATRIX_H_
#define MATRIX_H_

#include <array>

template <typename T, size_t X, size_t Y>
class Matrix
{
public:
	/// Default constructor
	Matrix() = default;

	/// Default destructor
	~Matrix() = default;
	
	/// Move constructor
	inline Matrix(Matrix&&) noexcept;

	/// Copy constructor
	inline Matrix(const Matrix& other);

	/// Move assignment
	inline Matrix<T, X, Y>& operator = (Matrix<T, X, Y>&&);

	/// Copy assignment
	inline Matrix<T, X, Y>& operator = (const Matrix<T, X, Y>&);

	/// Operator plus
	inline Matrix<T, X, Y>&& operator + (const Matrix<T, X, Y>&) const noexcept;

	/// Operator minus
	inline Matrix<T, X, Y>&& operator - (const Matrix<T, X, Y>&) const noexcept;

	/// Operator dot
	inline Matrix<T, X, Y>&& operator * (const Matrix<T, X, Y>&) const noexcept;

	/// Operator multiply
	inline const Matrix<T, X, Y>& operator & (const Matrix<T, X, Y>&) const noexcept;

	/// Operator multiply
	inline Matrix<T, X, Y>&& operator * (size_t) const noexcept;

	/// Get row
	inline const std::array<T, Y>& row(size_t) const noexcept;
	
	/// Get column
	inline const std::array<T, X>& column(size_t) const noexcept;

	/// Rotate
	inline Matrix<T, X, Y>&& rotate() const noexcept;

	std::array<std::array<T, Y>, X> matrix;
};

#include "Matrix-inl.h"

#endif
