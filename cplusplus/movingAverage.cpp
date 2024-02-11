class MovingAverage {
public:
// [1,2,3] --> 6/3 = 2
    MovingAverage(int size) {
        window_size = size;
    }

    double next(int val) {
        dq.push_back(val);
        total += val;
        if(dq.size() > window_size) {
            total -= dq.front();
            dq.pop_front();
        }
        return total / double(dq.size());
    }
private:
    list<int> dq;
    double total = 0;
    int window_size;
};
