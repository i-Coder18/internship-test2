#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main()
{
	ifstream file;
	ofstream output_file;
	file.open("../../input/question-2/main.csv");
	map<string,pair<int,int>> entry;
	bool flag=0;
	while(file.good()) {
		string user_id,age,gender,occupation,zip;
		getline(file,user_id,',');
		getline(file,age,',');
		getline(file,gender,',');
		getline(file,occupation,',');
		getline(file,zip,'\n');
		// cout<<occupation<<" ";
		if(flag)
		{
			if(entry.find(occupation)==entry.end()) entry[occupation]={stoi(age),stoi(age)};
			else {entry[occupation].first=min(stoi(age),entry[occupation].first); entry[occupation].second=max(entry[occupation].second,stoi(age));}
		}
		flag=1;
	}
	output_file.open("main.csv");
	output_file<<" "<<","<<"min"<<","<<"max"<<endl;
	output_file<<"occupation"<<","<<" "<<","<<" "<<endl;
	for(auto it:entry)
		output_file<<it.first<<","<<it.second.first<<","<<it.second.second<<endl;
	return 0;
}