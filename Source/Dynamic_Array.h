#pragma once

namespace DataStructures
{
	template <typename T>
	class DynamicArray
	{
	private:
		T* array = nullptr;
		unsigned long long size = 0;
		unsigned long long count = 0;

	public:
		DynamicArray(unsigned long long size = 0)
			: array(new T[size]), size(size), count(0)
		{

		}

		DynamicArray(DynamicArray&& copyArray)
			: array(copyArray.array), size(copyArray.size), count(copyArray.count)
		{
			copyArray.array = nullptr;
			copyArray.size = 0;
			copyArray.count = 0;
		}

		~DynamicArray()
		{
			delete[] array;
			array = nullptr;
		}

		T& operator[](unsigned long long index)
		{
			return array[index];
		}

		constexpr T& operator[](unsigned long long index) const
		{
			return array[index];
		}

		constexpr unsigned long long Size() const noexcept
		{
			return size;
		}

		constexpr unsigned long long Count() const noexcept
		{
			return count;
		}

		void Trim()
		{
			size = count;

			T* newArray = new T[size];

			for(unsigned long long i = 0; i < count - 1; i++)
			{
				newArray[i] = array[i];
			}

			delete[] array;
			array = newArray;
		}

		void Add(T data)
		{
			count++;

			if(count > size)
			{
				size++;
				T* newArray = new T[size];

				for(unsigned long long i = 0; i < count - 1; i++)
				{
					newArray[i] = array[i];
				}

				delete[] array;
				array = newArray;
			}

			array[count - 1] = data;
		}

		void Remove(unsigned long long index)
		{
			if(count > 0 && index > 0 && index < count - 1)
			{
				count--;
				T temp1 = array[index];
				T temp2 = array[count];

				array[index] = temp2;
				array[count] = temp1;
			}
		}
	};
}