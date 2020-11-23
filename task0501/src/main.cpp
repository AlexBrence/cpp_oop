#include "View.h" 
#include "Position.h"
#include "Size.h"
#include "Layout.h" 
#include "TextView.h"

#include <iostream>
#include <memory>


int main() {
    std::cout << "***** Position *****\n";
    Position position1(10.0f, 15.0f);
    std::cout << position1.to_string();
    position1.set_x(11.0f);
    position1.set_y(17.0f);
    std::cout << "\n= After setting =\nget_x: " << position1.get_x() << "\nget_y: " << position1.get_y() << std::endl;

    std::cout << "\n***** Size *****\n";
    Size size1(5.0f, 10.0f, "mm");
    std::cout << size1.to_string();
    size1.set_width(10.0f);
    size1.set_height(15.0f);
    size1.set_unit("cm");
    std::cout << "\nget_width: " << size1.get_width()
              << "\nget_height: " << size1.get_height()
              << "\nget_unit: " << size1.get_unit() << std::endl;



    std::cout << "\n***** View *****\n";
    auto view1 = std::make_unique<View>(position1, size1);
    view1->draw();
    view1->set_visible(false);
    view1->draw();

    view1->set_position(20.0f, 25.0f);
    view1->set_size(15.0f, 20.0f, "mm");

    Position tmp_pos = view1->get_position();
    Size tmp_size = view1->get_size();
    std::cout << tmp_pos.to_string() << std::endl << tmp_size.to_string() << std::endl;
    std::cout << "Visible: " << view1->is_visible() << std::endl;
    view1->set_visible(true);
    std::cout << "Change visible to true\n";
    view1->draw();


    

    std::cout << "\n***** TextView *****\n";
    auto tw1 = std::make_unique<TextView>(position1, size1, "This is some random text");
    tw1->draw();
    tw1->set_text("Some other random text");
    tw1->set_position(25.0f, 30.0f);
    tw1->draw();

    
    std::cout << "\n***** Layout *****\n";
    Layout layout1;
    layout1.add_view(std::make_unique<View>(*view1));
    layout1.add_view(std::make_unique<View>(*tw1));
    layout1.draw();
    std::cout << "Views size: " << layout1.size();
    tw1->set_capitalize(true);
    std::cout << "\n\n= Setting capitalize: true =\n";
    layout1.draw();

    
    
    return 0;
}
