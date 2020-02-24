#pragma once
template<typename T>
class Stack {
private:
	T* m_Array;
	int m_Size;
public:
	Stack(int nSize) : m_Size(0), m_Array(new T[nSize]) {};
	~Stack() {
		delete[] m_Array;
		m_Array = nullptr;
		m_Size = 0;
	};
	void push(T value) {
		T* buffer = new T[m_Size+1];
		for (int i = 0; i < m_Size; i++) {
			buffer[i] = m_Array[i];
		}

		buffer[m_Size] = value;

		delete[] m_Array;
		m_Array = buffer;

		m_Size++;
		return;
	}
	void pop() {
		T* buffer = new T[m_Size - 1];
		for (int i = 0; i < m_Size - 1; i++) {
			buffer[i] = m_Array[i];
		}
		delete[] m_Array;
		m_Array = buffer;

		m_Size--;
		return;
	}
	T peek() {
		return m_Array[m_Size - 1];
	}
	int count() {
		return m_Size;
	}

	friend bool operator == (Stack<T>& stack1, Stack<T>& stack2) {
		int size1 = stack1.count();
		int size2 = stack2.count();

		int size;

		if (size1 < size2) size = size1;
		else size = size2;

		for (int i = 0; i < size; i++) {
			T num1 = stack1.m_Array[i];
			T num2 = stack2.m_Array[i];
			if (num1 != num2) {
				return false;
			}
			else {
				continue;
			}
		}

		if (stack1.count() == stack2.count()) return true;
		return false;
	}

	friend bool operator != (Stack<T>& stack1, Stack<T>& stack2) {
		if (stack1 == stack2) return false;
		return true;
	}

	friend bool operator > (Stack<T>& stack1, Stack<T>& stack2) {
		int size1 = stack1.count();
		int size2 = stack2.count();

		int size;

		if (size1 < size2) size = size1;
		else size = size2;

		for (int i = 0; i < size; i++) {
			T num1 = stack1.m_Array[i];
			T num2 = stack2.m_Array[i];
			if (num1 != num2) {
				if (num1 < num2) {
					return false;
				}
				else {
					return true;
				}
			}
			else {
				continue;
			}
		}

		if (stack1.count() <= stack2.count()) return false;
		return true;
	}
	friend bool operator < (Stack<T>& stack1, Stack<T>& stack2) {
		int size1 = stack1.count();
		int size2 = stack2.count();

		int size;

		if (size1 < size2) size = size1;
		else size = size2;

		for (int i = 0; i < size; i++) {
			T num1 = stack1.m_Array[i];
			T num2 = stack2.m_Array[i];
			if (num1 != num2) {
				if (num1 < num2) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				continue;
			}
		}

		if (stack1.count() < stack2.count()) return true;
		return false;
	}

	friend bool operator >= (Stack<T>& stack1, Stack<T>& stack2) {
		if ((stack1 > stack2) || (stack1 == stack2)) return true;
		return false;
	}

	friend bool operator <= (Stack<T>& stack1, Stack<T>& stack2) {
		if ((stack1 < stack2) || (stack1 == stack2)) return true;
		return false;
	}
};
