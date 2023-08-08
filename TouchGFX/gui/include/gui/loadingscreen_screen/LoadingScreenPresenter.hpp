#ifndef LOADINGSCREENPRESENTER_HPP
#define LOADINGSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class LoadingScreenView;

class LoadingScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    LoadingScreenPresenter(LoadingScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~LoadingScreenPresenter() {}

private:
    LoadingScreenPresenter();

    LoadingScreenView& view;
};

#endif // LOADINGSCREENPRESENTER_HPP
