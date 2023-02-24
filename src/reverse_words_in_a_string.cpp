/*  Problem: Reverse Words in a String
    Date: Feb 21, 2023
    Time Complexity: O(n)
    Space Complexity:
        Solution #1: O(n)
        Solution #2: O(1)
*/

#include <bits/stdc++.h>
#include <lest.hpp>

using namespace std;

/* Solution #1
    Identify the word breaks and store the start, end positions of the words in a vector.
    Iterate this vector in reverse direction and create reversed string by adding a space between consecutive words.
*/ 
string ReverseWordsSolution1(string sentence)
{
    unsigned int i = 0;
    unsigned int j;
    vector<pair<unsigned int, unsigned int>> vec_word_pos_pair;

    while (i < sentence.size())
    {
        // Keep right shifting of i till it either reaches the begin of next word or end of the string, whichever is earlier
        while ((i < sentence.size()) && (sentence[i] == ' '))
        {
            ++i;
        }

        if (i < sentence.size())
        {
            j = i;

            // Keep right shifting of j till it reaches the end of current word
            while ((j < sentence.size()) && (sentence[j] != ' '))
            {
                ++j;
            }

            vec_word_pos_pair.push_back(make_pair(i, j));

            // Update i for the next iteration
            i = j;
        }
    }

    string reverse_words_sentence = "";

    for (auto it=vec_word_pos_pair.rbegin(); it != vec_word_pos_pair.rend(); ++it)
    {
        if (it != vec_word_pos_pair.rbegin())
        {
            reverse_words_sentence += " ";
        }
        reverse_words_sentence += sentence.substr((*it).first, (*it).second - (*it).first);
    }    

    return reverse_words_sentence;
}

/* Solution #2
    Unlike solution #1, this reverses the words in the sentence in-place.
    This solution is inspired by the official solution mentioned in Educative.
    The difference being that instead of a user-defined function to reverse characters of the words,
     in-built function reverse() has been utilized.
*/
string ReverseWords(string sentence)
{
    // Step #0: Remove the leading and trailing spaces from the input string.
    sentence = regex_replace(sentence, regex("^ +| +$|( ) +"), "$1");
    // cout << "Sentence post regex: " << sentence << endl;

    // Step #1: Reverse the entire sentence
    reverse(sentence.begin(), sentence.end());

    // Step #2: (a) Identify the word breaks. (b) For each word, reverse it's characters.
    unsigned int start = 0;
    unsigned int end;

    while (start < sentence.size())
    {
        // current word range: [start, end)
        end = start + 1;
        while ((end < sentence.size()) && (sentence[end] != ' '))
        {
            ++end;
        }
        
        // Reverse the characters of the current word
        reverse(sentence.begin()+start, sentence.begin()+end);

        // Identify the start of next word
        start = end;

        while ((start < sentence.size()) && (sentence[start] == ' '))
        {
            ++start;
        }
    }
    
    // cout << "Updated string: " << sentence << endl;
    return sentence;
}

const lest::test tests[] = {
    CASE("Test Case 1"){
        string sentence = "We love Python";
        string reverse_words_sentence = ReverseWords(sentence);
        EXPECT(reverse_words_sentence == "Python love We");
    },
    CASE("Test Case 2"){
        string sentence = " To be or    not to     be  ";
        string reverse_words_sentence = ReverseWords(sentence);
        EXPECT(reverse_words_sentence == "be to not or be To");
    },
    CASE("Test Case 3"){
        string sentence = "You are amazing";
        string reverse_words_sentence = ReverseWords(sentence);
        EXPECT(reverse_words_sentence == "amazing are You");
    },
    CASE("Test Case 4"){
        string sentence = "Hello     World";
        string reverse_words_sentence = ReverseWords(sentence);
        EXPECT(reverse_words_sentence == "World Hello");
    },
    CASE("Test Case 5"){
        string sentence = "Hey";
        string reverse_words_sentence = ReverseWords(sentence);
        EXPECT(reverse_words_sentence == "Hey");
    },
    CASE("Test Case 6"){
        string sentence = " ";
        string reverse_words_sentence = ReverseWords(sentence);
        EXPECT(reverse_words_sentence == "");
    },
    CASE("Test Case 7"){
        string sentence = "";
        string reverse_words_sentence = ReverseWords(sentence);
        EXPECT(reverse_words_sentence == "");
    },
};

int main(int argc, char** argv)
{
    lest::run(tests, argc, argv);
}
