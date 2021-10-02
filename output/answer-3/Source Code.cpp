#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main()
{
	ifstream file;
	ofstream output_file;
	file.open("../../input/question-3/main.csv");
	vector<vector<string>> v;
	bool flag=0;
	int num=-1;
	while(file.good())
	{
		vector<string> temp(35);
		vector<string> vec;
		vec.push_back(to_string(num));
		for(int i=0;i<34;i++)
		{
			getline(file,temp[i],',');
			if(i==0 || i==30 || i==31) vec.push_back(temp[i]);
		}
		getline(file,temp[34],'\n');
		if(flag)
		{
			v.push_back(vec);
		}
		flag=1;
		num++;
	}
	sort(v.begin(),v.end(),[](vector<string> a,vector<string> b){
		if(stoi(a[3])==stoi(b[3])) return stoi(a[2])>stoi(b[2]);
		return stoi(a[3])>stoi(b[3]);
	});
	output_file.open("main.csv");
	output_file<<" "<<","<<"Team"<<","<<"Yellow Cards"<<","<<"Red Cards"<<endl;
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			output_file<<v[i][j]<<",";
		}
		output_file<<endl;
	}
	return 0;
}