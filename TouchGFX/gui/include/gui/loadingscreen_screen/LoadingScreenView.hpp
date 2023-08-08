#ifndef LOADINGSCREENVIEW_HPP
#define LOADINGSCREENVIEW_HPP

#include <gui_generated/loadingscreen_screen/LoadingScreenViewBase.hpp>
#include <gui/loadingscreen_screen/LoadingScreenPresenter.hpp>

class LoadingScreenView : public LoadingScreenViewBase
{
public:
    LoadingScreenView();
    virtual ~LoadingScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void handleTickEvent();
protected:
    bool increase = true;
};

#endif // LOADINGSCREENVIEW_HPP
