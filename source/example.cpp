#include "fensterchen.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite.hpp"






int main(int argc, char* argv[])
{

  ColorRGB red(255,0,0);
  Point2d p(0,0);
  std::shared_ptr<Circle> s1 = std::make_shared<Circle>(1.2,p, red, "sphere0");
  std::shared_ptr<Shape> s2 = std::make_shared<Circle>(1.2,p, red, "sphere1");
  s1->print(std::cout);
  s2->print(std::cout);

  Window win(glm::ivec2(800,800));
  Composite comp1{};
  Circle c1{0.08,{0.3,0.2},"Rad1"};
  Circle c2{0.08,{0.7,0.2},"Rad2"};
  Rectangle r1{{0.2,0.2},0.6,0.13,{0,0,0},"Mitte"};
  Rectangle r2{{0.3,0.33},0.4,0.15,{0,0,0},"Kabine"};

  std::shared_ptr<Circle> kreis1 = std::make_shared<Circle>(c1);
  std::shared_ptr<Circle> kreis2 = std::make_shared<Circle>(c2);
  std::shared_ptr<Rectangle> rect1 = std::make_shared<Rectangle>(r1);
  std::shared_ptr<Rectangle> rect2 = std::make_shared<Rectangle>(r2);
  std::shared_ptr<Composite> compptr = std::make_shared<Composite>(comp1);

  comp1.add_shape(kreis1);
  comp1.add_shape(kreis2);
  comp1.add_shape(rect1);
  comp1.add_shape(rect2);


  while (!win.shouldClose()) {
    if (win.isKeyPressed(GLFW_KEY_ESCAPE)) {
      win.stop();
    }
  
    auto m = win.mousePosition();
    Point2d mouse{m.x,m.y};
    comp1.inside_draw(win, mouse);


    win.update();
  }

  return 0;
}
