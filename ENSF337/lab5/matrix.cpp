//   matrix.cpp


#include "matrix.h"

Matrix::Matrix(int r, int c):rowsM(r), colsM(c)
{
    matrixM = new double* [rowsM];
    assert(matrixM != NULL);
    
    for(int i=0; i < rowsM; i++){
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }
    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);
    
    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);
}


Matrix::~Matrix()
{
    destroy();
}

Matrix::Matrix(const Matrix& source)
{
    copy(source);
}

Matrix& Matrix::operator= (const Matrix& rhs)
{
    if(&rhs != this){
        destroy();
        copy(rhs);
    }
   
    return *this;
}

double Matrix::get_sum_col(int i) const
{
    assert(i >= 0 && i < colsM);
    return sum_colsM[i];
}

double Matrix::get_sum_row(int i) const
{
    assert(i >= 0 && i < rowsM);
    return sum_rowsM[i];
}


void Matrix::sum_of_rows()const
{
   
    // COMMENT OUT THE FOLLOWING LINE AND COMPLETE THE DEFINITION OF THIS FUNCTION
    //cout << "\nSorry I don't know how to calculate sum of rowsM in a matrix. ";

	for(int i = 0; i < rowsM; i++){
		sum_rowsM[i] = 0;
		for(int j = 0; j < colsM; j++){
			sum_rowsM[i] += matrixM[i][j];
		}
	}

}

void Matrix::sum_of_cols()const
{
    // COMMENT OUT THE FOLLOWING LINE AND COMPLETE THE DEFINITION OF THIS FUNCTION
    //cout << "\nSorry I don't know how to calculate sum of columns in a matrix. ";
    
	for(int i = 0; i < colsM; i++){
		sum_colsM[i] = 0;
		for(int j = 0; j < rowsM; j++){
			sum_colsM[i] += matrixM[j][i];
		}
	}
}

void Matrix::copy(const Matrix& source)
{
    // THIS FUNCITON IS DEFECTIVE AND DOSEN'T PROPERLY MAKE THE COPY OF SROUCE
    if(source.matrixM == NULL){
        matrixM = NULL;
        sum_rowsM = NULL;
        sum_colsM = NULL;
        rowsM = 0;
        colsM = 0;
        return;
    }
    
    rowsM = source.rowsM;
    colsM = source.colsM;
    
    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);
    
    
    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);
    
    matrixM = new double*[rowsM];
    assert(matrixM !=NULL);
    for(int i =0; i < rowsM; i++){
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }
    // STUDENTS MUST COMMENT OUT THE FOLLOWING LINE AND FIX THE FUNCTION'S PROBLEM
    //cout << "\nSorry copy fucntion is defective. ";
	
	//copy matrix
	for(int i = 0; i < rowsM; i++){
		for(int j = 0; j < colsM; j++){
			matrixM[i][j] = source.matrixM[i][j];
		}
	}

	//copy sum rows
	for(int i = 0; i < rowsM; i++){
		sum_rowsM[i] = source.sum_rowsM[i];
	}
	
	//copy sum columns
	for(int i = 0; i < colsM; i++){
		sum_colsM[i] = source.sum_colsM[i];
	}
	
}

    

void Matrix::destroy()
{
    // COMMENT OUT THE FOLLOWING LINE AND COMPLETE THE DEFINITION OF THIS FUNCTION
    //cout << "\nProgram ended without destroying matrices.\n";
	
	delete sum_rowsM;
	delete sum_colsM;
	
	for(int i = 0; i < rowsM; i++){
		delete matrixM[i];
	}
	
	delete matrixM;
	
	
}
