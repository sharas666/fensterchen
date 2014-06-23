#include "shape.hpp"

Shape::Shape(std::string name, ColorRGB c):
	m_name_{name},
	m_color_{c}
{}

virtual std::ostream& Shape::print(std::ostream& os) const{
	
}