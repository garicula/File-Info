// Garrick Morley
// CPSC 200 Project 4
// This program manipulates scores from a file

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <fstream>
#include <cassert>
using namespace std;

/*/////////////////////////////////////////////////////////////////////////////////
//																				 //
NOTE: I couldn't get it to work without having a score counter in each function, //
I know it's not the right way but it's as close as I can get. If I don't have    //
it the count stays at 0, even if I do the counting in main. 			 		 //
//																				 //
*//////////////////////////////////////////////////////////////////////////////////


//create class
class ScoreList
{
      public:
      		 ScoreList()
      		 {
      		 	count = 0;
			 }
             void addScore(double add);
             double avgScore();
             double stdDevScore();
             double maxScore();
             int scoreCount();
             
      private:
      		  int list[1000];
              int count;
};

//set up functions

//add the given score to the list of scores
void ScoreList::addScore(double add)
{
	//this part counts the scores
	int i = 0;
	int score;
	
	ifstream input;
	input.open("scores");
	
    while (input >> score)
    {
		list[i] = score;
		i++;
		count++;
	} 
	
	//this part adds the number to the list
	list[count] = add;
}

//returns the average of all the scores in the list
double ScoreList::avgScore()
{
	//first part finds the count
	int i = 0;
	int score;
	int total = 0;
	double avg;
	
	ifstream input;
	input.open("scores");
	
    while (input >> score)
    {
		list[i] = score;
		i++;
		count++;
	} 
	
	//this part finds and returns the average
	for(int i = 0; i < count ; i++)
	{
		total += list[i];
	}
	
	return total / count;
	
}

//returns the standard deviation of all the scores in the list
double ScoreList::stdDevScore()
{
	int i = 0;
	int meanTotal = 0;
	int meanCount = 0;
	double mean = 0;
	double score = 0;
	int total = 0;
	double inside = 0;
	double insideAccumulator = 0;
	double deviation = 0;
	
	//open the file
	ifstream input;
	input.open("scores");
	
	//1st pass through the file (for the mean)
	while (input >> score)
	{
		meanTotal += score;	
		meanCount++;
	}
	
	//close file
	input.close();
	
	mean = meanTotal / meanCount;
	
	ifstream input1;
	input1.open("scores");
	
	//pass through file again
	while (input1 >> score)
	{
		inside = (score - mean) * (score - mean);
		insideAccumulator += inside;	
	}
	
	//calculate standard deviation
	deviation = sqrt(insideAccumulator / meanCount);
	return deviation;
}

//returns the highest score in the list
double ScoreList::maxScore()
{
	//first part gets the count
	int i = 0;
	int score;
	int max;
	
	ifstream input;
	input.open("scores");
	
    while (input >> score)
    {
		list[i] = score;
		i++;
		count++;
	}
	
	//this finds and returns the max 
	for(int i = 0; i < count ; i++)
	{
	  	int max = list[0];
        for (i = 1; i < count; i++) 
        if (list[i] > max) 
            max = list[i];
            return max;
	}
}

//returns the number of scores in the list
int ScoreList::scoreCount()
{
	int i = 0;
	int score;
	ifstream input;
	input.open("scores");
	
    while (input >> score)
    {
		list[i] = score;
		i++;
		count++;
	}
	return count;
	
}

main()
{	
	//test the functions
    ScoreList list1, list2, list3, list4, list5;
    cout << "Max score = " << list1.maxScore() << endl;
      
    cout << "Score count = " << list2.scoreCount() << endl;
      
    cout << "Average score = " << list3.avgScore() << endl;
      
    cout << "Standard Deviation = " << list4.stdDevScore() << endl;
    
    list5.addScore(6);
	
}





