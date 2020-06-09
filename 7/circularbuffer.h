#include "iterator.h"

template <typename T>
class CircularBuffer 
{
	private:
		T* ptr;
	    int front;
	    int rear;
	    size_t capacity;
	    size_t count;
	public:
	  	CircularBuffer(size_t _capacity)
		{
	        ptr = new T[_capacity + 1];
	        capacity = _capacity + 1;
	        front = 0;
	        rear = 0;
	        count = 0;
	    }
	
	    Iterator<T> begin() {
	        Iterator<T> itr(ptr, capacity, front, rear, front);
	        return itr;
	    }
	
	    Iterator<T> end() {
	        Iterator<T> itr(ptr, capacity, front, rear, rear);
	        return itr;
	    }
	    
	    void push_front(const T& val) 
		{
	        if (rear % capacity - front % capacity == 1 || (rear == capacity - 1 && front == 0)) 
	            rear = (rear + capacity - 1) % capacity;
	        else 
	            count++;
	        //front = (address + capacity -1) % length
	        front = (front + capacity - 1) % capacity;
	        ptr[front % capacity] = val;
   		}
   		
   		void push_rear(const T& val) 
		{
        if (front % capacity - rear % capacity == 1)
            front = (front + 1) % capacity;
        else 
            count++;
        //   rear = (address + 1) % Length
        ptr[rear % capacity] = val;
        rear = (rear + 1) % capacity;
    	}
	    
	    void pop_front() 
		{
        if (front % capacity != rear % capacity) 
            front = (front + 1) % capacity, count--;
        else 
            std::cout << "Empty buffer" << '\n';
    	}
    	
    	void pop_rear() 
		{
        if (front % capacity != rear % capacity) 
            rear = (rear + capacity - 1) % capacity, count--;
        else 
            std::cout << "Buffer is empty" << '\n';
    	}
    	
    	Iterator<T> insert(const Iterator<T>& itr, const T& value) 
		{
        if (itr == begin()) 
		{
            push_front(value);
            return begin();
        }
        else if (itr == end()) 
		{
            push_rear(value);
            return end() - 1;
        }
        else {
            T* buffer = new T[capacity];
            int max_size = 0;
            int ptr_buf = -1;
            int i = 0;
            for (auto it = begin(); it != end(), i <= count; it++, i++) 
			{
                if (it == itr) {
                    ptr_buf = i;
                    buffer[i] = value;
                    max_size++;
                    i++;
                }
                buffer[i] = *it;
                max_size++;
            }
            delete[] ptr;
            ptr = new T[capacity];
            for (int i = 0; i <= max_size; i++) 
			{
                ptr[i] = buffer[i];
            }
            front = 0;
            rear = max_size;
            count = max_size;
            delete[] buffer;
            return begin() + ptr_buf;
        }
    }
    
    Iterator<T> erase(const Iterator<T>& itr) {
        if (itr == begin()) {
            pop_front();
            return begin();
        }
        else if (itr == end() - 1) {
            pop_rear();
            return end() - 1;
        }
        else {
            T* buffer = new T[capacity];
            int max_size = 0;
            int ptr_buf = -1;
            int i = 0;
            for (auto it = begin(); it != end(); it++, i++) {
                if (it == itr) {
                    ptr_buf = i;
                    it++;
                }
                buffer[i] = *it;
                max_size = i;
            }
            
            delete[] ptr;
            ptr = new T[capacity];
            for (int i = 0; i <= max_size; i++) 
			{
                ptr[i] = buffer[i];
            }
            front = 0;
            rear = max_size + 1;
            count = max_size + 1;
            delete[] buffer;
            return begin() + ptr_buf;
        }
    }
    
    void resize(const size_t& _capacity) 
	{
        T* buffer = new T[capacity];
        int max_size = 0;
        for (int i = 0; i < _capacity; i++) {
            if (i == count) 
			{
                break;
            }
            buffer[i] = operator[](i);
            max_size++;
        }
        delete[] ptr;
        ptr = new T[_capacity + 1];
        for (int i = 0; i < max_size; i++) {
            ptr[i] = buffer[i];
        }
        count = max_size;
        capacity = _capacity + 1;
        front = 0;
        rear = count;
        delete[] buffer;
    }
	
	size_t size() const 
	{
        return count;
    }
    
    T& operator[] (const size_t & i) const 
	{
        return ptr[(front + i) % capacity];
    }

    ~CircularBuffer() {
        delete[] ptr;
    }
};
