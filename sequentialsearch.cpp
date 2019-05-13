#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<random>

using namespace std;

int sequentialSearch(vector<string>testVector,int number,string key);
int sentinelSearch(vector<string>testVector, int number,string key);
int probabilitySearch(vector<string>testVector, int number,string key);
int promote(vector<string>testVector, int i);
int orderedSearch(vector<string>testVector, int number,string key);

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
    sequentialSearch(myVector,myVector.size(),findWord);
    sentinelSearch(myVector,myVector.size(),findWord);
    probabilitySearch(myVector,myVector.size(),findWord);
    orderedSearch(myVector,myVector.size(),findWord);
    return 0;
}

int sequentialSearch(vector<string>testVector,int number,string key){
    int i = 0;
    while(i < number && testVector[i] != key){
         i++;
    }
    //printing out the index of the word you entered.
    cout << "The index number of your word is: " << i << " by sequential search."<< endl;
    if(i < number){
        return true;
    }
    else{
        return false;
    }
}

int sentinelSearch(vector<string>testVector, int number,string key){
    testVector[number] = key;
    int i = 0;
    while(testVector[i] != key){
        i++;
    }
    cout << "The index number of your word is: " << i << " by sentinel search." << endl;
    if(i < number){
        return true;
    }
    else{
        return false;
    }
}

int probabilitySearch(vector<string>testVector, int number,string key){
    int i = 0;
    while(i < number && testVector[i] != key){
        i++;
    }
    cout << "The index number of your word is: " << i << " by probability search." << endl;
    if(i < number){
        i = promote(testVector,number);
        return true;
    }
    else{
        return false;
    }
}
int promote(vector<string>testVector, int i){
    string temp = testVector[i];
    int j;
    j = i - rand();
    if(j < 0){
        j = 0;
    }
    while(i > j){
        testVector[i] = testVector[i - 1];
        i--;
    }
    testVector[i] = temp;
    return i;
}
int orderedSearch(vector<string>testVector, int number,string key){
    int i = 0;
    while(i < number && testVector[i] != key){
        i++;
    }
    cout << "The index number of your word is: " << i << " by ordered search." << endl;
    if(i < number && testVector[i] == key){
        return true;
    }
    else{
        return false;
    }
}

//The following are some additional information about sequential search by Dr.Kramer.
/*Sequential Search.
Three questions about the algorithm.
Question 1: What if the first list position is 1, not 0?
Yes, 
If the first position is j , replace all occurrences of
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

/* Sentinel Search Restrictions 
Two restrictions on Sentinel Search.
1. You must be able to add k to the end of the list and remove it if
necessary. Must use Sequential Search otherwise.
2. Adding and removing must be faster than O(n) time
No faster than Sequential Search otherwise 
*/

/* Probability Search
Probability Search comes in two favors:
Static. - Boring, Arrange data before searching, and use sequential or sentinel search.
Dynamic. - Start with sequential or sentinel search and if k is found, move it forward in the list.
*/
