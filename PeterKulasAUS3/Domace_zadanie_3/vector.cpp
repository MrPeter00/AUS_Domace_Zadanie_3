#include "vector.h"
#include "ds_routines.h"
#include <cstdlib>
#include <cstring>

namespace structures {

	Vector::Vector(size_t size) :
		memory_(calloc(size, 1)),//calloc alokuje pamät, inicializuje na 0
		size_(size)
	{
	}

	//move schematika

	Vector::Vector(Vector&& other)
		: memory_(other.memory_),
		size_(other.size_)
	{		
		other.size_ = 0;
		other.memory_ = nullptr;
	}

	Vector& Vector::operator=(Vector&& other)
	{
		if (this != &other)
		{
			free(memory_);

			size_ = std::move(other.size_);
			memory_ = std::move(other.memory_);

			other.size_ = 0;
			other.memory_ = nullptr;
		}
		return *this;
	}
	
	Vector::Vector(const Vector& other) : //kopirovaci construktor
		Vector(other.size_)
	{
		memory_ = memcpy(memory_, other.memory_, size_); //memcpy mozem pouzit lebo sa neprekryva pamat
	}

	Vector::~Vector() //destruktor
	{
		free(memory_);
		memory_ = nullptr;
		size_ = 0;
	}

	Structure* Vector::clone() const
	{
		return new Vector(*this);
	}

	size_t Vector::size() const
	{
		return size_;
	}

	Structure& Vector::operator=(const Structure& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const Vector&>(other);
		}
		return *this;
	}

	Vector& Vector::operator=(const Vector& other)
	{
		if (this != &other)
		{
			size_ = other.size_;
			memory_ = realloc(memory_, size_);
			memory_ = memcpy(memory_, other.memory_, size_);
		}
		return *this;
	}

	bool Vector::operator==(const Vector& other) const
	{
		return size_ == other.size_ && memcmp(memory_, other.memory_, size_) == 0;
	}

	byte& Vector::operator[](const int index)
	{
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index in Vector!");
		return *(reinterpret_cast<byte*>(memory_) + index); //* dereferencuje a dostaneme to naco ukazuje pointer, hodnotu
	}

	byte Vector::operator[](const int index) const
	{
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index in Vector!");
		return *(reinterpret_cast<byte*>(memory_) + index); //* dereferencuje a dostaneme to naco ukazuje pointer, hodnotu
	}

	byte& Vector::readBytes(const int index, const int count, byte& dest)
	{
		//DSRoutines::rangeCheckExcept(index, size_, "Invalid index in Vector!");
		DSRoutines::rangeCheckExcept(index + count, size_ + 1, "Invalid end index!");
		memcpy(&dest, getBytePointer(index), count); 
		return dest;
	}

	//Byty chceme kopirotvat z 1 vectora do druheho, moze byt aj ten iste
	void Vector::copy(const Vector& src, const int srcStartIndex, Vector& dest, const int destStartIndex, const int length)
	{
		if (length != 0) { //ci ma kopirovanie zmysel
			//osetrujeme startovacie indexy a ci indexy nepresiahnu velkost
			DSRoutines::rangeCheckExcept(srcStartIndex, src.size_, "Invalid index in Vector src!"); 
			DSRoutines::rangeCheckExcept(destStartIndex, dest.size_, "Invalid index in Vector dest!");
			DSRoutines::rangeCheckExcept(srcStartIndex + length, src.size_ + 1, "Invalid end index in Vector src!");
			DSRoutines::rangeCheckExcept(destStartIndex + length, dest.size_ + 1, "Invalid end index in Vector dest!");

			if ((&src == &dest) && (((srcStartIndex >= destStartIndex) && (srcStartIndex < destStartIndex + length)) || ((destStartIndex >= srcStartIndex) && (destStartIndex < srcStartIndex + length)))) {
				memmove(src.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
			}
			else {
				// ak sa vectory neprekrývaju pouzivame rychlejsi memcpy
				memcpy(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
			}
		}
	}

	byte* Vector::getBytePointer(const int index) const
	{
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index in Vector!");
		return (reinterpret_cast<byte*>(memory_) + index);
	}
	//v DS je memoryroutines a tu dorobit v .h je popis co to ma robit
}