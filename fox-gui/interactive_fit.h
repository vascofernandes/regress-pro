/* -*- mode: C++; -*- */

#ifndef INTERATIVE_FIT_H
#define INTERATIVE_FIT_H

#include <fx.h>

#include <gsl/gsl_vector.h>

#include "agg2/agg_array.h"

#include "elliss_app.h"
#include "spectra.h"
#include "fit-params.h"
#include "fx_plot.h"

class interactive_fit : public FXMainWindow {
  FXDECLARE(interactive_fit)

  struct param_info {
    FXTextField *text_field;
    fit_param_t fp;
    double value;
    bool selected;
  };

private:

  struct fit_engine* fit_engine;

  fx_plot_vector<2> m_plot;

  struct fit_parameters *m_fit_parameters;

  agg::pod_array<param_info> m_parameters;

  struct spectrum *spectrum;

  bool m_canvas_is_dirty;

protected:
  FXMenuBar         *menubar;
  FXStatusBar       *statusbar;
  FXMenuPane        *fitmenu;

  FXCanvas *canvas;

  void updatePlot(bool freeze_limits = false);
  void drawPlot();

protected:
  interactive_fit(){};
private:
  interactive_fit(const interactive_fit&);
  interactive_fit &operator=(const interactive_fit&);

public:
  interactive_fit(elliss_app *app, struct fit_engine *fit, struct spectrum *sp);
  virtual ~interactive_fit();

  long onCmdParamSelect(FXObject*, FXSelector,void*);
  long onCmdParamChange(FXObject*, FXSelector,void*);
  long onCmdRunFit(FXObject*, FXSelector,void*);
  long onCmdPaint(FXObject*, FXSelector,void*);
  long onUpdCanvas(FXObject*, FXSelector,void*);

  enum {
    ID_PARAM_SELECT = FXMainWindow::ID_LAST,
    ID_PARAM_VALUE,
    ID_RUN_FIT,
    ID_CANVAS,
    ID_LAST
  };
};

#endif