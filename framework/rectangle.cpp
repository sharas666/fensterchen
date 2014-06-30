#include "rectangle.hpp"

Rectangle::Rectangle():
	Shape{"standard_constructed_rectangle",{0,0,0}},
	m_left_bottom_corner_{0,0},
	m_angle_{0},
	m_sidelength_a{1},
	m_sidelength_b{1}

{
	std::cout << "Rechteck " << m_name_ << " konstruiert." << std::endl;
}

Rectangle::Rectangle(Point2d const& m_left_bottom_corner, double const& angle, double const& side_a,
						double const& side_b, ColorRGB const& c, std::string const& name):
	Shape{name, c},
	m_left_bottom_corner_{m_left_bottom_corner},
	m_angle_{angle},
	m_sidelength_a{side_a},
	m_sidelength_b{side_b}
	
{
	std::cout << "Rechteck " << m_name_ << " konstruiert." << std::endl;
}

Rectangle::Rectangle(Point2d const& m_left_bottom_corner, double const& side_a,
						double const& side_b, ColorRGB const& c, std::string const& name):
	Shape{name,c},
	m_left_bottom_corner_{m_left_bottom_corner},
	m_angle_{0},
	m_sidelength_a{side_a},
	m_sidelength_b{side_b}
	
{
	std::cout << "Rechteck " << m_name_ << " konstruiert." << std::endl;
}

Rectangle::~Rectangle(){
	std::cout << "Rechteck " << m_name_ << " zerstört." << std::endl;
}

double Rectangle::a()const{
	return m_sidelength_a;
}

double Rectangle::b()const{
	return m_sidelength_b;
}

ColorRGB Rectangle::c()const{
	return m_color_;
}

Point2d Rectangle::corner()const{
	return m_left_bottom_corner_;
}

double Rectangle::angle()const{
	return m_angle_;
}

ColorRGB Rectangle::color()const{
	return m_color_;
}


bool Rectangle::is_inside(Point2d const& p)const /*override*/{
	if( (p.x()>=m_left_bottom_corner_.x())&&
		(p.y()>=m_left_bottom_corner_.y())&&
		(p.x()<=m_left_bottom_corner_.x()+m_sidelength_a)&&
		(p.y()<=m_left_bottom_corner_.y()+m_sidelength_b) ){
		return true;
	}else{
		return false;
	}
	
}

double Rectangle::circumference()const{
	return 2*(m_sidelength_a + m_sidelength_b);

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
    window.drawLine(c1.x(), c1.y(), c2.x(), c2.y(),color.r,color.g,color.b);
    window.drawLine(c2.x(), c2.y(), c3.x(), c3.y(),color.r,color.g,color.b);
    window.drawLine(c3.x(), c3.y(),c0.x(), c0.y(),color.r,color.g,color.b);


 }

std::ostream& Rectangle::print(std::ostream& os) const{
	Shape::print(os);
	std::cout << "Eckpunkt rechts unten: x = " << m_left_bottom_corner_.x() << ", y = " << m_left_bottom_corner_.y() << std::endl;
	std::cout << "Seitenlänge a: " << m_sidelength_a;
	std::cout << "Seitenlänge b: " << m_sidelength_b;
	std::cout << "Winkel: " << m_angle_ << std::endl;


	return os;
}

bool Rectangle::is_leave() const{
	return true;
}