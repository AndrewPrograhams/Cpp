#include <list>
#include <algorithm>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>


class vContainer
{
    private:
        std::vector<int> v;
    
    public:
        vContainer(std::vector<int> v);
        std::vector<int> getVector();
};

std::vector<int> vContainer::getVector()
{
    return v;
}

void adjacent_find()
{
    std::vector<int> v = {5,10,15,20,40};
    auto iter = std::adjacent_find(v.begin(),v.end(),[](int a, int b){
        return a*2 == b;
    });

    std::cout << *iter << std::endl;
}

//Task: Create a function that returns all indecies where adjacent elements fulfill a predicate
void all_adjacent(std::vector<int> v)
{
    std::vector<std::vector<int>::iterator> indecies;
    std::vector<int>::iterator current_index = v.begin();
    std::vector<int>::iterator end = v.end(); 
    
    while(true)
    {
        auto iter = std::adjacent_find(current_index,v.end(),[](int a, int b){
            return a*2 == b;
        });

        if(std::distance(v.begin(),iter) != std::distance(v.begin(),v.end()))
        {
            indecies.push_back(iter);
            current_index = std::next(iter);
        }
        else
            break;
    }

    std::string a = "";

    std::for_each(indecies.begin(),indecies.end(), [&a](std::vector<int>::iterator iter){
        a += std::to_string(*iter);
        a += ",";
    });

    std::cout << a.substr(0, a.length() - 1);

}


void all_of()
{
    std::vector<int> v;

    for(int i=1;i<16;i+=2)
        v.push_back(i);
    
    bool allOdd = std::all_of(v.begin(),v.end(),[](int a){
        return a%2 != 0;
    });

    bool allEven = std::all_of(v.begin(),v.end(),[](int a){
        return a%2 == 0;
    });


    if(allOdd)
        std::cout << "All elements of v are ODD." << std::endl;

    if(allEven)
        std::cout << "All elements of v are EVEN." << std::endl;

}

void any_of(){
    std::list<int> l = {1,3,5,7,9,10};

    bool anyOf = std::any_of(l.begin(),l.end(),[](int a){
        return a%2 == 0;
    });

    if(anyOf)
        std::cout << "At least one member of l is EVEN." << std::endl;

}

void backward_copy()
{
    std::vector<int> v1(10);
    std::vector<int> v2(10);

    for(int i=0;i<v1.size();i++)
        v1.at(i) = i;
    

    for(int i=v1.size();i>=0;i--)
        v2[i] = i;

    
}


int main()
{
    //adjacent_find();

    std::vector<int> v = {5,10,15,20,40};
    
    all_adjacent(v);


    // all_of();
    //any_of();

    // std::vector<int> source = {1, 2, 3, 4, 5};
    // std::vector<int> destination = {10, 20, 30, 40, 50};

    // vContainer vc_source = vContainer(source);
    // vContainer vc_dest = vContainer(destination);

    // std::copy_backward(source.begin(), source.end(), destination.end());

    // // Print the destination vector
    // for (int num : destination) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    return 0;

}