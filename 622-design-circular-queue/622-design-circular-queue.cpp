class MyCircularQueue {
public:
    int front=0,back=-1,size;
    vector<int>v;
    MyCircularQueue(int k) {
        v.resize(k);
        size=k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        back=(back+1)%size;
        v[back]=value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(front==back){
            front=0,back=-1;
        }
        else {
            front=(front+1)%size;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return v[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return v[back];
    }
    
    bool isEmpty() {
        return back==-1;
    }
    
    bool isFull() {
        if(back!=-1 && (back+1)%size==front) return true;
        return false;
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