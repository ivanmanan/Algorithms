// Course Schedule I

bool dfs(int course, unordered_map<int,vector<int>>& ma, unordered_set<int>& seen, unordered_set<int>& done) {

    if(done.find(course) != done.end()) {
        return true;
    }

    if(ma.find(course) == ma.end()) {
        // No dependencies
        return true;
    }

    if(seen.find(course) != seen.end()) {
        // Cycle detected
        return false;
    }

    seen.insert(course);
    for(auto& it: ma[course]) {
        if(!dfs(it, ma, seen, done)) {
            return false;
        }
    }

    seen.erase(course);
    done.insert(course);
    return true;
}


bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int,vector<int>> ma;

    for(auto& it: prerequisites) {
        ma[it[0]].push_back(it[1]);
    }

    unordered_set<int> seen;
    unordered_set<int> done;
    for(auto& it: ma) {
        if(!dfs(it.first, ma, seen, done)) {
            return false;
        }
    }
    return true;
}



//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// Course Schedule II

bool dfs(int course, vector<int>& res, unordered_map<int,vector<int>>& ma, unordered_set<int>& seen, unordered_set<int>& done) {
    if(done.find(course) != done.end()) {
        // Already handled this course before
        return true;
    }
    if(ma.find(course) == ma.end() || ma[course].empty()) {
        // Course has no dependencies
        res.push_back(course);
        done.insert(course);
        return true;
    }
    if(seen.find(course) != seen.end()) {
        // Cycle detected
        return false;
    }
    seen.insert(course);
    for(auto& it: ma[course]) {
        if(!dfs(it, res, ma, seen, done)) {
            return false;
        }
    }
    res.push_back(course);
    done.insert(course);
    seen.erase(course);
    return true;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> res;
    unordered_map<int,vector<int>> ma;

    // To prepopulate map
    for(int i = 0; i < numCourses; i++) {
        ma[i] = vector<int>();
    }

    for(auto& courses: prerequisites) {
        ma[courses[0]].push_back(courses[1]);
    }

    unordered_set<int> seen;
    unordered_set<int> done;

    for(auto& course: ma) {
        if(!dfs(course.first, res, ma, seen, done)) {
            return vector<int>();
        }
    }
    return res;
}
