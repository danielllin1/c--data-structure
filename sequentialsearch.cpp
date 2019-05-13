#include<iostream>
#include<fstream>
#include<vector>
#include<string>

//This is a sequential search file I created to search words in a dictionary("sgb-words.txt") of 5756 words.

using namespace std;

int myTest(vector<string>testVector,int number,string key);

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
    while(findWord.size() != 5){
        cout << "Re-enter a five-letter word for searching." << endl;
        cin >> findWord;
    }
    //This is a simple loop to perform sequential search.
    for(int i = 0; i < myVector.size(); i++){
        if(myVector[i] == findWord){
            wordLocation = i;
        }
    }
    //Checking the boundary.
    if(wordLocation == 0){
        cout << "The word you entered can not be found in the dictionary." << endl;
    }
    //printing out the index of the word you entered.
    else{
    cout << "The index number of your word is: " << wordLocation << endl;
    }
    //-------------.
    //myTest function is what I learned from Data structure class.
    myTest(myVector,myVector.size(),findWord);
        return 0;
}
int myTest(vector<string>testVector,int number,string key){
    int i = 0;
    while(i < number && testVector[i] != key){
         i++;
    }
    //Checking the boundary.
    if(i == number && key != testVector[i]){
        cout << "The word you entered can not be found in the dictionary." << endl;
    }
    else{
    //printing out the index of the word you entered.
        cout << "The index number of your word is: " << i << endl;
    }
    if(i < number){
        return true;
    }
    else{
        return false;
    }
}
//The following are some additional information about sequential search by Dr.Kramer.
/*Sequential Search.
Three questions about the algorithm.
Question 1: What if the first list position is 1, not 0?
Yes, 
If the first position is j , replace all occurrences of L[i ] with L[i + j ].

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
