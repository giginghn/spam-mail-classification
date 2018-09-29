/*
Nguyen, Giang
March 12th, 2018
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void percentInMail(string nameOfFile, const string& word, double&
	numOfWord, double& count)
{
	ifstream myfile;
	string temp;
	myfile.open(nameOfFile);
	if (!myfile)
	{
		cout << "Unable to open file";
		exit(1);
	}
	while (myfile >> temp)
	{
		if (temp[temp.size() - 1] == '.' || temp[temp.size() - 1]
			== '!' || temp[temp.size() - 1] == '?' || temp[temp.size() - 1] == ';' ||
			temp[temp.size() - 1] == ':' || temp[temp.size() - 1] == ',' ||
			temp[temp.size() - 1] == '\\' || temp[temp.size() - 1] == '|' ||
			temp[temp.size() - 1] == '/')
			temp = temp.substr(0, temp.size() - 1);
		if (temp == word)
			numOfWord++;
		++count;
	}
	myfile.close();
}
void percentinSpam(string nameOfFile, const string& word, double&
	numOfWord, double& count)
{
	ifstream myfile;
	string temp;
	myfile.open(nameOfFile);
	if (!myfile)
	{
		cout << "Unable to open file";
		exit(1);
	}
	while (myfile >> temp)
	{
		if (temp[temp.size() - 1] == '.' || temp[temp.size() - 1]
			== '!' || temp[temp.size() - 1] == '?' || temp[temp.size() - 1] == ';' ||
			temp[temp.size() - 1] == ':' || temp[temp.size() - 1] == ',' ||
			temp[temp.size() - 1] == '\\' || temp[temp.size() - 1] == '|' ||
			temp[temp.size() - 1] == '/')
			temp = temp.substr(0, temp.size() - 1);
		if (temp == word)
			numOfWord++;
		++count;
	}
	myfile.close();
}
int main()
{
	const double PS = 0.25;
	string word;
	double count = 1;
	double numOfWord = 1;
	cout << "This example uses the files from smallTestFiles" << endl;
	cout << "-------------------" << endl;
	cout << "Email Anti Spam Software" << endl;
	cout << "--------------------" << endl;
	cout << "This software helps customer to filter which of your
		incoming email are spam and which are not." << endl;
		cout << "----------------" << endl;
	cout << endl;
	cout << "Which word is contained in the mystery email? ";
	cin >> word;
	cout << endl;
	percentInMail("email1.txt", word, numOfWord, count);
	percentInMail("email2.txt", word, numOfWord, count);
	percentInMail("email3.txt", word, numOfWord, count);
	percentInMail("email4.txt", word, numOfWord, count);
	percentInMail("email5.txt", word, numOfWord, count);
	double PCNOTS = static_cast<double>(numOfWord / count);
	double spamCount = 1;
	double numOfWordSpam = 1;
	percentinSpam("spam1.txt", word, numOfWordSpam, spamCount);
	percentinSpam("spam2.txt", word, numOfWordSpam, spamCount);
	percentinSpam("spam3.txt", word, numOfWordSpam, spamCount);
	percentinSpam("spam4.txt", word, numOfWordSpam, spamCount);
	percentinSpam("spam5.txt", word, numOfWordSpam, spamCount);