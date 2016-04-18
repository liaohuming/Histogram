#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include<stdlib.h>
using namespace std;

int main(int argc, char *argv[])
{
	vector<int> lifeVector;

	ifstream infile;
	infile.open("DATA-MC-response1.txt");
	if (!infile.is_open())
	{
		return -1;
	}

	string lineStr = "";
	getline(infile, lineStr);
	while (lineStr != "")
	{
		int lifeTemp = 0;
		sscanf(lineStr.c_str(), "%d", &(lifeTemp));
		lifeVector.push_back(lifeTemp);
		getline(infile, lineStr);
	}
	infile.close();

	int lifeBegin = 118782;
	ofstream ofs;
	ofs.open("Histogram.txt", ofstream::out);
	for (int i = 1; i < 112; i++)
	{
		int counter = 0;
		for (int j = 0; j < lifeVector.size(); j++)
		{
			if (lifeBegin + (250 * (i-1))<= lifeVector[j] && lifeVector[j] < lifeBegin + 250 * i)
			{
				counter++;
			}
		}
		cout << counter << endl;
		ofs << counter << endl;
	}
	ofs.close();
	
	cout << "end" << endl;
	//cout << lifeVector.size() << endl;

	system("pause");
	return 0;
}