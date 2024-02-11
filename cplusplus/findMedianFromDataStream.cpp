class MedianFinder {
public:
/*
    [1, 2, 3, 4] -> median=2.5


    Small heap: [1,2] --> max heap
    Large heap: [3,4] --> min heap

    All elements in small heap must be smaller than elements in large heap

    If the heap are the same size: Take top of small and large heap, and
    calculate the average

    If the heaps are different size by 1:
    Take the top of heap stack that has the larger size.

    Always balance the heap such that the heap sizes differ by 1.
*/
    MedianFinder() {

    }

    void addNum(int num) {
        if(smallheap.empty()) {
            smallheap.push(num);
        }
        else if(largeheap.empty()) {
            int transfer = smallheap.top();
            if(num < transfer) {
                smallheap.pop();
                smallheap.push(num);
                largeheap.push(transfer);
            }
            else {
                largeheap.push(num);
            }
        }
        else {
            if(num > largeheap.top()) {
                largeheap.push(num);
            }
            else {
                smallheap.push(num);
            }

            // Balance the heaps
            if(smallheap.size() > largeheap.size()+1) {
                // smallheap cannot be more than 2 numbers greater
                int leftmedian = smallheap.top();
                smallheap.pop();
                largeheap.push(leftmedian);
            }
            else if(largeheap.size() > smallheap.size()) {
                // largeheap cannot be greater
                int rightmedian = largeheap.top();
                largeheap.pop();
                smallheap.push(rightmedian);
            }
        }
    }

    double findMedian() {
        if(smallheap.empty()) {
            return 0;
        }
        if(largeheap.empty()) {
            return smallheap.top();
        }

        if(largeheap.size() == smallheap.size()) {
            // Take average
            int leftmedian = smallheap.top();
            int rightmedian = largeheap.top();
            return (double(leftmedian+rightmedian))/double(2);
        }
        else {
            return smallheap.top();
        }
    }
private:
    priority_queue<int> smallheap;
    priority_queue<int,vector<int>,greater<int>> largeheap;
};
