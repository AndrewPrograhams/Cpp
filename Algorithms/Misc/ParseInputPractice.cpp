#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>


std::vector<float> interpolate(float numMissing, float prevValue, float nextValue)
{
    std::vector<float> interpolatedValues;
    double difference = static_cast<double>(nextValue) - static_cast<double>(prevValue);
    double interpolatedVal = static_cast<double>(prevValue);

    for (int i = 1; i <= numMissing; i++)
    {
        interpolatedVal += (difference / (numMissing + 1));
        interpolatedValues.push_back(static_cast<float>(interpolatedVal));
    }

    return interpolatedValues;
}

int main()
{
  std::ifstream inputFile("input000.txt");

  if(!inputFile.is_open())
    std::cerr << "Input file could not be opened" << std::endl;
  
  int numLines;
  std::string line;
  
  inputFile >> numLines;
  std::getline(inputFile, line); //proceed past newline character.

  std::vector<std::string> lines;
  std::vector<std::string> dates;
  std::vector<std::string> floats;

  std::unordered_map<std::string, std::string> map;

  std::string date;
  std::string time;
  std::string fValue;

  while(getline(inputFile,line))
  {
    lines.push_back(line);

    std::istringstream lineStream(line);
    lineStream >> date >> time >> fValue;
    std::cout << line << std::endl;
    // std::cout << "Date is: " << date << std::endl;
    // std::cout << "Value is: " << fValue << std::endl; 

    dates.push_back(date);
    floats.push_back(fValue);

    map[date] = fValue;

  }

  float activeValue;
  std::vector<float> missingValues;

    for(int i=0;i<dates.size(); i++)
    {
        
        if(map[dates[i]].find("Missing") == std::string::npos)
        {
            // std::cout << "Active value is: " << map[dates[i]] << std::endl;
            activeValue = stof(map[dates[i]]);
        }
        else
        {
            int countMissing = 1;
            int iterator = i+1;
            while(iterator<dates.size())
            {
                if(map[dates[iterator]].find("Missing") != std::string::npos)
                    countMissing++;
                else
                    break;
                
                iterator++;
            }

            // std::cout << "      Next value is: " << map[dates[iterator]] << std::endl;
            // std::cout << "      Active value is: " << activeValue << std::endl;
            float nextValue = stof(map[dates[iterator]]);

            std::vector<float> interpolatedValues = interpolate(float(countMissing), activeValue, nextValue);

            missingValues.insert(missingValues.end(),interpolatedValues.begin(),interpolatedValues.end());
            i = iterator;
        }
    }

    // std::sort(missingValues.begin(),missingValues.end(), std::less_equal());

    for(float f: missingValues)
    {
        std::cout << f << std::endl;
    }

    
}