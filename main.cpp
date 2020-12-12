
/******************************************************************************

Bridget Naylor
Date:12/12/2020
Secion: Problem 3 Part C

*******************************************************************************/
#include "node.h"
#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

//functionms needed
//bool Explore()
bool Explore( vector<vector<node*>> &mat, queue<node*> &unexplored, node* &benchWarmer )
{
    cout<<"segExplore1"<<endl;
    node* next = unexplored.front();
    unexplored.pop();
    int x = next->coorX;
    int y = next->coorY;
    bool oneFound = false;
    cout<<"segExplore1 "<<x<<" "<<y<<endl;
    for ( int i = x - 1; i < x + 2; i ++ )
    {
        for ( int j = y - 1; j < y + 2; j ++ )
        {
            cout<<"segExplore1LOOP "<<i<<" "<<j<<endl;
            if ( i >= 0 && i < mat.size() && j >= 0 && i < mat.size() && j < mat[0].size()&&
            !mat[i][j]->explored && mat[i][j]->value == "1" )
            {
                cout<<"segExplore1LOOPFOUND1"<<endl;
                mat[i][j]->explored = true;
                unexplored.push( mat[i][j] );
                oneFound = true;
            }
        }
    }
    return oneFound;
}
// int CalculateNumCircles()
int CalculateNumCircles( vector<vector<node*>> mat )
{
    cout<<"segCalculateNumCircles"<<endl;
    int numCircles = 0;
    node* nextNodeToCheck;
    queue<node*> nodes;
    bool oneFound = false;
    for ( int r = 0; r < mat.size(); r++ )
    {
        for ( int c = 0; c < mat[0].size(); c++ )
        {
            cout<<"segCalculateNumCircles2"<<endl;
            if ( nodes.size() == 0  )
            {
                nodes.push( mat[r][c] );
                cout<<"oneFoundHERE? "<<oneFound<<endl;
                if ( oneFound )
                {
                    numCircles++;
                }
                nextNodeToCheck = mat[r][c];
            }
            if ( nodes.size() != 0 )
            {
                oneFound = Explore( mat, nodes, nextNodeToCheck );
                cout<<"oneFound "<<oneFound<<endl;
            }
        }
    }
    return numCircles;
}

int main()
{
    //code taken from problem 2 of exam
    vector<vector<node*>> vertices(4);

    vector<vector<int>> verticesMap
    {
        { 0, 1, 1, 1 },
        { 0, 0, 1, 0 },
        { 0, 0, 0, 1 },
        { 1, 1, 0, 0 }
    };
    
    // //taken from lab 8
    //makes all values into nodes O(v)
    for ( int r = 0; r < verticesMap.size(); r++ )
    {
        for ( int c = 0; c < verticesMap[0].size(); c++ )
        {
            //cout<<"seg"<<endl;
            string placeHolder = to_string( verticesMap[r][c] );
            //cout<<"seg"<<endl;
            vertices[r].push_back(new node( placeHolder, r, c ));
            //cout<<vertices[r][c]->value<<" ";
        }
        //cout<<endl;
    }
    cout<<"segmain1"<<endl;
    cout<<"Number of glorious circles = "<<CalculateNumCircles( vertices );
    cout<<"segmain2"<<endl;

    return 0;
}
