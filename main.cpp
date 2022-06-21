#include "Services/DecodeService.h"
#include "Services/EncodeService.h"
#include "Services/GenerateService.h"
#include "Tasks/Orchestrator.h"
#include "Utility/Logger.h"
#include "Utility/Parser.h"
#include <iostream>

int main(int argc, char **argv) {

  Logger::createInstance(std::cout, Verbosity::Info);

  Orchestrator &orchestrator = Orchestrator::createInstance();

  Parser cliParser;

  cliParser.addService<GenerateService>("generate");
  cliParser.addService<EncodeService>("encode");
  cliParser.addService<DecodeService>("decode");

  cliParser.parse(argc, argv);
  cliParser.run();
}
