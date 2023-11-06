class SeatManager {
public:
    int val = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        
    }
    
    int reserve() {
        int x = -1;
        if(pq.empty()){
            return ++val;
        }
        else{
            x = pq.top();
            pq.pop();
        }
        return x;
    }
    
    void unreserve(int seatNumber) {
        if(val == seatNumber){
            --val;
        }
        else{
            pq.push(seatNumber);
        }
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */