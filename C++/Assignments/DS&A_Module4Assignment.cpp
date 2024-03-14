#include <iostream>
using namespace std;

//Write a recursive function to check if a string is a palindrome (a set of letters or numbers that is the same whether read forward or backward). Also, write a program to test your function on at least one palindromic word and one non-palindromic word. Submit the cpp file, and copy and paste the screenshot of the output here.
string palindrome(string word, int start, int end);

int main()
{
    //example function
    string word1 = "word";
    string word2 = "madam";
    cout << "this code determinds if a word is a palindrome" << "\n" << endl;
    cout << "for example: " << endl;
    cout << palindrome(word1, word1.length() * 0, word1.length() - 1) << endl;
    cout << palindrome(word2, 0, word2.length() - 1) << "\n" << endl;

    // get a word and determine its length, and its start / end element
    string word;
    cout << "Enter a word: ";
    cin >> word;
    int start = word.length() * 0;
    int end = word.length() - 1;

    cout << palindrome(word, start, end) << endl;
}

string palindrome(string word, int start, int end)
{
    if (start >= end) // base case, if start >= end then stop
    {
        cout << "The following word is a palindrome: ";
        return word;
    }

    if (word[start] != word[end])
    {
        cout << "The following word is not a palindrome: ";
        return word;
    }
    else
    {
        // Recursive case: check if word[start] = word[end]
        return palindrome(word, start + 1, end - 1);
    }

}