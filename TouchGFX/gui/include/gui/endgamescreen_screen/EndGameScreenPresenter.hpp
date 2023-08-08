#ifndef ENDGAMESCREENPRESENTER_HPP
#define ENDGAMESCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class EndGameScreenView;

class EndGameScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    EndGameScreenPresenter(EndGameScreenView& v);

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

    virtual ~EndGameScreenPresenter() {}

    int32_t getWinner() {
		return model->getWinner();
	}

    void Init()
    {
    	model->Init();
    }

private:
    EndGameScreenPresenter();

    EndGameScreenView& view;
};

#endif // ENDGAMESCREENPRESENTER_HPP
