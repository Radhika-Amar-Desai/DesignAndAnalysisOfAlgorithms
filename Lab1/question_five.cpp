/*
    Question Five : 
    Given n points P1, P2, ..., Pn with the coordinates (x1, y1),(x2, y2), ...,(xn, yn)
    respectively, write an insertion-sort based algorithm and the
    corresponding code to arrange the points in an increasing order of the distance of the point from the origin (with (0, 0) as
    the coordinates. Distance between any two points (a1, b1) and
    (a2, b2) is p
    (a1 − a2)
    2 + (b1 − b2)
    2
    . Input for the code is : n
    and the coordinates of the n points entered with x−coordinate
    first and then the y−coordinate.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Point{
    public:
        int x;
        int y;
        double distance;

        double calculateDistance(){
            distance = sqrt(x * x + y * y);
            return distance;
        }

        void setX(int x_val){
            x = x_val;
        }

        void setY(int y_val){
            y = y_val;
        }

};

void insertionSort(Point points[], int n) {
    for (int j = 1; j < n; j++){
        Point key = points[j];
        int i = j - 1;
        while (i >= 0 and points[i].distance > key.distance){
            points[i + 1] = points[i];
            i = i - 1;
        } 
        points[i + 1] = key;
    }
}

void printArray(Point points[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << points[i].x << " " << points[i].y << " "; 
    }
    cout << endl;
}

int main() {
    Point points[100];
    int n;

    cout << "Enter the number of points : ";
    cin >> n;

    int x;
    int y;

    for(int i = 0; i < n; i++){
        cout << "Enter point x co-ordinate : ";
        cin >> x;

        cout << "Enter point y co-ordinate : ";
        cin >> y;

        points[i].setX(x); points[i].setY(y); points[i].calculateDistance();
    } 

    insertionSort(points, n);
    printArray(points, n);
}
