
#include "circle.hpp"
#include "rectangle.hpp"

 
void Circle::draw(Window const& window) const{
    Point2d start_point{mid_.x() + radius_, mid_.y()};
    Point2d end_point{start_point};
  
       

    for (int j = 1; j<201; ++j){
        double bow = 0.01;
        end_point.rotate(mid_, bow*M_PI);
        window.drawLine(start_point.x(), start_point.y(), end_point.x(), end_point.y(),color_.r,color_.g,color_.b);
        start_point.rotate(mid_, bow*M_PI);
    }

 
}
void Circle::draw(Window const& window, ColorRGB color) const{
    Point2d start_point{mid_.x() + radius_, mid_.y()};
    Point2d end_point{start_point};
  
       

    for (int j = 1; j<201; ++j){
        double bow = 0.01;
        end_point.rotate(mid_, bow*M_PI);
        window.drawLine(start_point.x(), start_point.y(), end_point.x(), end_point.y(),color.r,color.g,color.b);
        start_point.rotate(mid_, bow*M_PI);
    }
}

 void Rectangle::draw(Window const& window) const{
    Point2d c0{left_bottom_corner_.x(), left_bottom_corner_.y()};
    Point2d c1{left_bottom_corner_.x() + sidelength_a, left_bottom_corner_.y()};
    Point2d c2{c1.x(), c1.y() + sidelength_b};
    Point2d c3{left_bottom_corner_.x(), left_bottom_corner_.y() + sidelength_b};
    c0.rotate(left_bottom_corner_,angle_);
    c1.rotate(left_bottom_corner_,angle_);
    c2.rotate(left_bottom_corner_,angle_);
    c3.rotate(left_bottom_corner_,angle_);
    

    window.drawLine(c0.x(), c0.y(), c1.x(), c1.y(),color_.r,color_.g,color_.b);
    window.drawLine(c1.x(), c1.y(), c2.x(), c2.y(),color_.r,color_.g,color_.b);
    window.drawLine(c2.x(), c2.y(), c3.x(), c3.y(),color_.r,color_.g,color_.b);
    window.drawLine(c3.x(), c3.y(),c0.x(), c0.y(),color_.r,color_.g,color_.b);


 }

  void Rectangle::draw(Window const& window, ColorRGB color) const{
    Point2d c0{left_bottom_corner_.x(), left_bottom_corner_.y()};
    Point2d c1{left_bottom_corner_.x() + sidelength_a, left_bottom_corner_.y()};
    Point2d c2{c1.x(), c1.y() + sidelength_b};
    Point2d c3{left_bottom_corner_.x(), left_bottom_corner_.y() + sidelength_b};
    c0.rotate(left_bottom_corner_,angle_);
    c1.rotate(left_bottom_corner_,angle_);
    c2.rotate(left_bottom_corner_,angle_);
    c3.rotate(left_bottom_corner_,angle_);
    

    window.drawLine(c0.x(), c0.y(), c1.x(), c1.y(),color.r,color.g,color.b);
    window.drawLine(c1.x(), c1.y(), c2.x(), c2.y(),color.r,color_.g,color.b);
    window.drawLine(c2.x(), c2.y(), c3.x(), c3.y(),color.r,color.g,color.b);
    window.drawLine(c3.x(), c3.y(),c0.x(), c0.y(),color.r,color.g,color.b);


 }
