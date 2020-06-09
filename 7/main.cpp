#include "circularbuffer.h"

using namespace std;

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
