#include "matrix.h"
#include <iostream>
/*
Author : Yash Pandey
Date: 02/27/2020
The following file tests the Matrix libary.

Please run the following lines in a c++ IDE
Enter the following line into the terminal: g++ -std=c++11 main.cpp matrix.h
After which we can run the output file.
*/

int main(){
  //declaring fist matrix
  Matrix<float> _matrix1;
  Matrix<float> _matrix2;
  //delaring vectors to push values into and then add them as rows for our matrix
  vector<float> test;
  vector<float> test1;
  vector<float> test2;

  test.push_back(5.3);
  test.push_back(4.1);

  test1.push_back(0.9);
  test1.push_back(1.8);

  test2.push_back(1.1);
  test2.push_back(2.4);

  _matrix1.add_row(test);
  _matrix1.add_row(test1);
  _matrix1.add_row(test2);

//Testing the transpose function
  cout<<"\nTesting Transpose Function"<<endl;
  cout<<"Matrix_01 before transpose() function is called\n"<<endl;

  _matrix1.print_matrix();
/*
before we transpose our _matrix1, we save our_matrix1 in a new _matrix2
so that we can test our multiply_matrix  function in the future
 */
 _matrix2 = _matrix1;
  _matrix2.transpose_matrix();
  cout<<"\n";

  cout<<"Matrix_01 after transpose() function is called\n"<<endl;
  _matrix2.print_matrix();
  cout<<"\n";


// The multiply_matrix() function is tested below, the function has returned a new matrix.
cout<<"Testing our multiply_matrix() function by multiplying \nthe Matrix_01 and transpose of Matrix_01\n"<<endl;
Matrix<float> _matrix3;
_matrix3 = multiply_matrix(_matrix1,_matrix1.row_size(),_matrix1.col_size(),_matrix2,_matrix2.row_size(),_matrix2.col_size());
_matrix3.print_matrix();
cout<<"\n";

/*
Since the Matirx library was made using a template class, we should be able to declare our matrix
with any type of variable, here we try it with a string
*/
  Matrix<string> _matrix4_strings;
  vector<string> test3;
  test3.push_back("a");
  test3.push_back("b");
  test3.push_back("c");
  test3.push_back("d");
  _matrix4_strings.add_row(test3);

  vector<string> test4;
  test4.push_back("w");
  test4.push_back("x");
  test4.push_back("y");
  test4.push_back("z");
  _matrix4_strings.add_row(test4);
  _matrix4_strings.add_row(test3);

// after addding three rows with four values each, we get an 3X4 matrix, we output it to console to check
cout<<"Testing if our matrix libary works for different variable types:\nMatrix_02"<<endl;
  _matrix4_strings.print_matrix();
  cout<<"\n";


cout<<"Testing transpose() function on Matrix_02\n"<<endl;
  _matrix4_strings.transpose_matrix();
  _matrix4_strings.print_matrix();
  cout<<"\n";


// in order for the client to be able to update values in the matrix, the below update_matrix() function was created
cout<<"Testing update_matrix() function on the first value in the first row of Matrix_02\nby updating this value to 'Q' \n"<<endl;

  _matrix4_strings.update_matrix("Q",0,0);
  _matrix4_strings.print_matrix();
  cout<<"\n";


// if the client wants to update a whole row of the matrix instead of using the update_value() function repeatedly, they can use the update_row() function
  test3.pop_back();
  _matrix4_strings.update_row(test3,3);
  cout<<"Testing the update_row() function on the 4th row on Matrix_02 by\nupdating the row to 'a\tb  c'\n"<<endl;
  _matrix4_strings.print_matrix();
  cout<<"\n";

  return 0;
}
