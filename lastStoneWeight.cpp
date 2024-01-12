int lastStoneWeight(vector<int>& stones) {

    priority_queue<int> pq(stones.begin(), stones.end());
    int res = 0;
    while(!pq.empty()) {
        res = pq.top();
        pq.pop();

        if(pq.empty()) {
            break;
        }
        else {
            // Calculate stone differences
            int second = pq.top();
            pq.pop();
            res = res - second;
            pq.push(res);
        }
    }
    return res;
}
