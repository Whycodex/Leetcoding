class MyCircularQueue {
public:
    vector<int>v;
    int start=0;
    int size=0;
    MyCircularQueue(int k) {
        v.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull()==true)
            return false;
        v[(start+size)%v.size()]=value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()==true)
            return false;
        start=(start+1)%v.size();
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()==true)
            return -1;
        return v[start];
    }
    
    int Rear() {
        if(isEmpty()==true)
            return -1;
        return v[(start+size-1)%v.size()];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==v.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */