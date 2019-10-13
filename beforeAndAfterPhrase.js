/*
   Clutter coding challenge
   NOTE: the solution was to use a hash table with {key:value} pair as
   {first_word:array_of_possible_phrases}
 */

function generate_phrases(phrases) {
  let ans = [];
  let phrases_map = {};

  // Create dictionary with {key:value} pair as {beginning word:phrase}
  for(let i = 0; i < phrases.length; i++) {

    // split string by spaces
    let res = phrases[i].split(" ");
    let beginning_word = res[0];

    // Must remove beginning word from the string
    // Since we know beginning word exists in the phrase,
    // then we can slice it and append a space
    let start = beginning_word.length;
    // Account for whitespace character
    let subtract_first_word = phrases[i].slice(start+1);

    // If exists in hash table, then push_back into array
    if(beginning_word in phrases_map) {
      phrases_map[beginning_word].push(subtract_first_word);
    } // Does not exist in hash table, so insert new array
    else {
      let val = [];
      val.push(subtract_first_word);
      phrases_map[beginning_word] = val;
    }
  }

  // Iterate every phrase if end word is found in hash table
  for (let i = 0; i < phrases.length; i++) {
    let phrase = phrases[i];
    let res = phrase.split(" ");
    let length = res.length;
    let last_word = res[length - 1];

    // Last word exists in hash table
    if (phrases_map[last_word] !== undefined) {
      for(let i = 0; i < phrases_map[last_word].length; i++) {
        let add_phrase = phrases_map[last_word][i];
        ans.push(phrase + " " + add_phrase);
      }
    }
  }
  // ASSUME: This is only for pairs and not for duplicates
  return ans;
}

input = ["mission statement", "a man on a mission", "mission impossible"];
let x = generate_phrases(input);

console.log(x);