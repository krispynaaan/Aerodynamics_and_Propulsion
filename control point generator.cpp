#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Make edge cases later for if more than a 2D point is made
// so the code doesn't crash. Same for if a string other than
// 'c' is inputed

void print(list<vector<double> >& listOfVectors)
{
    for (auto vect : listOfVectors) {
        // Each element of the list is
        // a vector itself
        vector<double> currentVector = vect;
  
        cout << "[ ";
  
        // Printing vector contents
        for (auto element : currentVector)
            cout << element << ' ';
  
        cout << ']';
        cout << '\n';
    }
}

int main(){

    cout << "\nEnter a 2-dimensional point in the format 'a b'.\n"
            "Then press enter. Then enter a point that connects to\n"
            "that point. Continue this process until finished. Then\n"
            "enter 'c' and press enter.\n\n"

            "*Note: This code allows the freedom to output any midpoint\n"
            "between any 2 successive points entered; therefore, it does not\n"
            "check that any duplicate points aren't made (duplicate, successive points\n"
            "make a midpoint also at the same point), that the shape is\n"
            "closed, or no edges intersect. It does however only allow the\n"
            "input of 2-dimensional points, and makes a midpoint between the\n"
            "first and last points entered\n\n";

    list<vector<double>> midpoints;
    string input;
    getline(cin,input);
    vector<double> firstPoint;
    vector<double> temp;
    int i = 0;
    while (input.compare("c")){
        stringstream lineStream(input);
        vector<double> point(istream_iterator<double>(lineStream), {});

        if (point.size() == 2){ // format correct
            if (i == 0) { //first iteration e.g. only single point currently made -> midpoint not possible
                i = 1;
                firstPoint = point;
                temp = point;
            }
            else { //all later iterations, make list of midpoints
                double x = (temp.at(0) + point.at(0)) / 2;
                double y = (temp.at(1) + point.at(1)) / 2;
                vector<double> midpoint{x, y};
                midpoints.push_back(midpoint);
                temp = point;
            }
        }
        else { // format wrong
            cout << "\nWrong Format. Input the point again making\n"
                    "sure to input 2 numbers for the 2-D point.\n\n";
        }

        getline(cin,input);

    }

    //make midpoint between final and last point
    double x = (firstPoint.at(0) + temp.at(0)) / 2;
    double y = (firstPoint.at(1) + temp.at(1)) / 2;
    vector<double> midpoint{x, y};
    midpoints.push_back(midpoint);

    print(midpoints);

}