#include "ViperApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<ViperApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

ViperApp::ViperApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  ViperApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  ViperApp::associateSyntax(_syntax, _action_factory);
}

ViperApp::~ViperApp()
{
}

// External entry point for dynamic application loading
extern "C" void ViperApp__registerApps() { ViperApp::registerApps(); }
void
ViperApp::registerApps()
{
  registerApp(ViperApp);
}

// External entry point for dynamic object registration
extern "C" void ViperApp__registerObjects(Factory & factory) { ViperApp::registerObjects(factory); }
void
ViperApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void ViperApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { ViperApp::associateSyntax(syntax, action_factory); }
void
ViperApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
