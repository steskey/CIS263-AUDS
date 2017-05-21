#ifndef __H_AUDS__
#define __H_AUDS__

template <class T>
class AUDS{

public:

	AUDS() : m_data(nullptr){
		m_data = new T[m_capacity];
	}

	~AUDS(){
		delete[] m_data;	
	}

	AUDS(AUDS const& other){
		m_size = other.m_size;
		m_data(new T[m_size]);
		for(int i = 0; i < m_size; ++i){
			m_data[i] = other.m_data[i];
		}
	}
	AUDS& operator=(AUDS other){
		AUDS copy(other);
		std::swap(*this, copy);
		return *this;
	}

	int size(){
		return m_size;
	}

	void push(T x){
		if(m_size >= m_capacity){
			resize(m_capacity * 1.5);	
		}
		
		m_data[m_size] = x;
		++m_size;		
	}

	T pop(){
		// http://www.cplusplus.com/reference/cstdlib/rand/
		int index = rand() % m_size + 1;
	
		T randomItem = m_data[index];	
		m_data[index] = m_data[m_size - 1];
		--m_size;
		return randomItem;				
	}

protected:

private:

	T* m_data;
	int m_size = 0;
	int m_capacity = 100;	

	void resize(int newCapacity){
		T* tmp = new T[newCapacity];
		for(int i = 0; i < m_size; ++i)
		{
			tmp[i] = m_data[i];
		}

		m_capacity = newCapacity;
		delete[] m_data;	
		m_data = tmp;
	}	
};

#endif // __H_AUDS__
