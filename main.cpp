#include "Services/GenerateService.h"
#include "Tasks/Orchestrator.h"
#include "Utility/Logger.h"
#include "Utility/Parser.h"
#include <iostream>

int main(int argc, char **argv) {

  Logger::createInstance(std::cout, Verbosity::Debug);

  Orchestrator &orchestrator = Orchestrator::createInstance();

  Parser cliParser;
  cliParser.addService<GenerateService>("generate");
  cliParser.parse(argc, argv);
  cliParser.run();

}
