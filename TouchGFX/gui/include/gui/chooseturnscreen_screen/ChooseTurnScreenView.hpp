#ifndef CHOOSETURNSCREENVIEW_HPP
#define CHOOSETURNSCREENVIEW_HPP

#include <gui_generated/chooseturnscreen_screen/ChooseTurnScreenViewBase.hpp>
#include <gui/chooseturnscreen_screen/ChooseTurnScreenPresenter.hpp>

class ChooseTurnScreenView : public ChooseTurnScreenViewBase
{
public:
    ChooseTurnScreenView();
    virtual ~ChooseTurnScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void btnFirstClicked();
    void btnSecondClicked();
protected:
};

#endif // CHOOSETURNSCREENVIEW_HPP
