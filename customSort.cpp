/*

  PHONE INTERVIEW

 unordered_map, map
 vector<int> answer

 arr = [4, 5, 6, 5, 4, 3]

 map<int,int> {KEY:VALUE} = {a[i], frequency_count}

 map sorts the keys in ascending order

 freq - display the keys with same freq; increment freq count, then loop again


 map<int,int> {KEY:VALUE} = {a[i], freq_count}
 map<int,int> {KEY:VALUE} = {freq_count, vector}


 */

// size of arr is N
void customSort(vector<int> arr) {

    map<int,int> numsFreq;
    vector<int> sorted;

    // Create numbers frequency map

    // O(N)
    for(int i = 0; i < arr.size(); i++) {

        auto got = numsFreq.find(arr[i]);

        // Finding in hash table O(1) at average case
        // If collisions occur, then worst case is O(N)
        if(got != numsFreq.end()) {

            (got->second)++;
        }
        else {
            // O(log N) -- sort the iteration of the keys
            numsFreq.insert({arr[i], 1});
        }
    }
    // O(N log N)

    map<int,vector<int>> freqArrMap;

    // O(N) --> if every key has a frequency count of 1
    for(auto it = numsFreq.begin(); it != numsFreq.end(); it++) {


        auto got = freqArrMap.find(it->second);
        int count = 0;

        // If exists in hash table
        if(got != freqArrMap.end()) {

            while(count < it->second) {
                (got->second).push_back(it->first);
                count++;
            }
        }
        else {
            vector<int> nums;
            while(count < it->second) {
                nums.push_back(it->first);
                count++;
            }
            // O(log N)
            freqArrMap.insert({it->second, nums});
        }
    }
    // O(N log N)

    for(auto it = freqArrMap.begin(); it != freqArrMap.end(); it++) {

        for(auto ite = (it->second).begin(); ite != (it->second).end(); ite++) {
            cout << *ite << endl;
        }
    }
    // O(N)

    // FINAL TIME COMPLEXITy
    // O(N log N + N log N + N)
    // O(2 N log N + N)
    // O(N log N)

    // SPACE COMPLEXITY
    // maps, vector
    // O(N)


}