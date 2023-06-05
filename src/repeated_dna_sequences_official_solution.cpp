/*  Problem: Repeated DNA Sequences
*/
#include <bits/stdc++.h>

using namespace std;

std::set<std::string> FindRepeatedSequences(std::string s, int k)
{
    int windowSize = k;
    if (s.size() <= windowSize)
    {
        return {};
    }
    int base = 4;
    int hiPlaceValue = std::pow(base, windowSize);
    std::map<char, int> mapping;
    mapping['A'] = 1;
    mapping['C'] = 2;
    mapping['G'] = 3;
    mapping['T'] = 4;
    std::vector<int> numbers{};
    for (int i = 0; i < s.size(); i++)
    {
        numbers.push_back(mapping[s[i]]);
    }
    int hashing = 0;
    std::set<int> substringHashes{};
    std::set<std::string> output{};
    for (int start = 0; start < (s.size() - windowSize + 1); start++)
    {
        if (start != 0)
        {
            hashing = hashing * base - numbers[start - 1] * hiPlaceValue + numbers[start + windowSize - 1];
        }
        else
        {
            for (int end = 0; end < windowSize; end++)
            {
                hashing = hashing * base + numbers[end];
            }
        }
        if (substringHashes.find(hashing) != substringHashes.end())
        {
            output.insert(s.substr(start, windowSize));
        }
        substringHashes.insert(hashing);
    }
    return output;
}

// Driver code
int main()
{
    std::vector<std::string> inputsString = {
        "ACGT", "AGACCTAGAC", "AAAAACCCCCAAAAACCCCCC",
        "GGGGGGGGGGGGGGGGGGGGGGGGG", "TTTTTCCCCCCCTTTTTTCCCCCCCTTTTTTT",
        "TTTTTGGGTTTTCCA", "", "AAAAAACCCCCCCAAAAAAAACCCCCCCTG", "ATATATATATATATAT"};
    std::vector<int> inputsK = {3, 3, 8, 12, 10, 14, 10, 10, 6};

    for (int i = 0; i < inputsK.size(); i++)
    {
        std::cout << i + 1 << ".\tInput Sequence: '" << inputsString[i] << "'\n";
        std::cout << "\tk: " << inputsK[i] << "\n";
        std::cout << "\tRepeated Subsequence: "
                  << Print(FindRepeatedSequences(inputsString[i], inputsK[i])) << "\n";
        std::cout << std::string(100, '-') << "\n";
    }
}
