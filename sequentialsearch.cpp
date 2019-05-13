#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

int main(){
    ifstream myFile;
    myFile.open("sgb-words.txt");
    if(myFile.is_open()){
        cout << "file opened" << endl;
    }
    vector<string>myVector;
    string words, findWord;
    int wordLocation;
    //Passing words into myVector.
    while(myFile >> words){
        myVector.push_back(words);
    }
    cout << "Enter the word you want to find in the word list" << endl;
    cin >> findWord;
    if(findWord.size()!= 5){
        cout << "Re-enter a five-letter word for searching." << endl;
    }
    while(findWord.size() != 5){
        cin >> findWord;
    }
    return 0;
}
//The following are some additional information about sequential search by Dr.Kramer.
/*Sequential Search.
Three questions about the algorithm.
Question 1: What if the first list position is 1, not 0?
Yes, 
If the first position is j , replace all occurrences of
L[i ] with L[i + j ].

Question 2: Can we always compare keys?
Yes, 
Lists for searching must always contain comparable data types
Numeric keys use standard operators
Strings can use either strcmp() or C++ string operators
More complex keys may require more work

Question 3: How do we indicate success and failure?
Return valid index for success, invalid index for failure
Return pointer to data if successful, NULL if not
Either of the above if successful, throw an exception if not
*/
