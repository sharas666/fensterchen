#include "rectangle.hpp"

Rectangle::Rectangle():
	Shape{"standard_constructed_rectangle",{0,0,0}},
	m_left_bottom_corner_{0,0},
	m_angle_{0},
	m_sidelength_a{1},
	m_sidelength_b{1}

{};

Rectangle::Rectangle(Point2d const& m_left_bottom_corner, double const& angle, double const& side_a, double const& side_b, ColorRGB const& c, std::string name):
	Shape{name, c},
	m_left_bottom_corner_{m_left_bottom_corner},
	m_angle_{angle},
	m_sidelength_a{side_a},
	m_sidelength_b{side_b}
	
{};

Rectangle::Rectangle(Point2d const& m_left_bottom_corner, double const& side_a, double const& side_b, ColorRGB const& c, std::string name):
	Shape{name,c},
	m_left_bottom_corner_{m_left_bottom_corner},
	m_angle_{0},
	m_sidelength_a{side_a},
	m_sidelength_b{side_b}
	
{};

Rectangle::~Rectangle(){};

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