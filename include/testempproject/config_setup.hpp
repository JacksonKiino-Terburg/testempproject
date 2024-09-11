#pragma once

#include <filesystem>

#include "emp/config/ArgManager.hpp"
#include "emp/prefab/ConfigPanel.hpp"
#include "emp/web/UrlParams.hpp"
#include "emp/web/web.hpp"

#include "testempproject/ExampleConfig.hpp"

void use_existing_config_file(testempproject::Config & config, emp::ArgManager & am) {
  if(std::filesystem::exists("testempproject.cfg")) {
    std::cout << "Configuration read from testempproject.cfg" << "\n";
    config.Read("testempproject.cfg");
  }
  am.UseCallbacks();
  if (am.HasUnused())
    std::exit(EXIT_FAILURE);
}

void setup_config_web(testempproject::Config & config)  {
  auto specs = emp::ArgManager::make_builtin_specs(&config);
  emp::ArgManager am(emp::web::GetUrlParams(), specs);
  use_existing_config_file(config, am);
}

void setup_config_native(testempproject::Config & config, int argc, char* argv[]) {
  auto specs = emp::ArgManager::make_builtin_specs(&config);
  emp::ArgManager am(argc, argv, specs);
  use_existing_config_file(config, am);
}

