
#include <QProgressBar>

#include "wd.h"
#include "progressbar.h"
#include "form.h"
#include "pane.h"
#include "cmd.h"

// ---------------------------------------------------------------------
ProgressBar::ProgressBar(string n, string s, Form *f, Pane *p) : Child(n,s,f,p)
{
  type="progressbar";
  QProgressBar *w=new QProgressBar;
  widget=(QWidget*) w;
  QString qn=s2q(n);
  QStringList opt=qsplit(s);
  QStringList unopt=qsless(qsless(opt,qsplit("")),defChildStyle);
  if (unopt.size() && !qsnumeric(unopt)) {
    error("unrecognized child style: " + q2s(unopt.join(" ")));
    return;
  }
  w->setObjectName(qn);
  childStyle(opt);

  int i=0;
  if ((i<opt.size()) && (opt.at(i)=="v")) {
    i++;
    w->setOrientation(Qt::Vertical);
  }
  if (i<opt.size()) {
    w->setMinimum(c_strtoi(q2s(opt.at(i))));
    i++;
  }
  if (i<opt.size()) {
    w->setMaximum(c_strtoi(q2s(opt.at(i))));
    i++;
  }
  if (i<opt.size()) {
    w->setValue(c_strtoi(q2s(opt.at(i))));
    i++;
  }
}

// ---------------------------------------------------------------------
void ProgressBar::set(string p,string v)
{
  QProgressBar *w=(QProgressBar*) widget;
  QString cmd=s2q(p);
  QStringList arg=qsplit(v);
  if (arg.isEmpty()) {
    Child::set(p,v);
    return;
  }
  if (cmd=="min")
    w->setMinimum(c_strtoi(q2s(arg.at(0))));
  else if (cmd=="max")
    w->setMaximum(c_strtoi(q2s(arg.at(0))));
  else if (cmd=="pos" || cmd=="value")
    w->setValue(c_strtoi((v)));
  else Child::set(p,v);
}

