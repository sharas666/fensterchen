#ifndef COMPOSITE_HPP
#define COMPOSITEE_HPP
#include "shape.hpp"



class Composite : public Shape{

	public:

		Composite();
		Composite(std::string const& name);
		void add_shape(std::shared_ptr<Shape> const new_shape_pointer);
		void remove_shape(std::string const& name);
		bool is_inside(Point2d const& p) const;
		void draw(Window const& w) const;
		void draw(Window const& w, ColorRGB color) const;
		bool is_leave() const;
		void inside_draw(Window const& w, Point2d b)const;

	private:
		std::vector<std::shared_ptr<Shape>> m_vec_;
};



#endif