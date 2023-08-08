#ifndef CHOOSETURNSCREENPRESENTER_HPP
#define CHOOSETURNSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ChooseTurnScreenView;

class ChooseTurnScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ChooseTurnScreenPresenter(ChooseTurnScreenView& v);

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

    virtual ~ChooseTurnScreenPresenter() {}

    void setIsGoFirst(bool b) {
		model->setIsGoFirst(b);
	}

private:
    ChooseTurnScreenPresenter();

    ChooseTurnScreenView& view;
};

#endif // CHOOSETURNSCREENPRESENTER_HPP
