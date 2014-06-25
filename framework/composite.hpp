#ifndef COMPOSITE_HPP
#define COMPOSITEE_HPP
#include "shape.hpp"


class Composite : public Shape{

	public:

		Composite();
		void add_shape(std::shared_ptr<Shape> const new_shape_pointer);
		void remove_shape(std::string const& name);
		bool is_inside(Point2d const& p) const;
		void draw(Window const& c) const;

	private:
		std::vector<std::shared_ptr<Shape>> m_vec_;
};



#endif