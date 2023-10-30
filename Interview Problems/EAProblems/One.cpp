#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <assert.h>

using namespace std;



/*
 * Complete the function below.
 */
bool LaserHitsAsteroid(float laserStart[3], float laserDir[3], float asteroidPos[3], float asteroidRadius )
{
    //Intersection with sphere in 3D space is based on outcome of the determinant in quadratic equation from plugging ray into sphere equation
    //if b >= 0 intersects with sphere


    float sphereX = asteroidPos[0];
    float sphereY = asteroidPos[1];
    float sphereZ = asteroidPos[2];

    float laserX = laserStart[0];
    float laserY = laserStart[1];
    float laserZ = laserStart[2];

    float dirX = laserDir[0];
    float dirY = laserDir[1];
    float dirZ = laserDir[2];

    float radiusSquared = asteroidRadius * asteroidRadius;

    //vectors used in dot products.
    vector<float> normalizedDir = {dirX, dirY, dirZ};
    vector<float> oriCenter = {laserX-sphereX, laserY-sphereY, laserZ - sphereZ};

    
    //quadratic equation terms
    float termOne = std::inner_product(normalizedDir.begin(),normalizedDir.end(),normalizedDir.begin(),0.0f);

    float termTwo = 2.0f * std::inner_product(normalizedDir.begin(),normalizedDir.end(),oriCenter.begin(),0.0f);

    float termThree = std::inner_product(oriCenter.begin(),oriCenter.end(),oriCenter.begin(),0.0f) - radiusSquared;

    float determinant = (termTwo*termTwo) - (4.0*termOne*termThree);

    cout << determinant;

    return determinant >= 0;

}
int main() {

    float start[] = {0.0,0.0,0.0};
    float dir[] = {1.0,1.0,1.0};
    float spherePos[] = {2.0,0.0,0.0};
    float radius = 1.0;

    LaserHitsAsteroid(start,dir,spherePos,radius);

}
