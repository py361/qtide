
#include "isidraw.h"
#include "isigraph2.h"
#include "form.h"
#include "pane.h"

// ---------------------------------------------------------------------
Isidraw::Isidraw(string n, string s, Form *f, Pane *p) : Child(n,s,f,p)
{
  type = "isidraw";
  Isigraph2 *w= new Isigraph2(this, p);
  widget=(QWidget *) w;
  w->type=type;
  QString qn=s2q(n);
  w->setObjectName(qn);
  isigraph = this;
}

// ---------------------------------------------------------------------
void Isidraw::setform()
{
  if (!widget) return;
  if (!(event=="paint" || event=="print")) form=pform;
  isigraph=(Child *)this;
}