/*  Problem: Repeated DNA Sequences
    URL: https://www.educative.io/courses/grokking-coding-interview-patterns-cpp/JQRABNDZBxg
    Date: 02nd June 2023

    Approach: Window sliding and usage of polynomial rolling hash function.

    Complexity:
        Time: O(nk) (Average case)
                - (k due to substr)
        Space: O(n)
*/

#include <bits/stdc++.h>
#include <lest.hpp>

using namespace std;

set<string> FindRepeatedSequences(string s, int k)
{
    // Define the parameters of the polynomial rolling hash function.
    long long p = 31;
    long long m = 1e9 + 7;

    // key: hash value, value: set of strings having that hash value
    // N.B. There's possibility of multiple strings mapping to same hash value due to hash collision.
    unordered_map<long long, set<string>> hash_str_map;
    // key: substring, value: count (frequency of the substring in the given string)
    unordered_map<string, unsigned int> substr_count_map;

    long long cur_hash_val = 0;
    long long p_pow = 1;
    unsigned int i = 0;

    while (i != (k-1))
    {
        cur_hash_val += (s[i] - 'A')*p_pow;
        p_pow *= p;
        i += 1;
    }

    // Now p_pow = p^(k-1)
    
    cur_hash_val += (s[i] - 'A')*p_pow;

    // Populate hash maps for the 1st substring
    hash_str_map[cur_hash_val] = {s.substr(0, k)};
    substr_count_map[s.substr(0, k)] = 1;
    
    // Slide window of length k over the string and compute the hash for the current substring
    while (i != (s.size()-1))
    {
        i += 1;

        // Compute the hash value for the current substring.
        // We can utilize the hash value computation of previous substring.
        cur_hash_val -= (s[i-k] - 'A');
        cur_hash_val /= p;
        cur_hash_val += (s[i] -'A')*p_pow;

        unordered_map<long long, set<string>>::iterator it = hash_str_map.find(cur_hash_val);
        string cur_substr = s.substr(i-k+1,k);
        
        if (it == hash_str_map.end())
        {
            hash_str_map[cur_hash_val] = {cur_substr};
            substr_count_map[cur_substr] = 1;
        }
        else
        {
            // set elements are unique. Inserting an already existing element would be ignored.
            // Thus no need to search before insert.
            (*it).second.insert(cur_substr);

            if (substr_count_map.find(cur_substr) == substr_count_map.end())
            {
                substr_count_map[cur_substr] = 1;
            }
            else
            {
                substr_count_map[cur_substr] += 1;
            }
        }

    }
    
    // Populate the output set with the substring which have occurrence > 1.
    set<string> output{};

    for (unordered_map<string, unsigned int>::iterator it_substr_count=substr_count_map.begin(); it_substr_count != substr_count_map.end(); ++it_substr_count)
    {
        if ((*it_substr_count).second > 1)
        {
            output.insert((*it_substr_count).first);
        }
    }

    return output;
}

lest::test tests[] = {
    CASE("Test Case #1"){
        string s = "ATATATATATATATAT";
        int k = 6;
        set<string> output = {"TATATA", "ATATAT"};
        EXPECT(FindRepeatedSequences(s,k) == output);
    },
    CASE("Test Case #2"){
        string s = "AGAGCTCCAGAGCTTG";
        int k = 6;
        set<string> output = {"AGAGCT"};
        EXPECT(FindRepeatedSequences(s,k) == output);
    },
    CASE("Test Case #3"){
        string s = "AGCTGAAAGCTTAGCTG";
        int k = 5;
        set<string> output = {"AGCTG"};
        EXPECT(FindRepeatedSequences(s,k) == output);
    }
};

int main(int argc, char** argv)
{
    lest::run(tests, argc, argv);
}
