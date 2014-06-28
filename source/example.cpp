#include "fensterchen.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite.hpp"

int main(int argc, char* argv[])
{
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

  comp1.add_shape(kreis1);
  comp1.add_shape(kreis2);
  comp1.add_shape(rect1);
  comp1.add_shape(rect2);

  while (!win.shouldClose()) {
    if (win.isKeyPressed(GLFW_KEY_ESCAPE)) {
      win.stop();
    }
    comp1.draw(win);
    // auto t = win.getTime();
    // float x1(0.5 + 0.5 * std::sin(t)); float y1(0.5 + 0.5 * std::cos(t));
    // float x2(0.5 + 0.5 * std::sin(2.0*t)); float y2(0.5 + 0.5 * std::cos(2.0*t));
    // float x3(0.5 + 0.5 * std::sin(t-10.f)); float y3(0.5 + 0.5 * std::cos(t-10.f));

    // win.drawPoint(x1, y1, 255, 0, 0);
    // win.drawPoint(x2, y2, 0, 255, 0);
    // win.drawPoint(x3, y3, 0, 0, 255);

    auto m = win.mousePosition();
    // win.drawLine(0.1f,0.1f, 0.8f,0.1f, 255,0,0);

    // win.drawLine(0.0f, m.y, 0.01f, m.y, 0,0,0);
    // win.drawLine(0.99f, m.y,1.0f, m.y, 0,0,0);

    // win.drawLine(m.x, 0.0f, m.x, 0.01f, 0,0,0);
    // win.drawLine(m.x, 0.99f,m.x, 1.0f, 0,0,0);

    win.update();
  }

  return 0;
}
