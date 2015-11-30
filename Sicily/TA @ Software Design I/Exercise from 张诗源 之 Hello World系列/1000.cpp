#include "iostream"
#include "string"
#include "sstream"
#include "vector"
using namespace std;

bool isWA(vector<string> answer, vector<string> input)
{
	if (answer.size() != input.size())
		return true;
	else
	{
		for (int i = 0; i < answer.size(); ++i)
		{
			if (answer[i] != input[i])
				return true;
		}
		return false;
	}
}

bool isPE(vector<string> answer, vector<string> input)
{
	string clip, answerString, inputString;
	for (int i = 0; i < answer.size(); ++i)
	{
		istringstream ansStream(answer[i]);
		while(ansStream >> clip)
			answerString += clip;
	}
	for (int i = 0; i < input.size(); ++i)
	{
		istringstream inpStream(input[i]);
		while(inpStream >> clip)
			inputString += clip;
	}
	if (answerString == inputString)
		return true;
	else
		return false;
}

int main(int argc, char const *argv[])
{
	string read;
	vector<string> answer;
	vector<string> input;
	while(getline(cin, read) && *read.begin() != '#')
		answer.push_back(read);
	while(getline(cin, read) && *read.begin() != '#')
		input.push_back(read);
	if (isWA(answer, input))
	{
		if (isPE(answer, input))
			cout << "Presentation error\n";
		else
			cout << "Wrong answer\n";
	}
	else
		cout << "Accepted\n";
	return 0;
}