//  This file is part of TestEmpProject
//  Copyright (C) Jackson Kiino-Terburg, 2024.
//  Released under MIT license; see LICENSE

#include <iostream>

#include "emp/prefab/ConfigPanel.hpp"
#include "emp/web/TextArea.hpp"
#include "emp/web/web.hpp"

#include "testempproject/config_setup.hpp"
#include "testempproject/example.hpp"
#include "testempproject/ExampleConfig.hpp"

namespace UI = emp::web;

UI::Document doc("emp_base");

testempproject::Config cfg;

int main()
{
  doc << "<h1>Hello, browser!</h1>";

  // Set up a configuration panel for web application
  setup_config_web(cfg);
  cfg.Write(std::cout);
  emp::prefab::ConfigPanel example_config_panel(cfg);
  example_config_panel.ExcludeSetting("SUPER_SECRET");
  example_config_panel.SetRange("SEED", "-1", "100", "1");
  doc << example_config_panel;

  // An example to show how the Config Panel could be used
  // to control the color of text in an HTML text area
  UI::TextArea example_area("example_area");
  example_area.SetSize(cfg.SIZE(), cfg.SIZE());
  example_config_panel.SetOnChangeFun([](const std::string & setting, const std::string & value){
    UI::TextArea example_area = doc.TextArea("example_area");
    example_area.SetCSS("color", cfg.COLOR());
    example_area.Redraw();
  });

  doc << example_area;

  std::cout << "Hello, console!" << "\n";

  return example();
}
