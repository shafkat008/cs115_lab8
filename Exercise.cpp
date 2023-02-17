// Name: Shafkat Alam
// Student Number: 200443237
// Date: 24/10/2021

// Filename: Exercise.cpp
// Purpose: Exercise for inheritance lab

#include <iostream>
#include <math.h> // for sqrt()
using namespace std;

class TwoD
{
  private:
    double x, y; // x and y coordinates
  public: 
    // inline implementation of constructors
    TwoD(){x = y = 0.0; cout << "TwoD default constructor"<< endl;} // default constructor
    TwoD(double i, double j):x(i), y(j){cout << "TwoD constructor with two arguments"<< endl;} 
	
    // inline implementation of member functions
    void setX(double newX){x = newX;}
    void setY(double newY){y = newY;}
    double getX() const {return x;}
    double getY() const {return y;}
    // get distance of 2D points
	  double getDistance(const TwoD& pointTwo) const;
};

// calculate the distance of two 2D points
double TwoD::getDistance(const TwoD& pointTwo) const
{
  double point1[2];
  double point2[2];
  double dx, dy;
  double distance;

  point1[0] = x;
  point1[1] = y;

  point2[0] = pointTwo.getX();
  point2[1] = pointTwo.getY();

  dx = point2[0] - point1[0];
  dy = point2[1] - point1[1];

  distance = sqrt(dx * dx + dy * dy); 
  return distance;
}

class ThreeD:public TwoD
{
  private:
    double z;
  public: 

    // --->ADD CODE HERE<---:
    // Create a default inline constructor that reuses the constructor of
    // the TwoD class.
    // YOUR CODE GOES HERE
    ThreeD():TwoD(){}

    // --->ADD CODE HERE<---:
    // Create an inline constructor that initializes the 3D point
    // and reuses the TwoD class.
    // YOUR CODE GOES HERE
    ThreeD(double i, double j, double k):TwoD(i,j){z=k;}

    void setZ(double newZ){z = newZ;}
    double getZ() const {return z;}

    // get distance for two 3D points
	  double getDistance(const ThreeD& pointTwo) const;
};

// --->ADD CODE HERE<---:
// Overload the definition of getDistance() of TwoD class so that it
// can calculate the distance between two 3D points
double ThreeD::getDistance(const ThreeD& pointTwo) const
{
  // YOUR CODE GOES HERE:
  double point1[3];
  double point2[3];
  double dx, dy, dz;
  double distance;

  point1[0] = getX();
  point1[1] = getY();
  point1[2] = z;

  point2[0] = pointTwo.getX();
  point2[1] = pointTwo.getY();
  point2[2] = pointTwo.getZ();

  dx = point2[0] - point1[0];
  dy = point2[1] - point1[1];
  dz = point2[2] - point1[2];

  distance = sqrt(dx * dx + dy * dy + dz * dz); 
  return distance;
}

// --->ADD CODE HERE<---:
// Implement a main() function.
// You should ask the user for the xyz coordinates of two 3D points,
// and then calculate and print out the distance between these two points.
int main()
{
  // YOUR CODE GOES HERE
  
  //coordinates
  double x1,y1,z1;
  cout << "This program asks for the coordinates of two points in 3D space and calculates their distance." << endl;
  cout << "Please enter the xyz coordinates for the first point: " << endl;
  cin >> x1 >> y1 >> z1;
  
  //first 3d coordinate
  ThreeD t1;
  t1.setX(x1);
  t1.setY(y1);
  t1.setZ(z1);

  cout << "Please enter the xyz coordinates for the second point " << endl;
  cin >> x1 >> y1 >> z1;
  
  //second 3d coordinate
  ThreeD t2(x1,y1,z1);

 


	// you can store the final result in this variable
	double finalDistance = t2.getDistance(t1);

  cout << "Distance is "  << finalDistance << endl;
}
