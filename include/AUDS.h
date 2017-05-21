/**
 * This class is called an AUDS -- Almost Useless Data Structure.
 * It stores a generic data type in an array and is responsible
 * for managing the memory allocated for the array.
 * @author Samantha Teskey
 * @file AUDS.h
 * @version 5-21-2017
 */

#ifndef __H_AUDS__
#define __H_AUDS__

template <class T>
class AUDS{

    public:

        /**
         *  Default construcotr. Creates a new data array with an
         *  initial capacity of m_capacity
         */
        AUDS() : m_data(nullptr){

            m_data = new T[m_capacity]; // m_capacity == 100
        }

        /**
         * Destructor. Frees the memory that was allocated for the
         * data array.
         */
        ~AUDS(){
            // The square brackets are used because this is an array.
            delete[] m_data;	
        }

        /**
         * Copy constructor. Accepts a reference to another AUDS
         * object. Performs a deep copy of this object by copying
         * the size, capacity, and allocating memory for a new
         * array to hold individual copies of all the elements.
         */
        AUDS(AUDS const& other){

            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_data(new T[m_capacity]); // Allocate space for new array

            // Go to m_size because this is the number of elements
            for(int i = 0; i < m_size; ++i){
                // Create a copy of each element
                m_data[i] = other.m_data[i];
            }
        }

        /**
         * Copy operator. Performs a copy-and-swap using the copy
         * constructor defined above and std::swap. By using
         * the copy constructor, a deep copy is made.
         */
        AUDS& operator=(AUDS other){
            AUDS copy(other);
            std::swap(*this, copy); // 'This' now refers to the copy
            return *this;
        }

        /**
         * Returns the current number of elements stored in the array.
         * This is different from the capacity.
         */
        int size(){
            return m_size;
        }

        /**
         * Adds the element to the data structure. If the size will
         * exceed the capacity, the data structure first increases the
         * capacity by 50%. The element is added to the end of the
         * array.
         */ 
        void push(T x){
            // Can use ==, but >= is safer
            if(m_size >= m_capacity){
                resize(m_capacity * 1.5);	
            }

            m_data[m_size] = x;
            ++m_size; // Track that we have added an element
        }

        /**
         * Removes a random item from the array using rand().
         *
         * Sources used:
         * http://www.cplusplus.com/reference/cstdlib/rand/
         */
        T pop(){
            // Pseudo-random number in the range of 0 to m_size - 1
            int index = rand() % m_size;
            T randomItem = m_data[index]; // Copy the element

            // Assign the last element in its place 
            m_data[index] = m_data[m_size - 1]; 

            --m_size; // Track that we have removed an element

            // Return the copy of the removed element
            return randomItem;
        }

    private:

        /** Points to the first element of an array holding generics */
        T* m_data;

        /** Tracks the number of elements currently held */
        int m_size = 0;

        /** Tracks the number of spots allocated in memory */
        int m_capacity = 100;	

        /**
         * Changes the capacity of the array by creating a new
         * array with the specified capacity. Copies each existing
         * element into the new array, then deallocates the memory
         * from the old one. 
         */
        void resize(int newCapacity){
            // This will hold the new array
            T* tmp = new T[newCapacity];

            // Copy all the elements
            for(int i = 0; i < m_size; ++i){
                tmp[i] = m_data[i];
            }

            m_capacity = newCapacity;
            
            // Deallocate the old memory
            delete[] m_data;	

            // Have our data point at the new array
            m_data = tmp;
        }	
};

#endif // __H_AUDS__
