//  This file is part of TestEmpProject
//  Copyright (C) Jackson Kiino-Terburg, 2024.
//  Released under MIT license; see LICENSE

#include <iostream>

#include "emp/base/vector.hpp"

#include "testempproject/config_setup.hpp"
#include "testempproject/example.hpp"
#include "testempproject/ExampleConfig.hpp"

// This is the main function for the NATIVE version of TestEmpProject.

testempproject::Config cfg;

int main(int argc, char* argv[])
{ 
  // Set up a configuration panel for native application
  setup_config_native(cfg, argc, argv);
  cfg.Write(std::cout);

  std::cout << "Hello, world!" << "\n";

  return example();
}
