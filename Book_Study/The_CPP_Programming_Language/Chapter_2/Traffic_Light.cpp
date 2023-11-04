#include "Traffic_Light.h"

Traffic_Light& operator++(Traffic_Light& t)
{
    switch(t){
        case Traffic_Light::Green: return t = Traffic_Light::Yellow;
        case Traffic_Light::Yellow: return t = Traffic_Light::Red;
        case Traffic_Light::Red: return t = Traffic_Light::Green;
    }
}

Traffic_Light& operator--(Traffic_Light& t)
{
    switch(t)
    {
        case Traffic_Light::Green: return t = Traffic_Light::Red;
        case Traffic_Light::Yellow: return t = Traffic_Light::Green;
        case Traffic_Light::Red: return t = Traffic_Light::Yellow;
    }
}

bool operator==(Traffic_Light t, Traffic_Light u)
{
    return static_cast<int>(t) == static_cast<int>(u);
}