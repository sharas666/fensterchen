#include "composite.hpp"

Composite::Composite():
	Shape{},
	m_vec_{}
	{}

void Composite::add_shape(std::shared_ptr<Shape> const new_shape_pointer){
	m_vec_.push_back(new_shape_pointer);	
}

// void Composite::remove_shape(std::string const& name){
// 	std::remove_if(m_vec_.begin(),m_vec_.end(),[&name](std::shared_ptr<Shape> const& it)->bool{return (name==it->m_name_);});
// }

bool Composite::is_inside(Point2d const& p) const{
	for (auto i : m_vec_){
		if (i->is_inside(p)){
			return true;
		}
	}return false;
}

void Composite::draw(Window const& c) const{
	for (auto i : m_vec_){
		i->draw(c);
	}
}