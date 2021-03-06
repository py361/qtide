#ifndef ISIGRAPH_H
#define ISIGRAPH_H

#include <string>

#include "child.h"

class Form;
class Pane;

class Isigraph : public Child
{
  Q_OBJECT

public:
  Isigraph(string n, string s, Form *f, Pane *p);
  void setform();
  string get(string p,string v);
  void set(string p,string v);
  string state();
};

#endif

