#include "Eigen/Eigen"
#include <iostream>

int main()
{
  // 1. Test the Getting Started code here:
  //---------------------------------------


  // 2. Solve the tutorial problems here:
  // a) Create a few vectors and matrices.
  //--------------------------------------
  // Todo: Create vector t.
  Eigen::Vector3d t;
  t << 1, 0, 3; 

  // Todo: Create matrix A.
  Eigen::Matrix3d A;
  A << 1, 0, 3, 
       4, 5, 6, 
       7, 8, 9; 

  // Todo: Create identity matrix I.
  Eigen::Matrix3d I;
  I = Eigen::Matrix3d::Identity();

  // Todo: Create matrix T.
  Eigen::Matrix4d T;
  T << A, t, 
      0, 0, 0, 1; 

  // Todo: Create matrix B.
  Eigen::Matrix3d B;
  B = A.transpose(); 

  // Print the results (uncomment code below).
 std::cout << "a) Create a few vectors and matrices:" << std::endl;
 std::cout << "-------------------------------------" << std::endl;
 std::cout << "t = " << std::endl << t << std::endl << std::endl;
 std::cout << "A = " << std::endl << A << std::endl << std::endl;
 std::cout << "I = " << std::endl << I << std::endl << std::endl;
 std::cout << "T = " << std::endl << T << std::endl << std::endl;
 std::cout << "B = " << std::endl << B << std::endl << std::endl;


  // b) Coefficients.
  //-----------------
  // Todo: Follow lab notes.
  std::cout << "Subtask b), changing coefficients\n"; 
  std::cout << "t = " << std::endl << t << std::endl << std::endl;
  std::cout << "A = " << std::endl << A << std::endl << std::endl; 

  t(1) = 2; 
  A(0, 1) = 2; 
  std::cout << "t_2 = 2, a_1,2 = 2\n"; 
  std::cout << "t = " << std::endl << t << std::endl << std::endl;
  std::cout << "A = " << std::endl << A << std::endl << std::endl; 
  std::cout << "T = [A, t ; 0, 1]\n"; 
  T.block(0, 0, 3, 3) = A; 
  T.block(0, 3, 3, 1) = t;
  std::cout << "T = " << std::endl << T << std::endl << std::endl;

  // c) Block operations.
  //---------------------
  // Todo: Follow lab notes.
  Eigen::Vector3d r_2 = A.row(1);  

  Eigen::Vector3d c_2 = A.col(1); 

  Eigen::Matrix<double, 3, 4> T_3x4 = T.block(0, 0, 3, 4); 

  A.row(1).setConstant(0); 
  A.col(1).setConstant(0); 
  T.block(0, 0, 3, 4).setConstant(0); 

  std::cout << "Subtask c), subvectors and submatrices\n"; 
  std::cout << "A row 2 = " << std::endl << r_2 << std::endl << std::endl;
  std::cout << "A col 2 = " << std::endl << c_2 << std::endl << std::endl;
  std::cout << "A_3x4 = " << std::endl << T_3x4 << std::endl << std::endl;
  std::cout << "Zeroing out these in the original...\n"; 
  std::cout << "A = " << std::endl << A << std::endl << std::endl;
  std::cout << "T = " << std::endl << T << std::endl << std::endl;  

  // d) Matrix and vector arithmetic.
  //---------------------------------
  // Todo: Follow lab notes.
  std::cout << "Subtask d) Matrix and vector arithmetic\n"; 
  std::cout << "Summing " << r_2.transpose() << " and " << c_2.transpose() << '\n'; 
  std::cout << r_2 + c_2 << '\n'; 

  std::cout << "Summing \n" << A << "\nand\n" << B << '\n'; 
  std::cout << A + B << '\n'; 

  std::cout << "Multiplying \n" << A << "\nand\n" << B << '\n';   
  std::cout << A * B << '\n'; 

  std::cout << "Dot product between " << r_2.transpose() << " and " << c_2.transpose() << '\n'; 
  std::cout << r_2.dot(c_2) << '\n'; 

  std::cout << "Coefficient-wisely multiplying \n" << A << "\nand\n" << B << '\n';   
  std::cout << A.array() * B.array() << '\n'; 

  // e) Reductions.
  //---------------
  // Todo: Follow lab notes.
  std::cout << "Subtask d) Reductions\n"; 

  A(2, 2) = -A(2, 2); 
  std::cout << "Sum of elements in \n" << A << "\n = " << A.sum() << '\n'; 

  std::cout << "Minimum value and its position in \n" << A << '\n'; 
  int row, col; 
  double value = A.minCoeff(&row, &col); 
  std::cout << "Value = " << value << " at row " << row << " and col " << col << '\n'; 

  Eigen::Vector3d colMaxVector = A.colwise().maxCoeff(); 
  std::cout << "Max coefficient vector of columns of A = " << colMaxVector << '\n'; 

  std::cout << "L2-norm of " << colMaxVector << " is " << colMaxVector.squaredNorm() << '\n';   

  Eigen::Vector3i boolVector = (colMaxVector.array() > 2).matrix().cast<int>(); 
  std::cout << "Number of elements in " << colMaxVector.transpose() << " greater than 2 is " << boolVector.sum() << '\n'; 
}
