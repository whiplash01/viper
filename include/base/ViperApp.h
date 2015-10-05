#ifndef VIPERAPP_H
#define VIPERAPP_H

#include "MooseApp.h"

class ViperApp;

template<>
InputParameters validParams<ViperApp>();

class ViperApp : public MooseApp
{
public:
  ViperApp(InputParameters parameters);
  virtual ~ViperApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* VIPERAPP_H */
