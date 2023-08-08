#ifndef GAMESCREENPRESENTER_HPP
#define GAMESCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class GameScreenView;

class GameScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    GameScreenPresenter(GameScreenView& v);

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

    virtual ~GameScreenPresenter() {}

	void getDesk(int32_t (*arr)[10]) {
		int32_t data[10][10];
		model->getPlayer1Desk(data);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				arr[i][j] = data[i][j];
			}
		}
	}
    void setDesk(int32_t i, int32_t j, int32_t status)
    {
        model->setPlayer1Desk(i, j, status);
    }
	void setHits(std::pair<int32_t, int32_t> bot[100]) {
		model->setHits(bot);
	}
	void getHits(std::pair<int32_t, int32_t>* bot) {
		std::pair<int32_t, int32_t> t[100];
		model->getHits(t);
		for (int32_t i = 0; i < 100; i++) {
			bot[i] = t[i];
		}
	}
	void setIndexHit(int32_t index){
		model->setIndexHit(index);
	}
	int32_t getIndexHit(){
		return model->getIndexHit();
	}
    void setFire(int x, int y){
    	model->setFire(x, y);
    }
    std::pair<int, int> getFire(){
    	return model->getFire();
    }

private:
    GameScreenPresenter();

    GameScreenView& view;
};

#endif // GAMESCREENPRESENTER_HPP
