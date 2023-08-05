#ifndef OPPONENTSCREENPRESENTER_HPP
#define OPPONENTSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class OpponentScreenView;

class OpponentScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    OpponentScreenPresenter(OpponentScreenView& v);

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

    virtual ~OpponentScreenPresenter() {}

    void setDesk(int32_t i, int32_t j, int32_t status)
        {
            model->setDesk(i, j, status);
        }
    std::vector<std::vector<int8_t>> getDesk()
        {
            return model->getDesk();
        }

private:
    OpponentScreenPresenter();

    OpponentScreenView& view;
};

#endif // OPPONENTSCREENPRESENTER_HPP
