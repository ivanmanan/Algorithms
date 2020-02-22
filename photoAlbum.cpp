#include <iostream>
#include <vector>
#include <list>

using namespace std;

/*
  Given a vector of indices, I want to sort based on their identities such that
  identity[i+1] > identity[i]. Afterwards, I return the sorted identities.
 */

vector<int> photoAlbum(vector<int> index, vector<int> identity) {

    // Use a linked list from STL b/c it already handles the pointer rearrangements after inserting a new node
    list<int> album;


    for(int i = 0; i < index.size(); i++) {

        auto it = album.begin();
        for(int j = 0; j < index[i]; j++) {
            it++;
        }
        album.insert(it, identity[i]);
    }

    vector<int> res;
    for(auto it = album.begin(); it != album.end(); it++) {
        res.push_back(*it);
    }
    return res;
}