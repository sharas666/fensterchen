
#include "circle.hpp"
#include "rectangle.hpp"

 
void Circle::draw(Window const& window) const /*override*/{
    Point2d start_point{m_mid_.x() + m_radius_, m_mid_.y()};
    Point2d end_point{start_point};
  
       

    for (int j = 1; j<201; ++j){
        double bow = 0.01;
        end_point.rotate(m_mid_, bow*M_PI);
        window.drawLine(start_point.x(), start_point.y(), end_point.x(), end_point.y(),m_color_.r,m_color_.g,m_color_.b);
        start_point.rotate(m_mid_, bow*M_PI);
    }

 
}
void Circle::draw(Window const& window, ColorRGB color) const /*override*/{
    Point2d start_point{m_mid_.x() + m_radius_, m_mid_.y()};
    Point2d end_point{start_point};
  
       

    for (int j = 1; j<201; ++j){
        double bow = 0.01;
        end_point.rotate(m_mid_, bow*M_PI);
        window.drawLine(start_point.x(), start_point.y(), end_point.x(), end_point.y(),color.r,color.g,color.b);
        start_point.rotate(m_mid_, bow*M_PI);
    }
}

 void Rectangle::draw(Window const& window) const /*override*/{
    Point2d c0{m_left_bottom_corner_.x(), m_left_bottom_corner_.y()};
    Point2d c1{m_left_bottom_corner_.x() + m_sidelength_a, m_left_bottom_corner_.y()};
    Point2d c2{c1.x(), c1.y() + m_sidelength_b};
    Point2d c3{m_left_bottom_corner_.x(), m_left_bottom_corner_.y() + m_sidelength_b};
    c0.rotate(m_left_bottom_corner_,m_angle_);
    c1.rotate(m_left_bottom_corner_,m_angle_);
    c2.rotate(m_left_bottom_corner_,m_angle_);
    c3.rotate(m_left_bottom_corner_,m_angle_);
    

    window.drawLine(c0.x(), c0.y(), c1.x(), c1.y(),m_color_.r,m_color_.g,m_color_.b);
    window.drawLine(c1.x(), c1.y(), c2.x(), c2.y(),m_color_.r,m_color_.g,m_color_.b);
    window.drawLine(c2.x(), c2.y(), c3.x(), c3.y(),m_color_.r,m_color_.g,m_color_.b);
    window.drawLine(c3.x(), c3.y(),c0.x(), c0.y(),m_color_.r,m_color_.g,m_color_.b);


 }

  void Rectangle::draw(Window const& window, ColorRGB color) const /*override*/{
    Point2d c0{m_left_bottom_corner_.x(), m_left_bottom_corner_.y()};
    Point2d c1{m_left_bottom_corner_.x() + m_sidelength_a, m_left_bottom_corner_.y()};
    Point2d c2{c1.x(), c1.y() + m_sidelength_b};
    Point2d c3{m_left_bottom_corner_.x(), m_left_bottom_corner_.y() + m_sidelength_b};
    c0.rotate(m_left_bottom_corner_,m_angle_);
    c1.rotate(m_left_bottom_corner_,m_angle_);
    c2.rotate(m_left_bottom_corner_,m_angle_);
    c3.rotate(m_left_bottom_corner_,m_angle_);
    

    window.drawLine(c0.x(), c0.y(), c1.x(), c1.y(),color.r,color.g,color.b);
    window.drawLine(c1.x(), c1.y(), c2.x(), c2.y(),color.r,m_color.g,color.b);
    window.drawLine(c2.x(), c2.y(), c3.x(), c3.y(),color.r,color.g,color.b);
    window.drawLine(c3.x(), c3.y(),c0.x(), c0.y(),color.r,color.g,color.b);


 }
