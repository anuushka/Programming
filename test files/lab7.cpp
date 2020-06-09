#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class Iterator: public std::iterator<std::random_access_iterator_tag, T>
{
	private:
		T* data;
		int pos;
		int front;
		int rear;
		size_t capacity;
	public:
		//difference iterator: p2-p1, distances and ptr counts.
    using difference_type = typename std::iterator<std::random_access_iterator_tag, T>::difference_type;
	Iterator(T* buf, size_t& _capacity, int& _front, int& _rear, int _pos)
	{
		data = buf;
		capacity = _capacity;
		front = _front;
		rear = _rear;
		pos = _pos;
	}
	
	bool operator== (Iterator const& other) const {
        return this->pos % capacity == other.pos % capacity;
    }
		
	bool operator!= (Iterator const& other) const
	{
		return this->pos % capacity != other.pos % capacity;
	}
	
	bool operator>  (const Iterator& rhs) const
	{
		if(front > rear)
		{
			if(pos < capacity && rhs.pos < capacity)
				return pos > rhs.pos;			
			else if(pos > capacity)
				return false;
			else if(rhs.pos < capacity)
				return true;
			else
				return pos > rhs.pos;
		}
		else
			return pos > rhs.pos;
	}
	
	bool operator>= (const Iterator& rhs) const 
	{
        if (front > rear) 
		{
            if (pos < capacity && rhs.pos < capacity) 
                return pos >= rhs.pos;
            else if (pos < capacity) 
                return false;
            else if (rhs.pos < capacity) 
                return true;
            else 
                return pos >= rhs.pos;
        }
        else
            return pos >= rhs.pos;
    }
	
	bool operator< (const Iterator& rhs) const
	{
		if(front > rear)
		{
			if(pos < capacity && rhs.pos < capacity)
				return pos < rhs.capacity;
			else if(rhs.pos < capacity)
				return false;
			else if(pos < capacity)
				return true;
			else
				return pos < rhs.pos;
		}
		else
			pos < rhs.pos;
	}
	
	 bool operator<= (const Iterator& rhs) const 
	 {
        if (front > rear) {
            if (pos < capacity && rhs.pos < capacity) 
                return pos <= rhs.pos;
            else if (pos < capacity) 
                return true;
            else if (rhs.pos < capacity) 
                return false;
            else 
                return pos <= rhs.pos;
        }
        else 
            return pos <= rhs.pos;
    }
	
	difference_type operator- (const Iterator& it) const {
        Iterator itr = *this;
        itr.pos -= it.pos;
        return *itr;
    }

    difference_type operator+ (const Iterator& it) const {
        Iterator itr = *this;
        itr.pos += it.pos;
        return *itr;
    }

    Iterator operator+ (const int& ptr) const {
        Iterator itr = *this;
        itr.pos = (pos + ptr) % capacity;
        return itr;
    }

     Iterator operator- (const int& ptr) const {
        Iterator itr = *this;
        itr.pos = (pos + capacity - ptr) % capacity;
        return itr;
    }
    
    Iterator operator++ () {
        this->pos++;
        return *this;
    }

    Iterator operator++ (int) {
        Iterator tmp(*this);
        operator++ ();
        return tmp;
    }

    Iterator operator-- () {
        this->pos--;
        return *this;
    }
    Iterator operator-- (int) {
        Iterator tmp(*this);
        operator-- ();
        return tmp;
    }
    
     typename Iterator::reference operator* () const 
	{
        return data[pos % capacity];
    }
};

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
            cout << "Empty buffer" << '\n';
    	}
    	
    	void pop_rear() 
		{
        if (front % capacity != rear % capacity) 
            rear = (rear + capacity - 1) % capacity, count--;
        else 
            cout << "Buffer is empty" << '\n';
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
	int main() {
    CircularBuffer<int> Buffer(10);
    Buffer.push_front(2);
    Buffer.push_rear(25);
    Buffer.push_front(36);
    Buffer.push_rear(49);
    Buffer.push_rear(64);
    Buffer.push_rear(100);
    Buffer.push_front(4);
    Buffer.push_rear(16);
    Buffer.push_front(9);
    Buffer.push_front(81);
    
	//Display
    cout << "CircularBuffer[10]: ";
    for (int i : Buffer) 
        cout << i << " ";
    cout << '\n';
    
    //Delete 9
    cout << "Delete 9: ";
    Buffer.erase(find(Buffer.begin(), Buffer.end(), 9));
    for (int i : Buffer) 
        cout << i << " ";
    cout << '\n';
    
    //Delete 36
    cout << "Delete 36: ";
    Buffer.erase(find(Buffer.begin(), Buffer.end(), 36));
    for (int i : Buffer) 
        cout << i << " ";
    cout << '\n';
    
    //Inser 225 at Buffer[5]
    cout << "Insert 225 at place of 6: ";
    Buffer.insert(find(Buffer.begin(), Buffer.end(), Buffer[5]), 225);
    for (int i : Buffer) 
        cout << i << " ";
    cout << '\n';
    
    //Change Capacity
    cout << "Change to Capacity to 5: ";
    Buffer.resize(5);
    for (int i : Buffer) 
        cout << i << " ";
    cout << '\n';
    
    //Push top
    cout << "Push top 0: ";
    Buffer.push_front(0);
    for (int i : Buffer) 
        cout << i << " ";
    cout << '\n';
    
    //Pop top
    cout << "Pop top: ";
    Buffer.pop_front();
    for (int i : Buffer) 
        cout << i << " ";
    cout << '\n';
    
    //Push back
    cout << "Push back 49: ";
    Buffer.push_rear(49);
    for (int i : Buffer) 
        cout << i << " ";
    cout << '\n';
    
    //Pop back
    cout << "Pop back: ";
    Buffer.pop_rear();
    for (int i : Buffer) 
        cout << i << " ";
    cout << '\n';
    return 0;
}
