#include "Eigen/Eigen"
#include "Eigen/Geometry"
#include "opencv2/core/eigen.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

// You can use this definition of pi:
constexpr double pi = 3.14159265358979323846;

// You can convert from degrees to radians with this function:
constexpr double deg2rad(const double& deg)
{
  return deg * (pi/180.0);
}


int main()
{
  // 1. Eigen and homogeneous representations.
  //------------------------------------------
  // Todo: Translation.
  Eigen::Vector2d t;
  t << 10, 15; 

  // Todo: Rotation (tip: take a look at https://eigen.tuxfamily.org/dox/group__Geometry__Module.html).
  Eigen::Matrix2d R = Eigen::Rotation2Dd(deg2rad(20)).matrix();

  // Todo: Euclidean transformation that rotates and then translates.
  Eigen::Matrix3d E;
  E << R, t, 
       0, 0, 1; 

  std::cout << "Euclidean transformation E = " << std::endl << E << std::endl << std::endl;

  // Todo: Perform the transformation on a pixel u.
  Eigen::Vector2d u;
  u << 10, 5; 
  Eigen::Vector2d u_transformed = (E * u.homogeneous()).hnormalized();

  std::cout << "Original pixel u = " << std::endl << u << std::endl << std::endl;
  std::cout << "Transformed pixel u_transformed = " << std::endl << u_transformed << std::endl << std::endl;


  // 2. Eigen and OpenCV.
  //---------------------
  cv::Mat E_cv;
  cv::eigen2cv(E, E_cv); 
  // Todo: Convert from Eigen matrix to OpenCV cv::Mat.

  std::cout << "Euclidean transformation E_cv = " << std::endl << E_cv << std::endl << std::endl;


  // 3. Transform images.
  //---------------------
  // Todo: Read the image.
  cv::Mat img_orig = cv::imread("../lab_01_transformations/img_grid.png");
  if (img_orig.empty()) 
  {
    std::cerr << "Could not find image file\n"; 
    return EXIT_FAILURE; 
  }

  // Todo: Display the original image.
  std::string orig_win_title{"Lab 1.2: Original image"}; 
  cv::namedWindow(orig_win_title, cv::WINDOW_NORMAL); 
  cv::imshow(orig_win_title, img_orig); 

  // Todo: Perform transformation on the image.
  cv::Mat img_trans_E; 
  cv::warpPerspective(img_orig, img_trans_E, E_cv, img_orig.size(), cv::INTER_CUBIC); 

  // Todo: Display the transformed image.
  std::string trans_win_title{"Lab 1.2: Transformed image"}; 
  cv::namedWindow(trans_win_title, cv::WINDOW_NORMAL); 
  cv::imshow(trans_win_title, img_trans_E); 


  // 4. Composing transformations.
  //------------------------------
  // Todo: Compose transformations to rotate and scale around the centre of the image.


  // Please press a key, don't close the windows with your mouse.
  while (cv::waitKey(10) != 'q');
  return EXIT_SUCCESS;
}
