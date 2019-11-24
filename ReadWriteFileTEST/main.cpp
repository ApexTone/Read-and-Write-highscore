#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
/*
ScorePair.txt
*/
bool sortinrev(const pair<int, string>& a,const pair<int, string>& b) //Sort in descending order consider first element
{
	return (a.first > b.first);
}

int main()
{
	ifstream reader;
	reader.open("ScorePair.txt");
	vector<pair<int, string>> pairVector;
	do//add all value to vector
	{
		string tempString;
		reader >> tempString;
		string name, score;
		name = tempString.substr(0,tempString.find(','));
		score = tempString.substr(tempString.find(',')+1,tempString.length());

		cout << name << "\t" << score << endl;
		pairVector.push_back(make_pair(atoi(score.c_str()),name));//CAN'T STOI?
	} while (reader.good());
	reader.close();

	cout << "--------------------------------------------------------------------" << endl << endl << "From Vector" << endl;

	for (size_t i=0;i<pairVector.size()-1;i++)//print all value
	{
		cout << pairVector[i].second << "\t" << pairVector[i].first << endl;
		//cout << i << endl;
	}


	sort(pairVector.begin(),pairVector.end(),sortinrev);//sort entire vector
	cout << endl<<"------------------------------------After sort--------------------------------" << endl;

	for (size_t i = 0; i < pairVector.size()-1; i++)//print all value
	{
		cout << pairVector[i].second << "\t" << pairVector[i].first << endl;
		//cout << i << endl;
	}

	
	//Insert new score and name
	int inputScore;
	string inputName;
	cout << "Tell score and name: ";
	cin >> inputScore >> inputName;

	pairVector.push_back(make_pair(inputScore,inputName));
	sort(pairVector.begin(),pairVector.end(),sortinrev);


	//Write to file
	ofstream writer;
	writer.open("ScorePair.txt");
	for(size_t i=0;i<5;i++)//only write top 5 score
	{
		writer << pairVector[i].second << "," << pairVector[i].first << "\n";
	}
	writer.close();
	
	cout << "----------------------------------CHANGE INPUT FILE------------------------" << endl << endl;
	pairVector.clear();
	reader.open("ScorePair.txt");
	do//add all value to vector
	{
		string tempString;
		reader >> tempString;
		string name, score;
		name = tempString.substr(0, tempString.find(','));
		score = tempString.substr(tempString.find(',') + 1, tempString.length());
		pairVector.push_back(make_pair(atoi(score.c_str()), name));//CAN'T STOI?
	} while (reader.good());
	reader.close();

	for (size_t i = 0; i < pairVector.size()-1; i++)//print all value
	{
		cout << pairVector[i].second << "\t" << pairVector[i].first << endl;
	}
	
	return 0;
}