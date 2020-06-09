#include <iostream>
#include <algorithm>
#pragma once

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

