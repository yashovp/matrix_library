#ifndef MATRIX_H
#define MATRIX_H

#include "stddef.h"
#include <vector>
#include <iostream>

using namespace std;


template <typename T>
class Matrix{
	private:
		vector< vector<T> > _matrix;
	public:
    Matrix(); // constructors
		int col_size(); // returns col size
		int row_size(); // returns row size
		T get_value(int row, int col); /* returns value defined in the matrix at the positon
		defined at row and col as passed in the function call*/
    void print_matrix(); //printing values from matrix
    void add_row(vector<T>& val); //adding a row to the matrix
		void transpose_matrix(); // transposing the matrix
		void update_matrix(T val, int col ,int row); //updates value of matrix as per the values passed in the function
		void update_row(vector<T> &row_values ,int row_pos); //updates row of matrix as per values passed in the function

};

/*
Function Definition: Constructs the matrix
INPUT:none
OUTPUT:none
*/
template <typename T>
Matrix<T>::Matrix(){
  vector <vector<T> > dec_matrix;
	_matrix = dec_matrix;

}

/*
Function Definition: Returns the number of elements in a row of the matrix
INPUT:none
OUTPUT:number of elements in a row of the matrix
*/
template <typename T>
int Matrix<T>::row_size(){
		return _matrix.size();
	};

/*
Function Definition: Returns the number of elements in a column of the matrix
INPUT:none
OUTPUT: number of elements in a column of the matrix
*/
template <typename T>
int Matrix<T>::col_size(){
			return _matrix[0].size();
	};

/*
Function Definition: Returns the value in matrix as row and column specifed by function
INPUT:none
OUTPUT: value in matrix at row and column specifed by client
*/
template <typename T>
T Matrix<T>::get_value(int row, int col){
	return _matrix[row][col];
};

/*
Function Definition: Function takes in a vector and adds it to the first available column
of the matrix
INPUT: vector of values
OUTPUT: none
*/
template <typename T>
 void Matrix<T>::add_row(vector<T>& row){
  _matrix.push_back(row);
}

/*
Function Definiton: Prints all the values in all the rows of the matrix, starting from the top.
INPUT:operates on the matrix that the function is called on.
OUTPUT:void function, prints values to console
*/
template <typename T>
void Matrix<T>::print_matrix(){
  for(int col = 0; col < _matrix.size();col++){
    for(int row = 0; row < _matrix[0].size();row++){
      cout<<_matrix[col][row]<<"\t";
    }
    cout<<"\n";
  }
}

/*
Function Definition:Transposes the matrix passed.
INPUT:operates on the matrix that the function is called on.
OUTPUT: none, the matrix is now transposed.
*/
template <typename T>
void Matrix<T>::transpose_matrix(){
vector< vector<T> > transposed_matrix;
vector <T> holder;
for(int row = 0; row<_matrix[0].size();row++){
  for(int col = 0; col<_matrix.size();col++){
    holder.push_back(_matrix[col][row]);
  }
  transposed_matrix.push_back(holder);
  holder.clear();
}
_matrix = transposed_matrix;
}

/*
Function Definition: Update any value defined in the matrix
INPUT:operates on the matrix that the function is called on.
OUTPUT: none, the matrix is now updated
*/
template <typename T>
void Matrix<T>::update_matrix(T val,int col ,int row){
_matrix[col][row] = val;
}

/*
Function Definition:Transposes the matrix passed.
INPUT:operates on the matrix that the function is called on.
OUTPUT: none, the matrix's row specified in the function is now updated.
*/
template <typename T>
void Matrix<T>::update_row(vector<T>& row_values,int row_pos){
_matrix[row_pos]= row_values;
}

//Non member function:

/*
The function multiply_matrix() function is declared as a non memeber function to allow our client
to get a new matrix when the function is called and allow for dynamic use by client in the future.
*/

/*
Function Definition:The function takes two matricies and multiplies them. The function first accepts
the 1st matrix,the row size and the column size. then the second matrix, the row size and the col size of that matrix.
A new matrix is intentionally returned to allow for the client to have control over the way they may want
to implement the function while using it in the .cpp file.
INPUT: two matricies and their row and column sizes.
OUTPUT: multiplied matrix
*/
template<typename T>
Matrix<T> multiply_matrix(Matrix<T>& first_matrix,int row_first_matrix,int col_first_matrix, Matrix<T>& second_matrix, int row_second_matrix, int col_second_matrix){
/*
Incase the client has passed two matricies that cannot be mathematicaly calculated,
we return a message to the output console.
*/
	if(row_first_matrix != col_second_matrix){
		cout<<"Incompatiple matrix sizes,\nPlease select a first matrix who's row size is equal to the column size of the second matrix"<<endl;
		cout<<"Returning first matrix as default"<<endl;
		return first_matrix;
	}
	else{
		Matrix<T> output_matrix;
// create a vector of appropriate row size
		vector<T> data_holder(row_first_matrix);
		int counter = 0 ;
//add appropriate number of rows to our matrix
		while(counter < col_second_matrix){
			output_matrix.add_row(data_holder);
			counter++;
		}

/*
let new_value be of type T so that it be adjusted as per the variable type picked by the client,
we subtrat a value form itself to set that as the multiplied value in order to let new_value
be of variable type passed in my client, since the subtract will give us either an appropriate variable type of zero
(floating point,double, integer)
*/
T new_value = first_matrix.get_value(0,0) - first_matrix.get_value(0,0);
//algorithm to calculate matrix multiplication
/*
for every postion of the output_matrix, we iterate through the appropriate combination of numbers in the passed matricies
to calculate the new_value of each value in the output_matrix
*/
		for(int _row = 0;_row<row_first_matrix;_row++){
			for(int _col = 0;_col<col_second_matrix;_col++){
					for(int _iterator = 0; _iterator < col_first_matrix;_iterator++){
						//set multiplied_value to the number we get after multiplying the appropriate positions in the given matrix
						new_value = first_matrix.get_value(_row,_iterator)*second_matrix.get_value(_iterator,_col);
						//update the matrix value accordingly
						output_matrix.update_matrix(output_matrix.get_value(_row,_col) + new_value, _row,_col);
						//reset the multiplied_value
						new_value = first_matrix.get_value(0,0) - first_matrix.get_value(0,0);
					}
			}
		}
	return output_matrix;
}
}

#endif
