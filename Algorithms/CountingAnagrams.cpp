#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;


vector<string> parseInput(string str)
{
  vector<string> strings;
  size_t startPos = 0;
  size_t endPos = 0;

  while(endPos != string::npos)
  {
    endPos = str.find(' ',startPos);
    string a = str.substr(startPos,endPos-startPos);
    strings.push_back(a);
    startPos = endPos+1;

  }
  return strings;
}

bool isAnagram(string fir, string sec)
{
  sort(fir.begin(),fir.end());
  sort(sec.begin(),sec.end());

  return fir == sec;
}

void updateMap(unordered_map<string,int>& map,const string& str)
{
  
  for_each(map.begin(),map.end(),[str, &map](const pair<string, int>& elem){
    
      string key = elem.first;
      cout << key << endl;
      //if we have a unique key (elminate duplicates)
      if(map.count(str) > 0)
      {
        if(isAnagram(str,key))
        {
          int value = map.at(str) + 1;
          map[str] = value;
        }
      }
      else
      {
        map[str] = 1;
      }
  });

}


string CountingAnagrams(string str) {
  
  // code goes here  
  vector<string> strings = parseInput(str);
  std::unordered_map<string,int> anagramTracker;
  

  for(const auto str: strings)
  {
    cout << "About to update map with string value: " << str << endl;
    updateMap(anagramTracker,str);
  }

  for(const auto& entry: anagramTracker)
  {
    cout << entry.first << " " << entry.second << endl;
  }

  return str;

}

int main(void) { 
   
  
    
}