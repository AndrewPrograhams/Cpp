#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <unordered_map>

//A function to get interpolations that will fill out the missingValues vector.
std::vector<float> getInterpolations(int numMissing, float initialValue, float endValue, std::vector<float>& differences)
{
    std::vector<float> interpolationValues;

    bool swap = false;
    float temp;
    //Adjust values to account for lerping down
    if(initialValue > endValue)
    {
        temp = initialValue;
        initialValue = endValue;
        endValue = temp;
        swap = true;
    }

    float difference = endValue - initialValue;
    differences.push_back(difference);
    float interpolation = initialValue;

    for(int i=1; i<=numMissing;i++)
    {
        interpolation += (difference/(static_cast<float>(i)+1.0f));

        //std::cout << "      Adding interpolation value: " << interpolation << std::endl;
        interpolationValues.push_back(interpolation);
    }
    
    return interpolationValues;

}

int main()
{
    std::vector<float> differences;
    std::ifstream inputFile("input000.txt");

    //check file was found.
    if(!inputFile.is_open())
        std::cout << "Failed to open file. " << std::endl;
    

    //initialize structures to store data.
    int numLines;
    std::vector<std::string> dates;
    std::vector<std::string> fStrings;
    std::unordered_map<std::string,std::string> map;

    //Variables to store parsed data from sstream
    std::string line;
    std::string date;
    std::string time;
    std::string fString;

    inputFile >> numLines;
    std::getline(inputFile, line);

    //filling data structures with file data
    while(std::getline(inputFile,line))
    {
        std::istringstream streamLine(line);
        streamLine >> date >> time >> fString;

        fStrings.push_back(fString);
        dates.push_back(date);
        map[date] = fString;
    }

    float currentValue;
    std::vector<float> missingValues;

    //Iterate through each line to perform operations to ascertain missing data points. 
    for(int i=0; i<dates.size();i++)
    {

        std::string currentfString = map[dates[i]];
        
        //check if we hit a line without missing data
        if(!(currentfString.find("Missing") != std::string::npos))
        {
            //std::cout << "Current fString: " << currentfString << std::endl;
            currentValue = stof(currentfString);
        }
        else
        {
            //std::cout << "  Found missing value(s)" << std::endl;

            int iter = i+1;
            int numMissing = 1;
            currentfString = map[dates[iter]];
            while(currentfString.find("Missing") != std::string::npos)
            {
                iter++;
                numMissing++;
                currentfString = map[dates[iter]];
            }
            
            //get begin and endVal to use in getInterpolations method
            //std::cout << "      Current f string :" << currentfString << std::endl;
            float fEndVal = stof(currentfString);
            std::vector<float> interpolations = getInterpolations(numMissing,currentValue,fEndVal, differences);
            missingValues.insert(missingValues.end(),interpolations.begin(),interpolations.end());

            i = iter;
        }
    }
    
    for(int i =0; i <missingValues.size();i++)
    {
        std::cout << missingValues[i] << std::endl;
    }

}