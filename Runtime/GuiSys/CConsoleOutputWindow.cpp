#include "Runtime/GuiSys/CConsoleOutputWindow.hpp"
#include "Runtime/Graphics/CGraphics.hpp"

namespace urde {

CConsoleOutputWindow::CConsoleOutputWindow(int, float, float) : CIOWin("Console Output Window") {}

CIOWin::EMessageReturn CConsoleOutputWindow::OnMessage(const CArchitectureMessage&, CArchitectureQueue&) {
  return EMessageReturn::Normal;
}

void CConsoleOutputWindow::Draw() const {
  //SCOPED_GRAPHICS_DEBUG_GROUP("CConsoleOutputWindow::Draw", zeus::skGreen);
}

} // namespace urde
