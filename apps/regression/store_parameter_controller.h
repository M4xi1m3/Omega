#ifndef REGRESSION_STORE_PARAMETER_CONTROLLER_H
#define REGRESSION_STORE_PARAMETER_CONTROLLER_H

#include "../shared/store_parameter_controller.h"

namespace Regression {

class StoreController;

class StoreParameterController : public Shared::StoreParameterController {
public:
  StoreParameterController(Responder * parentResponder, Shared::DoublePairStore * store, StoreController * storeController);
  bool handleEvent(Ion::Events::Event event) override;
  int numberOfRows() override { return Shared::StoreParameterController::numberOfRows() + 1; }
  HighlightCell * reusableCell(int index) override;
  int reusableCellCount() override { return Shared::StoreParameterController::reusableCellCount() + 1; }
private:
  MessageTableCell m_changeRegression;
};

}

#endif
