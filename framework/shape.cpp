#include "shape.hpp"


Shape::Shape():
	m_name_{"standart_consrtructed_shape"},
	m_color_{0,0,0}
{}

Shape::Shape(std::string const& name, ColorRGB c):
	m_name_{name},
	m_color_{c}
{}

Shape::Shape(std::string const& name):
	m_name_{name},
	m_color_{0,0,0}
{}

Shape::~Shape(){
	std::cout << "Shape " << m_name_ << " zerstört." << std::endl;
}

std::string Shape::get_name() const{
	return m_name_;
}



std::ostream& Shape::print(std::ostream& os) const{
	std::cout << "Name: " << m_name_ << std::endl;
	std::cout << "Farbe: r = " << m_color_.r << "g = " << m_color_.g << "b = " << m_color_.b << std::endl;
}

std::ostream& operator<<(std::ostream& os,Shape const& s)
{
	s.print(os);
	return os;
}