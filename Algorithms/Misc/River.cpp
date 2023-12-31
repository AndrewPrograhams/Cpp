#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'calcMissing' function below.
 *
 * The function accepts STRING_ARRAY readings as parameter.
 */

void calcMissing(vector<string> readings) {
    
    for(int i=0;i<readings.size();i++)
    {
        cout << readings[i] << endl;   
    }

}

int main()
{
    string readings_count_temp;
    getline(cin, readings_count_temp);

    int readings_count = stoi(ltrim(rtrim(readings_count_temp)));

    vector<string> readings(readings_count);

    for (int i = 0; i < readings_count; i++) {
        string readings_item;
        getline(cin, readings_item);
        

        readings[i] = readings_item;
    }

    calcMissing(readings);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
