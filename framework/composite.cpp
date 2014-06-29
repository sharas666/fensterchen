#include "composite.hpp"

Composite::Composite():
	Shape{},
	m_vec_{}
	{}

Composite::Composite(std::string const& name):
	Shape{name},
	m_vec_{}
	{}

void Composite::add_shape(std::shared_ptr<Shape> const new_shape_pointer){
	m_vec_.push_back(new_shape_pointer);	
}

void Composite::remove_shape(std::string const& name){
	m_vec_.erase(std::remove_if(m_vec_.begin(),m_vec_.end(),[&name](std::shared_ptr<Shape> const& it)->bool{return (name==it->get_name());})),m_vec_.end();
}

bool Composite::is_inside(Point2d const& p) const{
	for (auto i : m_vec_){
		if (i->is_inside(p)){
			return true;
		}
	}return false;
}

void Composite::draw(Window const& w) const{
	for (auto i : m_vec_){
		i->draw(w);
	}
}

void Composite::draw(Window const& w, ColorRGB color) const{
	for (auto i : m_vec_){
		i->draw(w, color);
	}
}

bool Composite::is_leave() const{
	return false;
}