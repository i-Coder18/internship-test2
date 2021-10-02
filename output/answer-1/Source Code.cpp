#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main()
{
    ifstream file;
    ofstream output_file;
    file.open("../../input/question-1/main.csv");
    vector<vector<string>> v;
    while(file.good()) {
        string Year,Population,Total,Violent,Property,Murder,Forcible_Rape,Robbery,Aggravated_assault,Burglary,Larceny_Theft,Vehicle_Theft;
        vector<string> temp;
        getline(file,Year,',');
        getline(file,Population,',');
        getline(file,Total,',');
        getline(file,Violent,',');
        getline(file,Property,',');
        getline(file,Murder,',');
        getline(file,Forcible_Rape,',');
        getline(file,Robbery,',');
        getline(file,Aggravated_assault,',');
        getline(file,Burglary,',');
        getline(file,Larceny_Theft,',');
        getline(file,Vehicle_Theft,'\n');
        temp.push_back(Year);
        temp.push_back(Population);
        temp.push_back(Total);
        temp.push_back(Violent);
        temp.push_back(Property);
        temp.push_back(Murder);
        temp.push_back(Forcible_Rape);
        temp.push_back(Robbery);
        temp.push_back(Aggravated_assault);
        temp.push_back(Burglary);
        temp.push_back(Larceny_Theft);
        temp.push_back(Vehicle_Theft);
        v.push_back(temp);
    }
    vector<long long> data(12,0);
    vector<vector<long long>> result;
    int num=0;
    output_file.open("main.csv");
    for(int i=0;i<v.size();i++)
    {
         if(i==0) { 
            for(int j=0;j<v[i].size();j++)
            {
                if(j==2) continue;
                if(j==0) {output_file<<" "<<","; continue;}
                output_file<<v[i][j]<<",";
            }
            output_file<<endl;
            continue;}
        for(int j=0;j<v[i].size();j++)
        {
            if(num==0) {data[0]=stoll(v[i][0]);}
            if(j==0 || j==1) continue;

            data[j]+=stoll(v[i][j]);
        }
        if(num==9 || (i+1==(int)v.size())) {data[1]=stoll(v[i][1]); result.push_back(data); for(int k=0;k<12;k++) data[k]=0; num=-1; }
        num++;
    }

    for(int i=0;result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            if(j==2) continue;
            output_file<<result[i][j]<<",";
            // cout<<result[i][j]<<" ";
        }
        // cout<<endl;
        output_file<<endl;
    }
    return 0;
}