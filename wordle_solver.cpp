#include "./wordle_solver.h"
// #include "./temp.h"
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

/*

5 letter word

Given simple word, no duplicate letters.

Build the result

1st guess: solar

green _ _ yellow yellow

--> ANSWER: spare

Given list of words: what is the next possible guess.



STRATEGY:
1. Maximum information - use LARES or CRANE.
2. Rank each word with a score - green, yellow, grey

Green --> words containing that letter in that spot will be granted 5 points
Yellow --> words containing that letter not in a green spot nor grey spot will be granted 2 points

INPUT:

CRANE
_YG_G

R_ARE --> Words like this would be granted 14 points - this is the maximum

Take every permutation of the word, and see if it exists in the set

If CRANE has no matching word, then move on to POINT.
26^6 = 308,915,776 different queries worst case.

Answer: SPARE

There are about 13,000 5-letter words in the English dictionary.

First guess will always be CRANE.
2nd guess: Iterate and rank 13,000 words. Drop words that meet the exclusion criteria.
3rd guess: Iterate and rank remaining words.
...

13,000 + 13,000 + 13,000 + 13,000 + 13,000 = 65,000 computations worst case.

After the first guess, we keep a new list/heap of candidate words IF there are green letters
--> We stop processing the rest of the words in the heap if they cannot compete with the rest of the rankings.


BASE CASE: No duplicate letters. Let's not deal with frequency for now.

Criteria to exclude:
1. Green letters do not match.
2. Word not contain all the yellow letters
3. Word contains a yellow letter in a previously guessed position
4. Word contains black letters.

*/

const int WORD_SIZE = 5;

vector<int> guessWord(string answer, string guess, int round) {
    // Returns [ 0-5-10, 0-5-10, 0-5-10, 0-5-10, 0-5-10 ]
    cout << "GUESS " << round << ": " << guess << endl;

    if(answer == guess) {
        vector<int> temp(WORD_SIZE, 2);
        cout << "CORRECT GUESS!" << endl;
        exit(0);
        return temp;
    }
    else {

        // TODO: Handle frequency - use a map
        unordered_set<char> yellows;
        for(int i = 0; i < WORD_SIZE; i++) {
            yellows.insert(answer[i]);
        }

        vector<int> res(WORD_SIZE, 0);
        for(int i = 0; i < WORD_SIZE; i++) {
            if(guess[i] == answer[i]) {
                // Mark as green letter
                res[i] = 2;
            }
            // else if(yellows.find(guess[i]) != yellows.end()) {
            else if(answer.find(guess[i]) != std::string::npos) {
                // Mark as yellow letter
                // Exists in hash
                res[i] = 1;
                cout << "YELLOW AT INDEX: " << i;
                cout << "; REAL INDEX: " << answer.find(guess[i]) << endl;
            }
            else {
                // Mark as black letter
                res[i] = 0;
            }
        }
        for(auto& it: res) {
            cout << it << ", ";
        }
        cout << endl;
        return res;
    }
}


void wordle_solver(string answer, unordered_set<string> words) {

    vector<int> data;

    string guess1 = "lares";

    data = guessWord(answer, guess1, 1);

    // 0 == black
    // 1 == yellow
    // 2 == green

    // Rank words
    /*
        CRITERIA TO EXCLUDE
        1. Green letters do not match.
        2. Word not contain all the yellow letters
        3. Word contains a yellow letter in a previously guessed position
        4. Word contains black letters.
    */

    // Key: ranking, Value: word --- permits duplicate keys
    multimap<int, string> candidates;

    /*
        lares
        0, 1, 0, 0, 0 --> Take current ranking. The word must have ranking above or equal to this
        adhoc
    */

    // Black letters
    unordered_set<char> invalid_characters;
    // Yellow letters - Key: letter, Value: invalid indexes
    unordered_map<char,unordered_set<int>> incorrect_indexes;
    int minimum_ranking = 0;
    for(int i = 0; i < data.size(); i++) {
        if(data[i] == 0) {
            // Black letter
            invalid_characters.insert(guess1[i]);
        }
        if(data[i] == 1) {
            minimum_ranking += 1;
            auto got = incorrect_indexes.find(guess1[i]);
            if(got != incorrect_indexes.end()) {
                // Already exists
                (got->second).insert(i);
            }
            else {
                incorrect_indexes[guess1[i]] = {i};
            }
        }
        if(data[i] == 2) {
            minimum_ranking += 10;
        }
    }



    // We have guess1
    // Iterate through all 13,000 5-letter word dictionary
    for(auto& word : words) {
        int rank = 0;
        bool valid_word = true;
        for(int i = 0; i < word.length(); i++) {

            // Green letter
            if(data[i] == 2) {
                if(word[i] != guess1[i]) {
                    // If the word does not match the green letter, then drop the word
                    valid_word = false;
                    break;
                }
                else {
                    // Green letters match
                    rank += 10;
                }
            }
            else if(invalid_characters.find(word[i]) != invalid_characters.end()) { // Black letters
                // If black letters exist, then drop the word
                valid_word = false;
                break;
            }
            else if(incorrect_indexes.find(word[i]) != incorrect_indexes.end()) {
                // Check the word has yellow letter but not in previous position
                unordered_set<int> temp = incorrect_indexes[word[i]];
                if(temp.find(i) != temp.end()) {
                    valid_word = false;
                    break;
                }
                else {
                    rank += 1;
                }
            }
        }

        if(valid_word && rank >= minimum_ranking) {
            candidates.insert(make_pair(rank, word));
        }
    }

    for(auto it = candidates.rbegin(); it != candidates.rend(); it++) {
        string ranking = to_string(it->first);
        string word = it->second;
        // cout << "CANDIDATE: " << word << "; RANK: " << ranking << endl;
    }

    vector<int> done = guessWord(answer, answer, 13);
}



int main() {
    Helper helper;
    unordered_set<string> words = helper.get_words();

    // for(const auto& it: words) {
    //     cout << it << endl;
    //     break;
    // }

    wordle_solver("acers", words);
}
