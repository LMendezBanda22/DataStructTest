#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
//I am really tired
/*
I can't wait for the physics exam....;-;-;-;
*/
struct wordItem {
string word;
int count;
};

void getStopWords(const char *ignoreWordFileName, string ignoreWords[])
{
    ifstream infile(ignoreWordFileName);
    if (infile.is_open())
    {
     string line;
     int counter=0;
     while (getline(infile, line))
     {
      ignoreWords[counter]=line;
      counter++;
     }


    }
    else
    {
        cout << "Failed to open" << ignoreWordFileName << endl;
    }

}

bool isStopWord(string word, string ignoreWords[])
{
    for (int i=0; i<50; i++)
    {
        if (ignoreWords[i]==word)
        {
            return 1;
        }
    }

    return 0 ;
}
void arraySort(wordItem uniqueWords[], int length)
{
int temp;
string temp2;
//algorithm for an ascending bubble sort algorithm, not very efficient but it works
for(int i =0; i< length-1; i++)
{
for(int j = 0; j < length-1; j++){
if(uniqueWords[j].count<uniqueWords[j+1].count)
{
temp = uniqueWords[j].count;
temp2 =uniqueWords[j].word;
uniqueWords[j].count = uniqueWords[j+1].count;
uniqueWords[j].word = uniqueWords[j+1].word;

uniqueWords[j+1].count = temp;
uniqueWords[j+1].word = temp2;

}
}
}
    }
void printTopN(wordItem uniqueWords[], int topN, int totalNumWords)
{
   for (int i=0; i<topN; i++)
   {
     cout << fixed;
     cout << setprecision(4);
       cout << (float)(uniqueWords[i].count-1)/totalNumWords << " - " << uniqueWords[i].word << endl;
   }

}
int getTotalNumberNonStopWords(wordItem uniqueWords[], int length)
{
int count=0;
for (int i=0; i<length; i++)
{
    count=(count+uniqueWords[i].count);
}
    return count;
}
wordItem* doubleArray(wordItem myArray[], int& size)
{
  wordItem* newArray= new wordItem[size*2];

  for (int i =0; i<size; i++)
  {
    newArray[i]=myArray[i];



  }
    delete[] myArray;
  size=size*2;
  return newArray;
}

int main(int argc, char* argv[])
{
  int x=100;
  wordItem *words = new wordItem[x];

  int N=stoi(argv[1]);
string filename=argv[2];
char* ignorefilename=argv[3];
string ignorewords[50];
int doublecounter=0;
getStopWords(ignorefilename, ignorewords);
ifstream file(filename);
int counter=0;
int totalwordcounter=0;
if (file.is_open())
{
 string line;



 while (getline(file, line, ' '))
 {

bool tem=0;
   tem=isStopWord(line, ignorewords);

   if (counter==0)
   {
     words[0].word=line;
     words[0].count=1;
     counter++;

   }
  else if (tem==1)
   {
      tem=129;
   }
  else if (tem==0)
   {
     for (int i=0; i<counter;)
     {
       if (words[i].word == line)
       {
         words[i].count++;
         i=counter;


       }
       else if (words[i].word!=line)
       {
         i++;
         if (i==counter)
         {
           words[i].word=line;
           words[i].count=1;
           counter++;
         }
       }
     }

   }
   if (counter==(x-1))
   {

words=doubleArray(words, x);

doublecounter++;

}

 }

}
else
{
    cout << "Failed to open" << ignorefilename << endl;
}

arraySort(words, counter-1);
totalwordcounter=getTotalNumberNonStopWords(words, counter-1)-(counter)-doublecounter-2;
cout << "Array Doubled: " << doublecounter << endl << "#" << endl;
cout << "Unique non-common words: " << counter-1 << endl << "#" << endl;
cout << "Total non-common words: " << totalwordcounter << endl << "#" << endl;
cout << "Probabilities of top 10 most frequent words" << endl << "----------------------------" << endl;

printTopN(words, N, totalwordcounter);


  return 0;
}
